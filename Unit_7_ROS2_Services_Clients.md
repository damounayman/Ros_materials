## 7.1   Topics - Services - Actions

Services are based on a client-server (call-and-response) communication model. This means that a service will ONLY be executed when it is specifically called.

Topics, on the other hand, are based on a publish-subscribe model. This means that they will work with continuous flows of data.

 Use services when your program doesn't require to be executed contiuously.

## ROS2 and Services Examples


We will do the following:

        - Go over the different commands for ROS2 services.
        - Talk about limitations of ROS1-Bridge and how to circumvent them.
        - Call through commands the Robot service to delete a model in ROS2.
        - Create a dummy-Service-Server for ROS2.
        - Create a client for the dummy_Service-Server for ROS2 to Delete a model.
        - Modify the client for the dummy_Service-Server for ROS2, to call the real Robot service to delete a model.

7.2   Command Line Tools
ROS2, at the time of the creation of this tutorial, supports the following commands for services and its messages:

- ros2 service list: Lists all the services currently running in the system
- ros2 service call: Calls a certain service currently available
- ros2 interface list: Lists all the Service messages available
- ros2 interface package: Lists all the service messages from a package
- ros2 interface packages: Lists all the available packages that have service messages defined inside them.
- ros2 interface show: Gets the structure of a certain service message

## 7.2.1   ros2 service list
In the next examples we will interact with a ROS1 service provided by Gazebo named /gazebo/delete_model. Therefore, because it's a ROS1 Gazebo service, we will need ROS1-Bridge to interact with it.

Remember that whenever you interact with ROS1, you need to launch ROS1-Bridge.

```bash
$ source .bashrc_bridge
$ ros2 run ros1_bridge dynamic_bridge
```
With this command, you can get all the services running now.
```bash
# Get all the services currently running
$ source .bashrc_ros2
$ ros2 service list
```

## 7.2.2   ros2 service call
The command used in ROS2 to call service is ros2 service call. The structure of this command is the following:
```bash
ros2 service call <service_name> <service_interface> <value>
```

Let's call the /gazebo/delete_model service:
```bash
# Call A Service Server
$ source .bashrc_ros2
$ ros2 service call /gazebo/delete_model gazebo_msgs/DeleteModel '{model_name: bowl_1}'
```

## 7.2.3   ros2 interface list

Here we list the Service interfaces available for use in ROS2.
```bash
# List all available service messages in the system
$ source .bashrc_ros2
$ ros2 interface list | grep srv
```

## 7.2.4   ros2 interface package

```bash
# List all the messages defined in a certain package
$ source .bashrc_ros2
$ ros2 interface package gazebo_msgs
```

```bash
# List all the messages defined in a certain package
$ source .bashrc_ros2
$ ros2 interface show gazebo_msgs/srv/DeleteModel
```


Note: As you can see in the comment, the DeleteModel message has been substituted in ROS2 by the DelteEntity message. However, we will use the old version within this example, since the simulation we are working with it's still based in ROS1.

## 7.3   Service interfaces
Does the structure of this DeleteModel message look familiar to you? It should, because it's the same structure as with topic interfaces, with some add-ons.

Service Message Properties:
Service messages have the extension .srv. Remember that topic messages have the extension .msg
Service messages are defined inside a srv directory, instead of a msg directory.
Service messages have TWO parts:
```yaml
**REQUEST**


---
**RESPONSE**`
```

In the case of the DeleteModel service, **REQUEST** contains a string called model_name and **RESPONSE** is composed of a boolean named success, and a string named status_message.

```yaml
# Deprecated, kept for ROS 1 bridge.
# Use DeleteEntity
string model_name                 # name of the Gazebo Model to be deleted
---
bool success                      # return true if deletion is successful
string status_message    
```

The number of elements on each part of the service message can vary depending on the service needs. You can even put none if you find that it is irrelevant for your service. The important part of the message is the three dashes ---, because they define the file as a Service Message.


## Summarizing:

The **REQUEST** is the part of the service message that defines HOW you will do a call to your service. This means, what variables you will have to pass to the Service Server so that it is able to complete its task.

The **RESPONSE** is the part of the service message that defines HOW your service will respond after completing its functionality. For instance, it will return a string with a certain message saying that everything went well, or it will return nothing, etc...

## 7.4   Create a Service Client

- Create a ROS2 package
```bash
$ source .bashrc_ros2
$ cd ~/ros2_ws/src
$ ros2 pkg create cpp_unit_7_services --build-type ament_cmake --dependencies std_msgs rclcpp gazebo_msgs
```

Note that if the original service message name was DeleteModel.srv, the generated hpp file for the messages will be named delete_model.hpp. If you had MyCustomService.srv, it would be my_custom_service.hpp, and so on.

```cpp
#include <chrono>
#include <cinttypes>
#include <iostream>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "gazebo_msgs/srv/delete_model.hpp"


gazebo_msgs::srv::DeleteModel::Response::SharedPtr send_request(
  rclcpp::Node::SharedPtr node,
  rclcpp::Client<gazebo_msgs::srv::DeleteModel>::SharedPtr client,
  gazebo_msgs::srv::DeleteModel::Request::SharedPtr request)
{

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::executor::FutureReturnCode::SUCCESS)
  {

    RCLCPP_INFO(node->get_logger(), "Client request->model_name : %s", request->model_name.c_str());
    return result.get();
  } else {
    RCLCPP_ERROR(node->get_logger(), "service call failed :(");
    return NULL;
  }

}

int main(int argc, char ** argv)
{
    // Force flush of the stdout buffer.
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("cpp_simple_service_client");
    auto topic = std::string("/gazebo/delete_model");
    auto client = node->create_client<gazebo_msgs::srv::DeleteModel>(topic);
    auto request = std::make_shared<gazebo_msgs::srv::DeleteModel::Request>();

    //  Fill the variable model_name of this object with the desired value
    request->model_name = "bowl_2";

    while (!client->wait_for_service(std::chrono::seconds(1))) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(node->get_logger(), "service not available, waiting again...");
    }

    auto result = send_request(node, client, request);
    if (result) {

        auto result_str = result->success ? "True" : "False";

        RCLCPP_INFO(node->get_logger(), "Result-Success : %s", result_str);
        RCLCPP_INFO(node->get_logger(), "Result-Status: %s", result->status_message.c_str());
    } else {
        RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for response. Exiting.");
    }

    rclcpp::shutdown();
    return 0;
}
```

Now, we make the necessary changes to the CMakeLists.txt file in order to compile the client code and install the executable in our workspace.


```Cmake
cmake_minimum_required(VERSION 3.5)
project(cpp_unit_7_services)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(gazebo_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # remove the line when a copyright and license is present in all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # remove the line when this package is a git repo
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(cpp_simple_service_client src/cpp_simple_service_client.cpp)
ament_target_dependencies(cpp_simple_service_client rclcpp std_msgs gazebo_msgs)

install(TARGETS
   cpp_simple_service_client
   DESTINATION lib/${PROJECT_NAME}
 )


ament_package()
```