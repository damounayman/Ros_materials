### 8.1   Service Server

Create a service server that uses the std_srvs/Empty.srv interface. When called, the service will print a LOG-INFO message. we start by:
```bash
touch src/empty_service_server.cpp
```
```cpp
#include <inttypes.h>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"

using Empty = std_srvs::srv::Empty;
rclcpp::Node::SharedPtr g_node = nullptr;

void my_handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<Empty::Request> request,
    const std::shared_ptr<Empty::Response> response)
{
    (void)request_header;
    RCLCPP_INFO(g_node->get_logger(),"My_callback has been called");
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    g_node = rclcpp::Node::make_shared("empty_service_server");
    auto server = g_node->create_service<Empty>("/my_service", my_handle_service);
    rclcpp::spin(g_node);
    rclcpp::shutdown();
    g_node = nullptr;
    return 0;
}
```

Now, we make the necessary changes to the CMakeLists.txt file to compile it. For that, just add these new lines:

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
find_package(std_srvs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(cpp_simple_service_client src/cpp_simple_service_client.cpp)
ament_target_dependencies(cpp_simple_service_client rclcpp std_msgs gazebo_msgs)

add_executable(cpp_simple_service_client_ex7_1_node src/cpp_simple_service_client_ex7_1.cpp)
ament_target_dependencies(cpp_simple_service_client_ex7_1_node rclcpp std_msgs gazebo_msgs)

add_executable(empty_service_server_node src/empty_service_server.cpp)
ament_target_dependencies(empty_service_server_node rclcpp std_msgs std_srvs)

install(TARGETS
   cpp_simple_service_client
   cpp_simple_service_client_ex7_1_node
   empty_service_server_node
   DESTINATION lib/${PROJECT_NAME}
 )

ament_package()
```
Next we make the necessary changes to the package.xml file. In this case, just add this new line:

```xml
<?xml version="1.0"?>
<?xml-model href="http://download.ros.org/schema/package_format2.xsd" schematypens="http://www.w3.org/2001/XMLSchema"?>
<package format="2">
  <name>cpp_unit_7_services</name>
  <version>0.0.0</version>
  <description>TODO: Package description</description>
  <maintainer email="user@todo.todo">user</maintainer>
  <license>TODO: License declaration</license>

  <buildtool_depend>ament_cmake</buildtool_depend>

  <depend>std_msgs</depend>
  <depend>rclcpp</depend>
  <depend>gazebo_msgs</depend>
  <depend>std_srvs</depend>
  

  <test_depend>ament_lint_auto</test_depend>
  <test_depend>ament_lint_common</test_depend>

  <export>
    <build_type>ament_cmake</build_type>
  </export>
</package>
```

And now, we compile the whole cpp_unit_7_services to update the changes.

And let's finnaly execute your new service server:

```bash
$ source .bashrc_ros2
$ ros2 run cpp_unit_7_services empty_service_server_node
```
At the moment, you have just created and started the Service Server. So basically, you have made this service available for anyone to call it.
This means that if you run a ros2 service list, you will be able to visualize this service among the list of available services.

So, let's call the /my_service service manually. 
```bash
$ ros2 service call /my_service std_srvs/Empty '{}'
```

Note

We have to clear up that this is a very simple example. Normally, the request and response variables are used. An example is the delete_model service you used in the previous chapter.

For that case, you were passing the name of the object to delete to the Service Server in a variable called model_name. So. if you want to access the value of that model_name variable in the Service Server, you would have to do it like this:
```
request->model_name
```


## 8.2   How to create your own service interface
the package rosidl_default_generators, is in charge of generating new interfaces in ROS2.
Note that we are calling the function rosidl_generate_interfaces in order to generate the new service interface.
```Cmake
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/MyCustomServiceMessage.srv"
)
```

We needed to add the following dependencies:
```xml
<build_depend>rosidl_default_generators</build_depend>
<exec_depend>rosidl_default_runtime</exec_depend>
<member_of_group>rosidl_interface_packages</member_of_group>
```

### note
VERY IMPORTANT: After the message generation, you have to SOURCE AGAIN. Otherwise, you won't be able to see the messages generated through the ROS2 service commands, and you will think that it didn't work.

To use it, you just have to add the following include in your cpp file:

``` cpp
#include "unit_8_services_custom_msgs/srv/my_custom_service_message.hpp"
```


### Create a service server that uses this custom interface: MyCustomServiceMessage

``` bash
touch src/custom_service_server.cpp
```

``` cpp
#include <inttypes.h>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "unit_8_services_custom_msgs/srv/my_custom_service_message.hpp"

using MyCustomServiceMessage = unit_8_services_custom_msgs::srv::MyCustomServiceMessage;
rclcpp::Node::SharedPtr g_node = nullptr;

void handle_service(
    const std::shared_ptr<rmw_request_id_t> request_header,
    const std::shared_ptr<MyCustomServiceMessage::Request> request,
    const std::shared_ptr<MyCustomServiceMessage::Response> response)
{
    (void)request_header;
    RCLCPP_INFO(g_node->get_logger(),"Incoming request\nradius: %f", request->radius);
    RCLCPP_INFO(g_node->get_logger(),"Incoming request\nrepetitions: %i", request->repetitions);

    response->success = true;
}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    g_node = rclcpp::Node::make_shared("custom_service_server");
    auto server = g_node->create_service<MyCustomServiceMessage>("/my_custom_service", handle_service);
    RCLCPP_INFO(g_node->get_logger(),"CustomServiceServer...READY");
    rclcpp::spin(g_node);
    rclcpp::shutdown();
    g_node = nullptr;
    return 0;
}
``` 

```bash
touch src/custom_service_client.cpp
``` 
``` cpp
#include <chrono>
#include <cinttypes>
#include <iostream>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "unit_8_services_custom_msgs/srv/my_custom_service_message.hpp"

using MyCustomServiceMessage = unit_8_services_custom_msgs::srv::MyCustomServiceMessage;

MyCustomServiceMessage::Response::SharedPtr send_request(
  rclcpp::Node::SharedPtr node,
  rclcpp::Client<MyCustomServiceMessage>::SharedPtr client,
  MyCustomServiceMessage::Request::SharedPtr request)
{

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::executor::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(node->get_logger(),"Client request->radius: %f", request->radius);
    RCLCPP_INFO(node->get_logger(),"Client request->repetitions: %i", request->repetitions);

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

    auto node = rclcpp::Node::make_shared("custom_service_client");
    auto topic = std::string("/my_custom_service");
    auto client = node->create_client<MyCustomServiceMessage>(topic);
    auto request = std::make_shared<MyCustomServiceMessage::Request>();

    //  Fill In The variables of the Custom Service Message
    request->radius = 2.3;
    request->repetitions = 2;

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
    } else {
        RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for response. Exiting.");
    }

    rclcpp::shutdown();
    return 0;
}
```

To run :

``` bash
$ source .bashrc_ros2
$ ros2 run cpp_unit_7_services custom_service_server_node
```

``` bash
$ source .bashrc_ros2
$ ros2 run cpp_unit_7_services custom_service_client_node
```

