// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DETECTED__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__DETECTED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/detected__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Detected_angle
{
public:
  explicit Init_Detected_angle(::interfaces::msg::Detected & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Detected angle(::interfaces::msg::Detected::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Detected msg_;
};

class Init_Detected_y
{
public:
  explicit Init_Detected_y(::interfaces::msg::Detected & msg)
  : msg_(msg)
  {}
  Init_Detected_angle y(::interfaces::msg::Detected::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Detected_angle(msg_);
  }

private:
  ::interfaces::msg::Detected msg_;
};

class Init_Detected_x
{
public:
  explicit Init_Detected_x(::interfaces::msg::Detected & msg)
  : msg_(msg)
  {}
  Init_Detected_y x(::interfaces::msg::Detected::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Detected_y(msg_);
  }

private:
  ::interfaces::msg::Detected msg_;
};

class Init_Detected_color
{
public:
  Init_Detected_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detected_x color(::interfaces::msg::Detected::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_Detected_x(msg_);
  }

private:
  ::interfaces::msg::Detected msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Detected>()
{
  return interfaces::msg::builder::Init_Detected_color();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DETECTED__BUILDER_HPP_
