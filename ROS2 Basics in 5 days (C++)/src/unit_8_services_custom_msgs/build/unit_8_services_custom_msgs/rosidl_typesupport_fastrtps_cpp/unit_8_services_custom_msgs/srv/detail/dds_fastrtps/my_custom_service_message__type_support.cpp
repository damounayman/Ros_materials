// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: radius
  cdr << ros_message.radius;
  // Member: repetitions
  cdr << ros_message.repetitions;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & ros_message)
{
  // Member: radius
  cdr >> ros_message.radius;

  // Member: repetitions
  cdr >> ros_message.repetitions;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
get_serialized_size(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: radius
  {
    size_t item_size = sizeof(ros_message.radius);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: repetitions
  {
    size_t item_size = sizeof(ros_message.repetitions);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
max_serialized_size_MyCustomServiceMessage_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: radius
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: repetitions
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MyCustomServiceMessage_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyCustomServiceMessage_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyCustomServiceMessage_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyCustomServiceMessage_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MyCustomServiceMessage_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _MyCustomServiceMessage_Request__callbacks = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage_Request",
  _MyCustomServiceMessage_Request__cdr_serialize,
  _MyCustomServiceMessage_Request__cdr_deserialize,
  _MyCustomServiceMessage_Request__get_serialized_size,
  _MyCustomServiceMessage_Request__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomServiceMessage_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyCustomServiceMessage_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>()
{
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)() {
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response & ros_message)
{
  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
get_serialized_size(
  const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_unit_8_services_custom_msgs
max_serialized_size_MyCustomServiceMessage_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _MyCustomServiceMessage_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MyCustomServiceMessage_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MyCustomServiceMessage_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MyCustomServiceMessage_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MyCustomServiceMessage_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _MyCustomServiceMessage_Response__callbacks = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage_Response",
  _MyCustomServiceMessage_Response__cdr_serialize,
  _MyCustomServiceMessage_Response__cdr_deserialize,
  _MyCustomServiceMessage_Response__get_serialized_size,
  _MyCustomServiceMessage_Response__max_serialized_size
};

static rosidl_message_type_support_t _MyCustomServiceMessage_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyCustomServiceMessage_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>()
{
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)() {
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace unit_8_services_custom_msgs
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _MyCustomServiceMessage__callbacks = {
  "unit_8_services_custom_msgs::srv",
  "MyCustomServiceMessage",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)(),
};

static rosidl_service_type_support_t _MyCustomServiceMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MyCustomServiceMessage__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_unit_8_services_custom_msgs
const rosidl_service_type_support_t *
get_service_type_support_handle<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>()
{
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, unit_8_services_custom_msgs, srv, MyCustomServiceMessage)() {
  return &unit_8_services_custom_msgs::srv::typesupport_fastrtps_cpp::_MyCustomServiceMessage__handle;
}

#ifdef __cplusplus
}
#endif
