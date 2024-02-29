// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from obj_msg:msg/Detected.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "obj_msg/msg/detail/detected__struct.h"
#include "obj_msg/msg/detail/detected__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool obj_msg__msg__detected__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[31];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("obj_msg.msg._detected.Detected", full_classname_dest, 30) == 0);
  }
  obj_msg__msg__Detected * ros_message = _ros_message;
  {  // color
    PyObject * field = PyObject_GetAttrString(_pymsg, "color");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->color = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->x = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->y = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * obj_msg__msg__detected__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Detected */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("obj_msg.msg._detected");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Detected");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  obj_msg__msg__Detected * ros_message = (obj_msg__msg__Detected *)raw_ros_message;
  {  // color
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->color);
    {
      int rc = PyObject_SetAttrString(_pymessage, "color", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
