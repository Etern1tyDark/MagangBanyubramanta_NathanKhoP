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
#include "sensor_msgs/msg/joy.hpp"
#include "obj_msg/msg/motion.hpp"

using std::placeholders::_1;

#define R_SPEED 3

#define L_MIN -180
#define L_MAX 180

#define R_MIN -100
#define R_MAX 100

/*
Microsoft Xbox 360 Wired Controller for Linux - http://wiki.ros.org/joy
enum Axes
{
	LR_LEFT,  0
	UD_LEFT,  1
	LT,       2
	LR_RIGHT, 3
	UD_RIGHT, 4
	RT,       5
	LR_CROSS, 6
	UD_CROSS  7
};
*/

class Controller : public rclcpp::Node
{
public:

  int tempyaw = 0, tempdepth = 0;

  Controller()
  : Node("controller")
  {
    publisher_ = this->create_publisher<obj_msg::msg::Motion>("commands", 10);
    subscriber_ = this->create_subscription<sensor_msgs::msg::Joy>(
        "joy", 10, std::bind(&Controller::topic_callback, this, _1)
    );
  }

private:
  void topic_callback(const sensor_msgs::msg::Joy &msg)
  {
    auto motion_data = obj_msg::msg::Motion();
    
    motion_data.x_cmd = msg.axes[1] * L_MAX; 
    motion_data.y_cmd = msg.axes[0] * L_MIN;
    motion_data.yaw = tempyaw;
    motion_data.depth = tempdepth;

    tempyaw += ((msg.axes[3] * -1)) * R_SPEED;
    tempdepth += (msg.axes[4]) * R_SPEED;

    if (tempyaw > L_MAX || tempyaw < L_MIN) {
      tempyaw *=  -1;
    }
    if (tempdepth > R_MAX || tempyaw < R_MIN) {
      tempdepth *=  -1;
    } 
    
    publisher_->publish(motion_data);
    RCLCPP_INFO(this->get_logger(), "Motion commands inputted, [%d], [%d], [%d], [%d]", motion_data.x_cmd, motion_data.y_cmd, motion_data.yaw, motion_data.depth);
  }
  rclcpp::Publisher<obj_msg::msg::Motion>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscriber_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Controller>());
  rclcpp::shutdown();
  return 0;
}
