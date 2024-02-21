// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DETECTED__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__DETECTED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Detected __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Detected __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Detected_
{
  using Type = Detected_<ContainerAllocator>;

  explicit Detected_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = 0l;
      this->x = 0l;
      this->y = 0l;
      this->angle = 0.0f;
    }
  }

  explicit Detected_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = 0l;
      this->x = 0l;
      this->y = 0l;
      this->angle = 0.0f;
    }
  }

  // field types and members
  using _color_type =
    int32_t;
  _color_type color;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;
  using _angle_type =
    float;
  _angle_type angle;

  // setters for named parameter idiom
  Type & set__color(
    const int32_t & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__x(
    const int32_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int32_t & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t RED =
    0;
  static constexpr int32_t YELLOW =
    1;
  static constexpr int32_t BLUE =
    2;

  // pointer types
  using RawPtr =
    interfaces::msg::Detected_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Detected_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Detected_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Detected_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Detected_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Detected_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Detected_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Detected_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Detected_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Detected_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Detected
    std::shared_ptr<interfaces::msg::Detected_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Detected
    std::shared_ptr<interfaces::msg::Detected_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Detected_ & other) const
  {
    if (this->color != other.color) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const Detected_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Detected_

// alias to use template instance with default allocator
using Detected =
  interfaces::msg::Detected_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr int32_t Detected_<ContainerAllocator>::RED;
template<typename ContainerAllocator>
constexpr int32_t Detected_<ContainerAllocator>::YELLOW;
template<typename ContainerAllocator>
constexpr int32_t Detected_<ContainerAllocator>::BLUE;

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__DETECTED__STRUCT_HPP_
