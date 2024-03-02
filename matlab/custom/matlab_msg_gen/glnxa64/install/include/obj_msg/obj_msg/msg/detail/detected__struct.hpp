// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_HPP_
#define OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__obj_msg__msg__Detected __attribute__((deprecated))
#else
# define DEPRECATED__obj_msg__msg__Detected __declspec(deprecated)
#endif

namespace obj_msg
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
      this->type = 0;
      this->x = 0l;
      this->y = 0l;
    }
  }

  explicit Detected_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = 0;
      this->x = 0l;
      this->y = 0l;
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _x_type =
    int32_t;
  _x_type x;
  using _y_type =
    int32_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
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

  // constant declarations
  static constexpr uint8_t GATE =
    0u;
  static constexpr uint8_t RED =
    1u;
  static constexpr uint8_t YELLOW =
    2u;
  static constexpr uint8_t BLUE =
    3u;

  // pointer types
  using RawPtr =
    obj_msg::msg::Detected_<ContainerAllocator> *;
  using ConstRawPtr =
    const obj_msg::msg::Detected_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<obj_msg::msg::Detected_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<obj_msg::msg::Detected_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      obj_msg::msg::Detected_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<obj_msg::msg::Detected_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      obj_msg::msg::Detected_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<obj_msg::msg::Detected_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<obj_msg::msg::Detected_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<obj_msg::msg::Detected_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__obj_msg__msg__Detected
    std::shared_ptr<obj_msg::msg::Detected_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__obj_msg__msg__Detected
    std::shared_ptr<obj_msg::msg::Detected_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Detected_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
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
  obj_msg::msg::Detected_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t Detected_<ContainerAllocator>::GATE;
template<typename ContainerAllocator>
constexpr uint8_t Detected_<ContainerAllocator>::RED;
template<typename ContainerAllocator>
constexpr uint8_t Detected_<ContainerAllocator>::YELLOW;
template<typename ContainerAllocator>
constexpr uint8_t Detected_<ContainerAllocator>::BLUE;

}  // namespace msg

}  // namespace obj_msg

#endif  // OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_HPP_
