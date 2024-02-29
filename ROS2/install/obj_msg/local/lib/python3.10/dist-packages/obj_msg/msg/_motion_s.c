// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from obj_msg:msg/Motion.idl
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
#include "obj_msg/msg/detail/motion__struct.h"
#include "obj_msg/msg/detail/motion__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool obj_msg__msg__motion__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[27];
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
    assert(strncmp("obj_msg.msg._motion.Motion", full_classname_dest, 26) == 0);
  }
  obj_msg__msg__Motion * ros_message = _ros_message;
  {  // x_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_cmd");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->x_cmd = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // y_cmd
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_cmd");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->y_cmd = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->yaw = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // depth
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->depth = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * obj_msg__msg__motion__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Motion */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("obj_msg.msg._motion");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Motion");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  obj_msg__msg__Motion * ros_message = (obj_msg__msg__Motion *)raw_ros_message;
  {  // x_cmd
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->x_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_cmd
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->y_cmd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_cmd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->depth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
