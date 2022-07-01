// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__rosidl_typesupport_introspection_c.h"
#include "unit_8_services_custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__functions.h"
#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__init(message_memory);
}

void MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_fini_function(void * message_memory)
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_member_array[2] = {
  {
    "radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request, radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "repetitions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request, repetitions),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_members = {
  "unit_8_services_custom_msgs__srv",  // message namespace
  "MyCustomServiceMessage_Request",  // message name
  2,  // number of fields
  sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request),
  MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_member_array,  // message members
  MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_type_support_handle = {
  0,
  &MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)() {
  if (!MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_type_support_handle.typesupport_identifier) {
    MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MyCustomServiceMessage_Request__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__rosidl_typesupport_introspection_c.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__functions.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__init(message_memory);
}

void MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_fini_function(void * message_memory)
{
  unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_members = {
  "unit_8_services_custom_msgs__srv",  // message namespace
  "MyCustomServiceMessage_Response",  // message name
  1,  // number of fields
  sizeof(unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response),
  MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_member_array,  // message members
  MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_type_support_handle = {
  0,
  &MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unit_8_services_custom_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)() {
  if (!MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_type_support_handle.typesupport_identifier) {
    MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MyCustomServiceMessage_Response__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "unit_8_services_custom_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_members = {
  "unit_8_services_custom_msgs__srv",  // service namespace
  "MyCustomServiceMessage",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Request_message_type_support_handle,
  NULL  // response message
  // unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_Response_message_type_support_handle
};

static rosidl_service_type_support_t unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_type_support_handle = {
  0,
  &unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_unit_8_services_custom_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage)() {
  if (!unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_type_support_handle.typesupport_identifier) {
    unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unit_8_services_custom_msgs, srv, MyCustomServiceMessage_Response)()->data;
  }

  return &unit_8_services_custom_msgs__srv__detail__my_custom_service_message__rosidl_typesupport_introspection_c__MyCustomServiceMessage_service_type_support_handle;
}
