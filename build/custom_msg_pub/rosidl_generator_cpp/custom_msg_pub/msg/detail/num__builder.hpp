// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_pub:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG_PUB__MSG__DETAIL__NUM__BUILDER_HPP_
#define CUSTOM_MSG_PUB__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msg_pub/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msg_pub
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msg_pub::msg::Num num(::custom_msg_pub::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_pub::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_pub::msg::Num>()
{
  return custom_msg_pub::msg::builder::Init_Num_num();
}

}  // namespace custom_msg_pub

#endif  // CUSTOM_MSG_PUB__MSG__DETAIL__NUM__BUILDER_HPP_
