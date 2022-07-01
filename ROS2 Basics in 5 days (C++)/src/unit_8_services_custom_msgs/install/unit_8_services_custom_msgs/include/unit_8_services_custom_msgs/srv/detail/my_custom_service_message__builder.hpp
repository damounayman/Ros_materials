// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__BUILDER_HPP_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__BUILDER_HPP_

#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace unit_8_services_custom_msgs
{

namespace srv
{

namespace builder
{

class Init_MyCustomServiceMessage_Request_repetitions
{
public:
  explicit Init_MyCustomServiceMessage_Request_repetitions(::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request & msg)
  : msg_(msg)
  {}
  ::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request repetitions(::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request::_repetitions_type arg)
  {
    msg_.repetitions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request msg_;
};

class Init_MyCustomServiceMessage_Request_radius
{
public:
  Init_MyCustomServiceMessage_Request_radius()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MyCustomServiceMessage_Request_repetitions radius(::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return Init_MyCustomServiceMessage_Request_repetitions(msg_);
  }

private:
  ::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>()
{
  return unit_8_services_custom_msgs::srv::builder::Init_MyCustomServiceMessage_Request_radius();
}

}  // namespace unit_8_services_custom_msgs


namespace unit_8_services_custom_msgs
{

namespace srv
{

namespace builder
{

class Init_MyCustomServiceMessage_Response_success
{
public:
  Init_MyCustomServiceMessage_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response success(::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>()
{
  return unit_8_services_custom_msgs::srv::builder::Init_MyCustomServiceMessage_Response_success();
}

}  // namespace unit_8_services_custom_msgs

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__BUILDER_HPP_
