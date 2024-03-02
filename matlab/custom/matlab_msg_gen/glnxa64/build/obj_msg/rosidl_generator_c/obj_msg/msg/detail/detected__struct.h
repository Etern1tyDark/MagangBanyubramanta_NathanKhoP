// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_H_
#define OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GATE'.
enum
{
  obj_msg__msg__Detected__GATE = 1
};

/// Constant 'RED'.
enum
{
  obj_msg__msg__Detected__RED = 2
};

/// Constant 'YELLOW'.
enum
{
  obj_msg__msg__Detected__YELLOW = 3
};

/// Constant 'BLUE'.
enum
{
  obj_msg__msg__Detected__BLUE = 4
};

/// Struct defined in msg/Detected in the package obj_msg.
typedef struct obj_msg__msg__Detected
{
  uint8_t type;
  int32_t x;
  int32_t y;
} obj_msg__msg__Detected;

// Struct for a sequence of obj_msg__msg__Detected.
typedef struct obj_msg__msg__Detected__Sequence
{
  obj_msg__msg__Detected * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} obj_msg__msg__Detected__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OBJ_MSG__MSG__DETAIL__DETECTED__STRUCT_H_
