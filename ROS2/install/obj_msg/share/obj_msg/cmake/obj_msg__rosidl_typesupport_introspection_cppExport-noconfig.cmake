#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "obj_msg::obj_msg__rosidl_typesupport_introspection_cpp" for configuration ""
set_property(TARGET obj_msg::obj_msg__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(obj_msg::obj_msg__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libobj_msg__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_NOCONFIG "libobj_msg__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS obj_msg::obj_msg__rosidl_typesupport_introspection_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_obj_msg::obj_msg__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/libobj_msg__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)