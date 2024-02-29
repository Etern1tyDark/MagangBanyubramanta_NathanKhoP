// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from flare_detect:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef FLARE_DETECT__MSG__DETAIL__DETECTED__BUILDER_HPP_
#define FLARE_DETECT__MSG__DETAIL__DETECTED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "flare_detect/msg/detail/detected__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace flare_detect
{

namespace msg
{

namespace builder
{

class Init_Detected_blue
{
public:
  explicit Init_Detected_blue(::flare_detect::msg::Detected & msg)
  : msg_(msg)
  {}
  ::flare_detect::msg::Detected blue(::flare_detect::msg::Detected::_blue_type arg)
  {
    msg_.blue = std::move(arg);
    return std::move(msg_);
  }

private:
  ::flare_detect::msg::Detected msg_;
};

class Init_Detected_yellow
{
public:
  explicit Init_Detected_yellow(::flare_detect::msg::Detected & msg)
  : msg_(msg)
  {}
  Init_Detected_blue yellow(::flare_detect::msg::Detected::_yellow_type arg)
  {
    msg_.yellow = std::move(arg);
    return Init_Detected_blue(msg_);
  }

private:
  ::flare_detect::msg::Detected msg_;
};

class Init_Detected_red
{
public:
  Init_Detected_red()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Detected_yellow red(::flare_detect::msg::Detected::_red_type arg)
  {
    msg_.red = std::move(arg);
    return Init_Detected_yellow(msg_);
  }

private:
  ::flare_detect::msg::Detected msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::flare_detect::msg::Detected>()
{
  return flare_detect::msg::builder::Init_Detected_red();
}

}  // namespace flare_detect

#endif  // FLARE_DETECT__MSG__DETAIL__DETECTED__BUILDER_HPP_
