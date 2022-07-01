// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from unit_8_services_custom_msgs:srv/MyCustomServiceMessage.idl
// generated code does not contain a copyright notice

#ifndef UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_HPP_
#define UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request __attribute__((deprecated))
#else
# define DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request __declspec(deprecated)
#endif

namespace unit_8_services_custom_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyCustomServiceMessage_Request_
{
  using Type = MyCustomServiceMessage_Request_<ContainerAllocator>;

  explicit MyCustomServiceMessage_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
      this->repetitions = 0l;
    }
  }

  explicit MyCustomServiceMessage_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radius = 0.0;
      this->repetitions = 0l;
    }
  }

  // field types and members
  using _radius_type =
    double;
  _radius_type radius;
  using _repetitions_type =
    int32_t;
  _repetitions_type repetitions;

  // setters for named parameter idiom
  Type & set__radius(
    const double & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__repetitions(
    const int32_t & _arg)
  {
    this->repetitions = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Request
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyCustomServiceMessage_Request_ & other) const
  {
    if (this->radius != other.radius) {
      return false;
    }
    if (this->repetitions != other.repetitions) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyCustomServiceMessage_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyCustomServiceMessage_Request_

// alias to use template instance with default allocator
using MyCustomServiceMessage_Request =
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace unit_8_services_custom_msgs


#ifndef _WIN32
# define DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response __attribute__((deprecated))
#else
# define DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response __declspec(deprecated)
#endif

namespace unit_8_services_custom_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MyCustomServiceMessage_Response_
{
  using Type = MyCustomServiceMessage_Response_<ContainerAllocator>;

  explicit MyCustomServiceMessage_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MyCustomServiceMessage_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__unit_8_services_custom_msgs__srv__MyCustomServiceMessage_Response
    std::shared_ptr<unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MyCustomServiceMessage_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MyCustomServiceMessage_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MyCustomServiceMessage_Response_

// alias to use template instance with default allocator
using MyCustomServiceMessage_Response =
  unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

namespace unit_8_services_custom_msgs
{

namespace srv
{

struct MyCustomServiceMessage
{
  using Request = unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Request;
  using Response = unit_8_services_custom_msgs::srv::MyCustomServiceMessage_Response;
};

}  // namespace srv

}  // namespace unit_8_services_custom_msgs

#endif  // UNIT_8_SERVICES_CUSTOM_MSGS__SRV__DETAIL__MY_CUSTOM_SERVICE_MESSAGE__STRUCT_HPP_
