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

#define DEBUG

Mat frame;
Point red_p, yellow_p, blue_p;

Scalar BLUE_sc = Scalar(255,178,50);
Scalar YELLOW_sc = Scalar(0,255,255);
Scalar RED_sc = Scalar(0,0,255);

class Detection : public rclcpp::Node
{
public:
  Detection() : Node("detection")
  { 
    publisher_ = this->create_publisher<obj_msg::msg::Detected>("object_found", 10);
    camsrc_ = VideoCapture(0);

/*
    namedWindow("Edit value");
    createTrackbar("hue thresh", "values", &hue_lim, 90);
    createTrackbar("min sat", "values", &min_satur, 255);
    createTrackbar("min val", "values", &min_val, 255);
    createTrackbar("min area", "values", &min_area, 10000);
    createTrackbar("red hue", "values", &red_hue, 180);
    createTrackbar("yellow hue", "values", &yellow_hue, 180);
    createTrackbar("blue hue", "values", &blue_hue, 180);
*/ 

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
      message.type = color;
      message.x = moment.m10 / moment.m00 - camsrc_.get(CAP_PROP_FRAME_WIDTH) / 2;
      message.y = moment.m01 / moment.m00 - camsrc_.get(CAP_PROP_FRAME_HEIGHT) / 2;
      // message.angle = 2 * float(message.x) / float(camsrc_.get(CAP_PROP_FRAME_WIDTH));
      publisher_->publish(message);
    }
  
  Point findCenter(Mat &maskHSV, Scalar color)
    {
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        Point center_point;
        findContours(maskHSV, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        // drawContours(frame, contours, -1,(50,255,50),3);
        for (size_t i = 0; i < contours.size(); ++i)
        {
            Rect boundRect = boundingRect(contours[i]);
            // center_point.push_back(cv::Point(boundRect.x + boundRect.width / 2, boundRect.y + boundRect.height / 2));
            int colorarea = boundRect.height * boundRect.width;
            if (colorarea > 3000) 
            rectangle(frame, boundRect.tl(), boundRect.br(), color, 2);
            center_point.x = boundRect.x + boundRect.width / 2;
            center_point.y = boundRect.y + boundRect.height / 2;
        }
        return center_point;
    }

  void topic_callback() {
    
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
    inRange(framehsv, Scalar(max(0, yellow_hue - hue_lim), 100, min_val), Scalar(min(255, yellow_hue + hue_lim), 255, 255), yellow);
    inRange(framehsv, Scalar(max(0, blue_hue - hue_lim), min_satur, min_val), Scalar(min(255, blue_hue + hue_lim), 255, 255), blue);

    Moments red_moments = moments(red), yellow_moments = moments(yellow), blue_moments = moments(blue);

    this->send_msg(red_moments, obj_msg::msg::Detected::RED);
    this->send_msg(yellow_moments, obj_msg::msg::Detected::YELLOW);
    this->send_msg(blue_moments, obj_msg::msg::Detected::BLUE);

    red_p = findCenter(red, RED_sc);
    yellow_p = findCenter(yellow, YELLOW_sc);
    blue_p = findCenter(blue, BLUE_sc);
    
    #ifdef DEBUG
    imshow("frame", frame);
    // imshow("red", red);
    // imshow("yellow", yellow);
    // imshow("blue", blue);
    #endif
    waitKey(1);
  }

  rclcpp::Publisher<obj_msg::msg::Detected>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  VideoCapture camsrc_;

  int red_hue = 0, yellow_hue = 30, blue_hue = 110;
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