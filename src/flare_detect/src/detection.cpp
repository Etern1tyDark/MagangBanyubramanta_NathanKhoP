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

// TODO
#define red_hue 0
#define yellow_hue 30
#define blue_hue 120
#define hue_lim 20
#define min_satur 50
#define min_val 50

class Detection : public rclcpp::Node
{
public:
  Detection() : Node("detection")
  { 
    publisher_ = this->create_publisher<obj_msg::msg::Detected>("object_found", 10);
    camsrc_ = VideoCapture(0);

    if (!camsrc_.isOpened())
    {
      RCLCPP_ERROR(this->get_logger(), "An error occurred while trying to capture video");
    }
    else
    {
      timer_ = this->create_wall_timer(500ms, std::bind(&Detection::topic_callback, this));
    }
  }
  
  ~Detection() {
    camsrc_.release();
    destroyAllWindows();
  }

private:
  void topic_callback() {

    Mat frame;
    
    if (!camsrc_.read(frame)) {
      RCLCPP_ERROR(this->get_logger(), "An error occured while trying to read frame from video source");
      return;
    }
    imshow("Frame", frame);
    waitKey(1);

    Mat framehsv; 
    cvtColor(frame, framehsv, COLOR_BGR2HSV); 
    if (framehsv.empty()) {
      RCLCPP_ERROR(this->get_logger(), "An error occured while trying to convert frame -> HSV");
      return;
    }
    
    imshow("HSV Frame", framehsv);
    waitKey(1);

    Mat red, yellow, blue;
    inRange(framehsv, Scalar(max(0, red_hue - hue_lim), min_satur, min_val), Scalar(min(255, red_hue + hue_lim), 255, 255), red);
    inRange(framehsv, Scalar(max(0, yellow_hue - hue_lim), min_satur, min_val), Scalar(min(255, yellow_hue + hue_lim), 255, 255), yellow);
    inRange(framehsv, Scalar(max(0, blue_hue - hue_lim), min_satur, min_val), Scalar(min(255, blue_hue + hue_lim), 255, 255), blue);

    auto message = obj_msg::msg::Detected();
    message.red = countNonZero(red) > 0;
    message.yellow = countNonZero(yellow) > 0;
    message.blue = countNonZero(blue) > 0;
    publisher_->publish(message);
  }

  rclcpp::Publisher<obj_msg::msg::Detected>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  VideoCapture camsrc_;
  };

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Detection>());
  rclcpp::shutdown();
  return 0;
}