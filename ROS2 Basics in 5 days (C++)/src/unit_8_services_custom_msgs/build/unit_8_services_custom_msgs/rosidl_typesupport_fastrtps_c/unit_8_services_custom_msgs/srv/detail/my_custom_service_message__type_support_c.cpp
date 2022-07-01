// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.h"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MyCustomServiceMessage_Request__ros_msg_type = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request;

static bool _MyCustomServiceMessage_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyCustomServiceMessage_Request__ros_msg_type * ros_message = static_cast<const _MyCustomServiceMessage_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: radius
  {
    cdr << ros_message->radius;
  }

  // Field name: repetitions
  {
    cdr << ros_message->repetitions;
  }

  return true;
}

static bool _MyCustomServiceMessage_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyCustomServiceMessage_Request__ros_msg_type * ros_message = static_cast<_MyCustomServiceMessage_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: radius
  {
    cdr >> ros_message->radius;
  }

  // Field name: repetitions
  {
    cdr >> ros_message->repetitions;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_unit_8_services_custom_msgs
size_t get_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyCustomServiceMessage_Request__ros_msg_type * ros_message = static_cast<const _MyCustomServiceMessage_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name radius
  {
    size_t item_size = sizeof(ros_message->radius);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name repetitions
  {
    size_t item_size = sizeof(ros_message->repetitions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyCustomServiceMessage_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_unit_8_services_custom_msgs
size_t max_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: radius
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: repetitions
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _MyCustomServiceMessage_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MyCustomServiceMessage_Request = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage_Request",
  _MyCustomServiceMessage_Request__cdr_serialize,
  _MyCustomServiceMessage_Request__cdr_deserialize,
  _MyCustomServiceMessage_Request__get_serialized_size,
  _MyCustomServiceMessage_Request__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomServiceMessage_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyCustomServiceMessage_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)() {
  return &_MyCustomServiceMessage_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MyCustomServiceMessage_Response__ros_msg_type = unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response;

static bool _MyCustomServiceMessage_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MyCustomServiceMessage_Response__ros_msg_type * ros_message = static_cast<const _MyCustomServiceMessage_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _MyCustomServiceMessage_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MyCustomServiceMessage_Response__ros_msg_type * ros_message = static_cast<_MyCustomServiceMessage_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_unit_8_services_custom_msgs
size_t get_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MyCustomServiceMessage_Response__ros_msg_type * ros_message = static_cast<const _MyCustomServiceMessage_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MyCustomServiceMessage_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_unit_8_services_custom_msgs
size_t max_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MyCustomServiceMessage_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_MyCustomServiceMessage_Response = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage_Response",
  _MyCustomServiceMessage_Response__cdr_serialize,
  _MyCustomServiceMessage_Response__cdr_deserialize,
  _MyCustomServiceMessage_Response__get_serialized_size,
  _MyCustomServiceMessage_Response__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomServiceMessage_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MyCustomServiceMessage_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)() {
  return &_MyCustomServiceMessage_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "unit_8_services_custom_msgs/srv/my_custom_service_message.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MyCustomServiceMessage__callbacks = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)(),
};

static rosidl_service_type_support_t MyCustomServiceMessage__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MyCustomServiceMessage__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage)() {
  return &MyCustomServiceMessage__handle;
}

#if defined(__cplusplus)
}
#endif
