# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:obj_msg__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:obj_msg__rosidl_typesupport_fastrtps_c;__rosidl_typesupport_introspection_c:obj_msg__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:obj_msg__rosidl_typesupport_c;__rosidl_generator_cpp:obj_msg__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:obj_msg__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_cpp:obj_msg__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:obj_msg__rosidl_typesupport_cpp;__rosidl_generator_py:obj_msg__rosidl_generator_py")

# populate obj_msg_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "obj_msg::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'obj_msg' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND obj_msg_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
