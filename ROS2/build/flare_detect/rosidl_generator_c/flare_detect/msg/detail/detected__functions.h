// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from flare_detect:msg/Detected.idl
// generated code does not contain a copyright notice

#ifndef FLARE_DETECT__MSG__DETAIL__DETECTED__FUNCTIONS_H_
#define FLARE_DETECT__MSG__DETAIL__DETECTED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "flare_detect/msg/rosidl_generator_c__visibility_control.h"

#include "flare_detect/msg/detail/detected__struct.h"

/// Initialize msg/Detected message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * flare_detect__msg__Detected
 * )) before or use
 * flare_detect__msg__Detected__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__init(flare_detect__msg__Detected * msg);

/// Finalize msg/Detected message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
void
flare_detect__msg__Detected__fini(flare_detect__msg__Detected * msg);

/// Create msg/Detected message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * flare_detect__msg__Detected__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
flare_detect__msg__Detected *
flare_detect__msg__Detected__create();

/// Destroy msg/Detected message.
/**
 * It calls
 * flare_detect__msg__Detected__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
void
flare_detect__msg__Detected__destroy(flare_detect__msg__Detected * msg);

/// Check for msg/Detected message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__are_equal(const flare_detect__msg__Detected * lhs, const flare_detect__msg__Detected * rhs);

/// Copy a msg/Detected message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__copy(
  const flare_detect__msg__Detected * input,
  flare_detect__msg__Detected * output);

/// Initialize array of msg/Detected messages.
/**
 * It allocates the memory for the number of elements and calls
 * flare_detect__msg__Detected__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__Sequence__init(flare_detect__msg__Detected__Sequence * array, size_t size);

/// Finalize array of msg/Detected messages.
/**
 * It calls
 * flare_detect__msg__Detected__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
void
flare_detect__msg__Detected__Sequence__fini(flare_detect__msg__Detected__Sequence * array);

/// Create array of msg/Detected messages.
/**
 * It allocates the memory for the array and calls
 * flare_detect__msg__Detected__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
flare_detect__msg__Detected__Sequence *
flare_detect__msg__Detected__Sequence__create(size_t size);

/// Destroy array of msg/Detected messages.
/**
 * It calls
 * flare_detect__msg__Detected__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
void
flare_detect__msg__Detected__Sequence__destroy(flare_detect__msg__Detected__Sequence * array);

/// Check for msg/Detected message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__Sequence__are_equal(const flare_detect__msg__Detected__Sequence * lhs, const flare_detect__msg__Detected__Sequence * rhs);

/// Copy an array of msg/Detected messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_flare_detect
bool
flare_detect__msg__Detected__Sequence__copy(
  const flare_detect__msg__Detected__Sequence * input,
  flare_detect__msg__Detected__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FLARE_DETECT__MSG__DETAIL__DETECTED__FUNCTIONS_H_
