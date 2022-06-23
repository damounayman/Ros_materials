 ## What are ROS2 components?

 Components are the equivalent in ROS2 to well-known ROS1 nodelets. By writing our program as a component, we can build it into a shared library instead of an executable. This allows us to load multiple components into a single process. Quite interesting, right?

However, in order to be able to use composition, you need to write your programs in a specific way, as you have already seen in previous units. In order to better understand how composition works, let's follow an example with the programs you created in unit 2.


## Creating a component

Let's start by creating a new package, where we will create our components:

```bash
$ source /opt/ros/foxy/setup.bash
$ cd ~/ros2_ws/src
```

```
$ ros2 pkg create my_components --build-type ament_cmake --dependencies rclcpp rclcpp_components composition geometry_msgs
```

we need to add dependencies to the rclcpp_components and composition packages.


First of all, you will have to create an hpp file to define your class. Inside the include/my_components folder of the package, create a new file named moverobot_component.hpp and paste the below code to it:


```hpp
#ifndef COMPOSITION__MOVEROBOT_COMPONENT_HPP_
#define COMPOSITION__MOVEROBOT_COMPONENT_HPP_

#include "my_components/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

namespace my_components
{

class MoveRobot : public rclcpp::Node
{
public:
  COMPOSITION_PUBLIC
  explicit MoveRobot(const rclcpp::NodeOptions & options);

protected:
  void on_timer();

private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}  // namespace composition

#endif  // COMPOSITION__MOVEROBOT_COMPONENT_HPP_
```


As you can see, in this file we are just defining the different variables and functions that we will us in our MoveRobot class. Note also that we are encapsulating everything inside a my_components namespace.

Next we will create our program. Inside the src folder of the package, create a new script named moverobot_component.cpp, and paste the below code into it:


```cpp
#include "my_components/moverobot_component.hpp"

#include <chrono>
#include <iostream>
#include <memory>
#include <utility>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

namespace my_components
{
MoveRobot::MoveRobot(const rclcpp::NodeOptions & options)
: Node("moverobot", options)
{
  
  pub_ = create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

  timer_ = create_wall_timer(1s, std::bind(&MoveRobot::on_timer, this));
}

void MoveRobot::on_timer()
{
  auto msg = std::make_unique<geometry_msgs::msg::Twist>();
  msg->linear.x = 0.3;
  msg->angular.z = 0.3;
  std::flush(std::cout);

  pub_->publish(std::move(msg));
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(my_components::MoveRobot)
```


Let's point out the most important parts of the code.

First, we are importing the .hpp file we just created:

```cpp
#include "my_components/moverobot_component.hpp"
```

Note that we are also encapsulating everything inside the my_components namespace:
```cpp
namespace my_components
{   
}
```

Finally, we register our program as a component:

```cpp
include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(my_components::MoveRobot)
```



Note that, since a component is only built into a shared library, it doesn’t have a main function.


Let's now create another file, also inside the include/my_components folder, named visibility_control.h. Copy the code shown below.

```h
// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COMPOSITION__VISIBILITY_CONTROL_H_
#define COMPOSITION__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define COMPOSITION_EXPORT __attribute__ ((dllexport))
    #define COMPOSITION_IMPORT __attribute__ ((dllimport))
  #else
    #define COMPOSITION_EXPORT __declspec(dllexport)
    #define COMPOSITION_IMPORT __declspec(dllimport)
  #endif
  #ifdef COMPOSITION_BUILDING_DLL
    #define COMPOSITION_PUBLIC COMPOSITION_EXPORT
  #else
    #define COMPOSITION_PUBLIC COMPOSITION_IMPORT
  #endif
  #define COMPOSITION_PUBLIC_TYPE COMPOSITION_PUBLIC
  #define COMPOSITION_LOCAL
#else
  #define COMPOSITION_EXPORT __attribute__ ((visibility("default")))
  #define COMPOSITION_IMPORT
  #if __GNUC__ >= 4
    #define COMPOSITION_PUBLIC __attribute__ ((visibility("default")))
    #define COMPOSITION_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define COMPOSITION_PUBLIC
    #define COMPOSITION_LOCAL
  #endif
  #define COMPOSITION_PUBLIC_TYPE
#endif

#ifdef __cplusplus
}
#endif

#endif  // COMPOSITION__VISIBILITY_CONTROL_H_
```


Basically, this file will optimize the loading process of shared libraries. If you'd like to get more details about this file, have a look at: https://gcc.gnu.org/wiki/Visibility

Let's then modify the CMakeLists.txt file in order to generate the proper shared library from the component you have just created.


```Cmake
include_directories(include)

add_library(moverobot_component SHARED src/moverobot_component.cpp)
target_compile_definitions(moverobot_component PRIVATE "COMPOSITION_BUILDING_DLL")
ament_target_dependencies(moverobot_component
  "rclcpp"
  "rclcpp_components"
  "geometry_msgs")
rclcpp_components_register_nodes(moverobot_component "my_components::MoveRobot")
set(node_plugins "${node_plugins}my_components::MoveRobot;$<TARGET_FILE:moverobot_component>\n")

install(TARGETS
  moverobot_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
  ```


  Let's point out the most important parts of the code.

First we generate the shared library from our C++ script:

```Cmake
add_library(moverobot_component SHARED src/moverobot_component.cpp)
  ```

We register our component:
  ```Cmake
rclcpp_components_register_nodes(moverobot_component "my_components::MoveRobot")
set(node_plugins "${node_plugins}my_components::MoveRobot;$<TARGET_FILE:moverobot_component>\n")
```

And finally we install it into our workspace:
```Cmake
install(TARGETS
  moverobot_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
  ```

  In order to check if the component has been created successfully, you can use the command ros2 component types. This command will retur a list with all the available components:

Verify that the component has been created successfully:
```bash
ros2 component types
  ```

  In order to be able to load a component, you have to first start the component container. Execute the following command:
```bash
  ros2 run rclcpp_components component_container
   ```

   Now, we can verify that the container is running with the following command:
```bash
   ros2 component list
```

Alright! Everything is set up, so let's load our component. Execute the following command: