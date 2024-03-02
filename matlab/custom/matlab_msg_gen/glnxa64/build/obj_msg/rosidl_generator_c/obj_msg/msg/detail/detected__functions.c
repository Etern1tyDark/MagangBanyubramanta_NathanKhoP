// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice
#include "obj_msg/msg/detail/detected__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
obj_msg__msg__Detected__init(obj_msg__msg__Detected * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // x
  // y
  return true;
}

void
obj_msg__msg__Detected__fini(obj_msg__msg__Detected * msg)
{
  if (!msg) {
    return;
  }
  // type
  // x
  // y
}

bool
obj_msg__msg__Detected__are_equal(const obj_msg__msg__Detected * lhs, const obj_msg__msg__Detected * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
obj_msg__msg__Detected__copy(
  const obj_msg__msg__Detected * input,
  obj_msg__msg__Detected * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

obj_msg__msg__Detected *
obj_msg__msg__Detected__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obj_msg__msg__Detected * msg = (obj_msg__msg__Detected *)allocator.allocate(sizeof(obj_msg__msg__Detected), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(obj_msg__msg__Detected));
  bool success = obj_msg__msg__Detected__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
obj_msg__msg__Detected__destroy(obj_msg__msg__Detected * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    obj_msg__msg__Detected__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
obj_msg__msg__Detected__Sequence__init(obj_msg__msg__Detected__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obj_msg__msg__Detected * data = NULL;

  if (size) {
    data = (obj_msg__msg__Detected *)allocator.zero_allocate(size, sizeof(obj_msg__msg__Detected), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = obj_msg__msg__Detected__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        obj_msg__msg__Detected__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
obj_msg__msg__Detected__Sequence__fini(obj_msg__msg__Detected__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      obj_msg__msg__Detected__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

obj_msg__msg__Detected__Sequence *
obj_msg__msg__Detected__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  obj_msg__msg__Detected__Sequence * array = (obj_msg__msg__Detected__Sequence *)allocator.allocate(sizeof(obj_msg__msg__Detected__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = obj_msg__msg__Detected__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
obj_msg__msg__Detected__Sequence__destroy(obj_msg__msg__Detected__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    obj_msg__msg__Detected__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
obj_msg__msg__Detected__Sequence__are_equal(const obj_msg__msg__Detected__Sequence * lhs, const obj_msg__msg__Detected__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!obj_msg__msg__Detected__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
obj_msg__msg__Detected__Sequence__copy(
  const obj_msg__msg__Detected__Sequence * input,
  obj_msg__msg__Detected__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(obj_msg__msg__Detected);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    obj_msg__msg__Detected * data =
      (obj_msg__msg__Detected *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!obj_msg__msg__Detected__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          obj_msg__msg__Detected__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!obj_msg__msg__Detected__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
