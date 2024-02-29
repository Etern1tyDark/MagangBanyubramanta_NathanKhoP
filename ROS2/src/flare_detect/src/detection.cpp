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

#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "obj_msg/msg/detected.hpp"

using std::placeholders::_1;
using namespace std;
using namespace cv;

class Detection : public rclcpp::Node
{
public:
  Detection() : Node("detection")
  { 
    publisher_ = this->create_publisher<obj_msg::msg::Detected>("object_found", 10);
    camsrc_ = VideoCapture(0);

    namedWindow("Edit value");
    createTrackbar("hue thresh", "values", &hue_lim, 90);
    createTrackbar("min sat", "values", &min_satur, 255);
    createTrackbar("min val", "values", &min_val, 255);
    createTrackbar("min area", "values", &min_area, 10000);
    createTrackbar("red hue", "values", &red_hue, 180);
    createTrackbar("yellow hue", "values", &yellow_hue, 180);
    createTrackbar("blue hue", "values", &blue_hue, 180);

    if (!camsrc_.isOpened())
    {
      RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to capture video");
    }
    else
    {
      timer_ = this->create_wall_timer(100ms, std::bind(&Detection::topic_callback, this));
    }
  }
  
  ~Detection() {
    camsrc_.release();
    destroyAllWindows();
  }

private:
  void send_msg(Moments &moment, const int color)
    {
      if (moment.m00 < min_area)
          return;

      auto message = obj_msg::msg::Detected();
      message.color = color;
      message.x = moment.m10 / moment.m00 - camsrc_.get(CAP_PROP_FRAME_WIDTH) / 2;
      message.y = moment.m01 / moment.m00 - camsrc_.get(CAP_PROP_FRAME_HEIGHT) / 2;
      message.angle = 2 * float(message.x) / float(camsrc_.get(CAP_PROP_FRAME_WIDTH));
      publisher_->publish(message);
    }
  
  void topic_callback() {

    Mat frame;
    
    if (!camsrc_.read(frame)) {
      RCLCPP_ERROR(this->get_logger(), "An error occured while trying to read frame from video source");
      return;
    }

    Mat framehsv; 
    cvtColor(frame, framehsv, COLOR_BGR2HSV); 
    if (framehsv.empty()) {
      RCLCPP_ERROR(this->get_logger(), "An error occured while trying to convert frame -> HSV");
      return;
    }

    Mat red, yellow, blue;
    inRange(framehsv, Scalar(max(0, red_hue - hue_lim), min_satur, min_val), Scalar(min(255, red_hue + hue_lim), 255, 255), red);
    inRange(framehsv, Scalar(max(0, yellow_hue - hue_lim), min_satur, min_val), Scalar(min(255, yellow_hue + hue_lim), 255, 255), yellow);
    inRange(framehsv, Scalar(max(0, blue_hue - hue_lim), min_satur, min_val), Scalar(min(255, blue_hue + hue_lim), 255, 255), blue);

    Moments red_moments = moments(red), yellow_moments = moments(yellow), blue_moments = moments(blue);

    this->send_msg(red_moments, obj_msg::msg::Detected::RED);
    this->send_msg(yellow_moments, obj_msg::msg::Detected::YELLOW);
    this->send_msg(blue_moments, obj_msg::msg::Detected::BLUE);

    imshow("red", red);
    imshow("yellow", yellow);
    imshow("blue", blue);
    waitKey(1);
  }

  rclcpp::Publisher<obj_msg::msg::Detected>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  VideoCapture camsrc_;

  int red_hue = 0, yellow_hue = 30, blue_hue = 120;
  int hue_lim = 10; //thresh
  int min_satur = 150;
  int min_val = 50;
  int min_area = 10000;
  };

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Detection>());
  rclcpp::shutdown();
  return 0;
}