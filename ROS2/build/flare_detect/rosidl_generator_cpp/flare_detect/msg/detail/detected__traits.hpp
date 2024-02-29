// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from flare_detect:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef FLARE_DETECT__MSG__DETAIL__DETECTED__TRAITS_HPP_
#define FLARE_DETECT__MSG__DETAIL__DETECTED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "flare_detect/msg/detail/detected__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace flare_detect
{

namespace msg
{

inline void to_flow_style_yaml(
  const Detected & msg,
  std::ostream & out)
{
  out << "{";
  // member: red
  {
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << ", ";
  }

  // member: yellow
  {
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << ", ";
  }

  // member: blue
  {
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Detected & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: red
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "red: ";
    rosidl_generator_traits::value_to_yaml(msg.red, out);
    out << "\n";
  }

  // member: yellow
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yellow: ";
    rosidl_generator_traits::value_to_yaml(msg.yellow, out);
    out << "\n";
  }

  // member: blue
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blue: ";
    rosidl_generator_traits::value_to_yaml(msg.blue, out);
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

}  // namespace flare_detect

namespace rosidl_generator_traits
{

[[deprecated("use flare_detect::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const flare_detect::msg::Detected & msg,
  std::ostream & out, size_t indentation = 0)
{
  flare_detect::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use flare_detect::msg::to_yaml() instead")]]
inline std::string to_yaml(const flare_detect::msg::Detected & msg)
{
  return flare_detect::msg::to_yaml(msg);
}

template<>
inline const char * data_type<flare_detect::msg::Detected>()
{
  return "flare_detect::msg::Detected";
}

template<>
inline const char * name<flare_detect::msg::Detected>()
{
  return "flare_detect/msg/Detected";
}

template<>
struct has_fixed_size<flare_detect::msg::Detected>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<flare_detect::msg::Detected>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<flare_detect::msg::Detected>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FLARE_DETECT__MSG__DETAIL__DETECTED__TRAITS_HPP_
