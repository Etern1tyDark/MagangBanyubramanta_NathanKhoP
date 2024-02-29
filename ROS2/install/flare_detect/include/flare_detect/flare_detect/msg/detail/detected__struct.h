// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from flare_detect:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef FLARE_DETECT__MSG__DETAIL__DETECTED__STRUCT_H_
#define FLARE_DETECT__MSG__DETAIL__DETECTED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Detected in the package flare_detect.
typedef struct flare_detect__msg__Detected
{
  int32_t red;
  int32_t yellow;
  int32_t blue;
} flare_detect__msg__Detected;

// Struct for a sequence of flare_detect__msg__Detected.
typedef struct flare_detect__msg__Detected__Sequence
{
  flare_detect__msg__Detected * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} flare_detect__msg__Detected__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FLARE_DETECT__MSG__DETAIL__DETECTED__STRUCT_H_
