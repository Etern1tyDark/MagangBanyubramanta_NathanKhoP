#ifndef OBJ_MSG__VISIBILITY_CONTROL_H_
#define OBJ_MSG__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define OBJ_MSG_EXPORT __attribute__ ((dllexport))
    #define OBJ_MSG_IMPORT __attribute__ ((dllimport))
  #else
    #define OBJ_MSG_EXPORT __declspec(dllexport)
    #define OBJ_MSG_IMPORT __declspec(dllimport)
  #endif
  #ifdef OBJ_MSG_BUILDING_LIBRARY
    #define OBJ_MSG_PUBLIC OBJ_MSG_EXPORT
  #else
    #define OBJ_MSG_PUBLIC OBJ_MSG_IMPORT
  #endif
  #define OBJ_MSG_PUBLIC_TYPE OBJ_MSG_PUBLIC
  #define OBJ_MSG_LOCAL
#else
  #define OBJ_MSG_EXPORT __attribute__ ((visibility("default")))
  #define OBJ_MSG_IMPORT
  #if __GNUC__ >= 4
    #define OBJ_MSG_PUBLIC __attribute__ ((visibility("default")))
    #define OBJ_MSG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define OBJ_MSG_PUBLIC
    #define OBJ_MSG_LOCAL
  #endif
  #define OBJ_MSG_PUBLIC_TYPE
#endif
#endif  // OBJ_MSG__VISIBILITY_CONTROL_H_
// Generated 02-Mar-2024 02:09:40
 