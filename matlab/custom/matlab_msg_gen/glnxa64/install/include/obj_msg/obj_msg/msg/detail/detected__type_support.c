// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "obj_msg/msg/detail/detected__rosidl_typesupport_introspection_c.h"
#include "obj_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "obj_msg/msg/detail/detected__functions.h"
#include "obj_msg/msg/detail/detected__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  obj_msg__msg__Detected__init(message_memory);
}

void obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_fini_function(void * message_memory)
{
  obj_msg__msg__Detected__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_member_array[3] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obj_msg__msg__Detected, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obj_msg__msg__Detected, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(obj_msg__msg__Detected, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_members = {
  "obj_msg__msg",  // message namespace
  "Detected",  // message name
  3,  // number of fields
  sizeof(obj_msg__msg__Detected),
  obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_member_array,  // message members
  obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_init_function,  // function to initialize message memory (memory has to be allocated)
  obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_type_support_handle = {
  0,
  &obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_obj_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, obj_msg, msg, Detected)() {
  if (!obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_type_support_handle.typesupport_identifier) {
    obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &obj_msg__msg__Detected__rosidl_typesupport_introspection_c__Detected_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
