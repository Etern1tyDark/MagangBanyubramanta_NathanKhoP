// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__DETECTED__STRUCT_H_
#define INTERFACES__MSG__DETAIL__DETECTED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'RED'.
enum
{
  interfaces__msg__Detected__RED = 0l
};

/// Constant 'YELLOW'.
enum
{
  interfaces__msg__Detected__YELLOW = 1l
};

/// Constant 'BLUE'.
enum
{
  interfaces__msg__Detected__BLUE = 2l
};

/// Struct defined in msg/Detected in the package interfaces.
typedef struct interfaces__msg__Detected
{
  int32_t color;
  int32_t x;
  int32_t y;
  float angle;
} interfaces__msg__Detected;

// Struct for a sequence of interfaces__msg__Detected.
typedef struct interfaces__msg__Detected__Sequence
{
  interfaces__msg__Detected * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Detected__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__DETECTED__STRUCT_H_
