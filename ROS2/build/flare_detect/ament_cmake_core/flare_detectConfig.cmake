# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_flare_detect_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED flare_detect_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(flare_detect_FOUND FALSE)
  elseif(NOT flare_detect_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(flare_detect_FOUND FALSE)
  endif()
  return()
endif()
set(_flare_detect_CONFIG_INCLUDED TRUE)

# output package information
if(NOT flare_detect_FIND_QUIETLY)
  message(STATUS "Found flare_detect: 0.0.0 (${flare_detect_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'flare_detect' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${flare_detect_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(flare_detect_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${flare_detect_DIR}/${_extra}")
endforeach()
