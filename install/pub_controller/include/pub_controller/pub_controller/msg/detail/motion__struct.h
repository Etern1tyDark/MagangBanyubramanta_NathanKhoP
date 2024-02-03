// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pub_controller:msg/Motion.idl
// generated code does not contain a copyright notice

#ifndef PUB_CONTROLLER__MSG__DETAIL__MOTION__STRUCT_H_
#define PUB_CONTROLLER__MSG__DETAIL__MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Motion in the package pub_controller.
typedef struct pub_controller__msg__Motion
{
  int32_t x_cmd;
  int32_t y_cmd;
  int32_t yaw;
  int32_t depth;
} pub_controller__msg__Motion;

// Struct for a sequence of pub_controller__msg__Motion.
typedef struct pub_controller__msg__Motion__Sequence
{
  pub_controller__msg__Motion * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pub_controller__msg__Motion__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PUB_CONTROLLER__MSG__DETAIL__MOTION__STRUCT_H_
