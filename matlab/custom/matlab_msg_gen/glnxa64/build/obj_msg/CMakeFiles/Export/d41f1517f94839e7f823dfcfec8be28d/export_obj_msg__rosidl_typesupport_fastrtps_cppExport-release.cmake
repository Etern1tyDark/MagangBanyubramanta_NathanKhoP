#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "obj_msg::obj_msg__rosidl_typesupport_fastrtps_cpp" for configuration "Release"
set_property(TARGET obj_msg::obj_msg__rosidl_typesupport_fastrtps_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(obj_msg::obj_msg__rosidl_typesupport_fastrtps_cpp PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libobj_msg__rosidl_typesupport_fastrtps_cpp.so"
  IMPORTED_SONAME_RELEASE "libobj_msg__rosidl_typesupport_fastrtps_cpp.so"
  )

list(APPEND _cmake_import_check_targets obj_msg::obj_msg__rosidl_typesupport_fastrtps_cpp )
list(APPEND _cmake_import_check_files_for_obj_msg::obj_msg__rosidl_typesupport_fastrtps_cpp "${_IMPORT_PREFIX}/lib/libobj_msg__rosidl_typesupport_fastrtps_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
