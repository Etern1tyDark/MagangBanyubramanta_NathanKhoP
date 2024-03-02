// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/string.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "obj_msg/msg/found.hpp"
#include "openvino/openvino.hpp"

using namespace cv;
using namespace std;
using namespace std::chrono_literals;
using std::placeholders::_1;

struct Detection
{
	int cls;
	float x, y, w, h, conf;
};

#define INPUT_WIDTH 640
#define INPUT_HEIGHT 640

class YoloNode : public rclcpp::Node
{
public:
  YoloNode() : Node("yolonode")
  {
    publisher_ = this->create_publisher<obj_msg::msg::Found>("detected_obj", 10);
    subscriber_ = this->create_subscription<sensor_msgs::msg::Image>("cam_src", 10, std::bind(&YoloNode::topic_callback, this, _1));

    ov::Core core;
    std::shared_ptr<ov::Model> model = core.read_model("src/yolocpp/models/gateflare.onnx");
    ov::preprocess::PrePostProcessor ppp = ov::preprocess::PrePostProcessor(model);
    ppp.input().tensor().set_element_type(ov::element::u8).set_layout("NHWC").set_color_format(ov::preprocess::ColorFormat::RGB);
    ppp.input().preprocess().convert_element_type(ov::element::f32).convert_color(ov::preprocess::ColorFormat::RGB).scale({ 255, 255, 255 });// .scale({ 112, 112, 112 });
    ppp.input().model().set_layout("NCHW");
    ppp.output().tensor().set_element_type(ov::element::f32);
    model = ppp.build();
    this->compiled_model = core.compile_model(model, "CPU");
    this->infer_request = compiled_model.create_infer_request();

    cv::namedWindow("values");
		cv::createTrackbar("score", "values", &score_lim, 100);
		cv::createTrackbar("conf", "values", &conf_lim, 100);
		cv::createTrackbar("nms", "values", &nms_lim, 100);
  }

  ~YoloNode() {
    destroyAllWindows();
  }

private:
  void preprocessing(Mat &frame) {

    float width = frame.cols;
    float height = frame.rows;

    x_fact = width / float(INPUT_WIDTH);
		y_fact = height / float(INPUT_HEIGHT);

		cv::resize(frame, frame, cv::Size(INPUT_WIDTH, INPUT_HEIGHT));

    float* input_data = (float*)frame.data;
    input_tensor = ov::Tensor(compiled_model.input().get_element_type(), compiled_model.input().get_shape(), input_data);
    infer_request.set_input_tensor(input_tensor);

  }

  void postprocessing(Mat &frame) {
    
    infer_request.infer();
    const ov::Tensor& output_tensor = infer_request.get_output_tensor();
    ov::Shape output_shape = output_tensor.get_shape();
    float* data = output_tensor.data<float>();

    vector<cv::Rect> boxes;
    // vector<int> class_ids;
    vector<float> confidences;
    vector<Detection> detections;

    for (long unsigned int i = 0; i < output_shape[1]; i++) {

        float *detection = &data[i * output_shape[2]];
        float confidence = detection[4];

        if (confidence > conf_lim / 100.) {
          
            float* classes_scores = detection + 5;
            cv::Mat scores(1, output_shape[2] - 5, CV_32FC1, classes_scores);
            cv::Point class_id;
            double max_class_score;
            cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

            if (max_class_score > score_lim / 100.) {

              Detection d;
              d.cls = class_id.x;
              d.conf = confidence;
              d.x = detection[0] * x_fact,
              d.y = detection[1] * y_fact,
              d.w = detection[2] * x_fact,
              d.h = detection[3] * y_fact;

              detections.push_back(d);
              confidences.push_back(confidence);
              boxes.push_back(cv::Rect(d.x - (d.w / 2.), d.y - (d.h / 2.), d.w, d.h));

            }
        }
    }

    std::vector<int> nms_result;
    cv::dnn::NMSBoxes(boxes, confidences, score_lim / 100., nms_lim / 100., nms_result);
    RCLCPP_INFO(this->get_logger(), "Detected %ld objects", nms_result.size());

    for (long unsigned int i = 0; i < nms_result.size(); i++)
    {
        int idx = nms_result[i];
        auto message = obj_msg::msg::Found();

        message.x = detections[idx].x;
        message.y = detections[idx].y;
        message.w = detections[idx].w;
        message.h = detections[idx].h;

        publisher_->publish(message);

      std::string label = class_names[detections[idx].cls];
      cv::Point2i top_left = boxes[idx].tl();
      int base_line;
      cv::Size label_size = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &base_line);

      cv::rectangle(frame, boxes[idx], cv::Scalar(0, 0, 255));
      cv::rectangle(frame, top_left, cv::Point(label_size.width, top_left.y + base_line), cv::Scalar(0, 0, 255), -1);
      cv::putText(frame, label, top_left, cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255));
      cv::resize(frame, frame, cv::Size(0, 0), x_fact, y_fact);
    }
  }

    void topic_callback(const sensor_msgs::msg::Image &sensor_img) {
      cv_bridge::CvImagePtr cv_img = cv_bridge::toCvCopy(sensor_img);
      cv::Mat frame = cv_img->image;

      if (frame.empty())
      {
        RCLCPP_ERROR(this->get_logger(), "Failed to read frame");
        return;
      }

      preprocessing(frame);
      postprocessing(frame);

      cv::imshow("frame", frame);
      cv::waitKey(1);
	}

	rclcpp::Publisher<obj_msg::msg::Found>::SharedPtr publisher_;
	rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
	ov::CompiledModel compiled_model;
	ov::InferRequest infer_request;
	ov::Tensor input_tensor;
	
  int score_lim = 20, conf_lim = 40, nms_lim = 40;
	float x_fact, y_fact;
	const std::vector<std::string> class_names = {"gate"};
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<YoloNode>());
  rclcpp::shutdown();
  return 0;
}