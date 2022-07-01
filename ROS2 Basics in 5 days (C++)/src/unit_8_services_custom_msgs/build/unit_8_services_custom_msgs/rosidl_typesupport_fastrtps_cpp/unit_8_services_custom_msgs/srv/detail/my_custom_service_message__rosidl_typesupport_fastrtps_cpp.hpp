// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace unit_8_services_custom_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_serialize(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
get_serialized_size(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
max_serialized_size_MyCustomServiceMessage_Request(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)();

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// already included above
// #include "fastcdr/Cdr.h"

namespace unit_8_services_custom_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_serialize(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
get_serialized_size(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
max_serialized_size_MyCustomServiceMessage_Response(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)();

#ifdef __cplusplus
}
#endif

#include "rmw/types.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
const rosidl_service_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage)();

#ifdef __cplusplus
}
#endif

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
