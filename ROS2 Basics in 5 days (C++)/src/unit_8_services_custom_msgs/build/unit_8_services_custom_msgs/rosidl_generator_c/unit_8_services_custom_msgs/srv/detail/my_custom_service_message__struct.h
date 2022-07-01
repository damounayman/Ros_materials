// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_H_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/MyCustomServiceMessage in the package unit_8_services_custom_msgs.
typedef struct unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request
{
  double radius;
  int32_t repetitions;
} unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request;

// Struct for a sequence of unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request.
typedef struct unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/MyCustomServiceMessage in the package unit_8_services_custom_msgs.
typedef struct unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response
{
  bool success;
} unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response;

// Struct for a sequence of unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response.
typedef struct unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_H_
