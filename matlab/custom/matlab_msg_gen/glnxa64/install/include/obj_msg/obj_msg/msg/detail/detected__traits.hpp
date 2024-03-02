// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef OBJ_MSG__MSG__DETAIL__DETECTED__TRAITS_HPP_
#define OBJ_MSG__MSG__DETAIL__DETECTED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "obj_msg/msg/detail/detected__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace obj_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Detected & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detected & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Detected & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace obj_msg

namespace rosidl_generator_traits
{

[[deprecated("use obj_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const obj_msg::msg::Detected & msg,
  std::ostream & out, size_t indentation = 0)
{
  obj_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use obj_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const obj_msg::msg::Detected & msg)
{
  return obj_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<obj_msg::msg::Detected>()
{
  return "obj_msg::msg::Detected";
}

template<>
inline const char * name<obj_msg::msg::Detected>()
{
  return "obj_msg/msg/Detected";
}

template<>
struct has_fixed_size<obj_msg::msg::Detected>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<obj_msg::msg::Detected>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<obj_msg::msg::Detected>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // OBJ_MSG__MSG__DETAIL__DETECTED__TRAITS_HPP_
