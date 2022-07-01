// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__TRAITS_HPP_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__TRAITS_HPP_

#include "unit_8_services_custom_msgs/srv/detail/my_custom_service_message__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>()
{
  return "unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request";
}

template<>
inline const char * name<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>()
{
  return "unit_8_services_custom_msgs/srv/MyCustomServiceMessage_Request";
}

template<>
struct has_fixed_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>()
{
  return "unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response";
}

template<>
inline const char * name<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>()
{
  return "unit_8_services_custom_msgs/srv/MyCustomServiceMessage_Response";
}

template<>
struct has_fixed_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>()
{
  return "unit_8_services_custom_msgs::srv::MyCustomServiceMessage";
}

template<>
inline const char * name<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>()
{
  return "unit_8_services_custom_msgs/srv/MyCustomServiceMessage";
}

template<>
struct has_fixed_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>
  : std::integral_constant<
    bool,
    has_fixed_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>::value &&
    has_fixed_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>::value
  >
{
};

template<>
struct has_bounded_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>
  : std::integral_constant<
    bool,
    has_bounded_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>::value &&
    has_bounded_size<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>::value
  >
{
};

template<>
struct is_service<unit_8_services_custom_msgs::srv::MyCustomServiceMessage>
  : std::true_type
{
};

template<>
struct is_service_request<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request>
  : std::true_type
{
};

template<>
struct is_service_response<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__TRAITS_HPP_
