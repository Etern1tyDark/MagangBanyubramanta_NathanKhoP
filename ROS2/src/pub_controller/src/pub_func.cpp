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

// Microsoft Xbox 360 Wired Controller for Linux - http://wiki.ros.org/joy
/*
enum Buttons
{
	A,
	B,
	X,
	Y,
	LB,
	RB,
	BACK,
	START,
	POWER,
	LEFT_STICK,
	RIGHT_STICK
};

enum Axes
{
	LR_LEFT,
	UD_LEFT,
	LT,
	LR_RIGHT,
	UD_RIGHT,
	RT,
	LR_CROSS,
	UD_CROSS
};
*/
/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

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
    
    motion_data.x_cmd = msg.axes[1] * 180; 
    motion_data.y_cmd = msg.axes[0] * -180;
    motion_data.yaw = tempyaw;
    motion_data.depth = tempdepth;

    tempyaw += ((msg.axes[3] * -1)) * 3;
    tempdepth += (msg.axes[4]) * 3;

    if (tempyaw > 180 || tempyaw < -180) {
      tempyaw *=  -1;
    }
    if (tempdepth > 100 || tempdepth < -100) {
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
