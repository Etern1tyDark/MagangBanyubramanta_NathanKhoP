// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from obj_msg:msg/Motion.idl
// generated code does not contain a copyright notice

#ifndef OBJ_MSG__MSG__DETAIL__MOTION__BUILDER_HPP_
#define OBJ_MSG__MSG__DETAIL__MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "obj_msg/msg/detail/motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace obj_msg
{

namespace msg
{

namespace builder
{

class Init_Motion_depth
{
public:
  explicit Init_Motion_depth(::obj_msg::msg::Motion & msg)
  : msg_(msg)
  {}
  ::obj_msg::msg::Motion depth(::obj_msg::msg::Motion::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::obj_msg::msg::Motion msg_;
};

class Init_Motion_yaw
{
public:
  explicit Init_Motion_yaw(::obj_msg::msg::Motion & msg)
  : msg_(msg)
  {}
  Init_Motion_depth yaw(::obj_msg::msg::Motion::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_Motion_depth(msg_);
  }

private:
  ::obj_msg::msg::Motion msg_;
};

class Init_Motion_y_cmd
{
public:
  explicit Init_Motion_y_cmd(::obj_msg::msg::Motion & msg)
  : msg_(msg)
  {}
  Init_Motion_yaw y_cmd(::obj_msg::msg::Motion::_y_cmd_type arg)
  {
    msg_.y_cmd = std::move(arg);
    return Init_Motion_yaw(msg_);
  }

private:
  ::obj_msg::msg::Motion msg_;
};

class Init_Motion_x_cmd
{
public:
  Init_Motion_x_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Motion_y_cmd x_cmd(::obj_msg::msg::Motion::_x_cmd_type arg)
  {
    msg_.x_cmd = std::move(arg);
    return Init_Motion_y_cmd(msg_);
  }

private:
  ::obj_msg::msg::Motion msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::obj_msg::msg::Motion>()
{
  return obj_msg::msg::builder::Init_Motion_x_cmd();
}

}  // namespace obj_msg

#endif  // OBJ_MSG__MSG__DETAIL__MOTION__BUILDER_HPP_
