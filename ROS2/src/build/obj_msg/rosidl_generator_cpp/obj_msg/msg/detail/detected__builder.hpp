// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef OBJ_MSG__MSG__DETAIL__DETECTED__BUILDER_HPP_
#define OBJ_MSG__MSG__DETAIL__DETECTED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obj_msg/msg/detail/detected__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obj_msg
{

namespace msg
{

namespace builder
{

class Init_Detected_angle
{
public:
  explicit Init_Detected_angle(::obj_msg::msg::Detected & msg)
  : msg_(msg)
  {}
  ::obj_msg::msg::Detected angle(::obj_msg::msg::Detected::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obj_msg::msg::Detected msg_;
};

class Init_Detected_y
{
public:
  explicit Init_Detected_y(::obj_msg::msg::Detected & msg)
  : msg_(msg)
  {}
  Init_Detected_angle y(::obj_msg::msg::Detected::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Detected_angle(msg_);
  }

private:
  ::obj_msg::msg::Detected msg_;
};

class Init_Detected_x
{
public:
  explicit Init_Detected_x(::obj_msg::msg::Detected & msg)
  : msg_(msg)
  {}
  Init_Detected_y x(::obj_msg::msg::Detected::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Detected_y(msg_);
  }

private:
  ::obj_msg::msg::Detected msg_;
};

class Init_Detected_color
{
public:
  Init_Detected_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detected_x color(::obj_msg::msg::Detected::_color_type arg)
  {
    msg_.color = std::move(arg);
    return Init_Detected_x(msg_);
  }

private:
  ::obj_msg::msg::Detected msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obj_msg::msg::Detected>()
{
  return obj_msg::msg::builder::Init_Detected_color();
}

}  // namespace obj_msg

#endif  // OBJ_MSG__MSG__DETAIL__DETECTED__BUILDER_HPP_