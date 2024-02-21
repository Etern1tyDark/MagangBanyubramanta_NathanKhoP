// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Motion.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__MOTION__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Motion_depth
{
public:
  explicit Init_Motion_depth(::interfaces::msg::Motion & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Motion depth(::interfaces::msg::Motion::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Motion msg_;
};

class Init_Motion_yaw
{
public:
  explicit Init_Motion_yaw(::interfaces::msg::Motion & msg)
  : msg_(msg)
  {}
  Init_Motion_depth yaw(::interfaces::msg::Motion::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Motion_depth(msg_);
  }

private:
  ::interfaces::msg::Motion msg_;
};

class Init_Motion_y_cmd
{
public:
  explicit Init_Motion_y_cmd(::interfaces::msg::Motion & msg)
  : msg_(msg)
  {}
  Init_Motion_yaw y_cmd(::interfaces::msg::Motion::_y_cmd_type arg)
  {
    msg_.y_cmd = std::move(arg);
    return Init_Motion_yaw(msg_);
  }

private:
  ::interfaces::msg::Motion msg_;
};

class Init_Motion_x_cmd
{
public:
  Init_Motion_x_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Motion_y_cmd x_cmd(::interfaces::msg::Motion::_x_cmd_type arg)
  {
    msg_.x_cmd = std::move(arg);
    return Init_Motion_y_cmd(msg_);
  }

private:
  ::interfaces::msg::Motion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Motion>()
{
  return interfaces::msg::builder::Init_Motion_x_cmd();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__MOTION__BUILDER_HPP_
