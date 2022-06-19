
## table of contents:

- How to structure and launch ROS2 programs (packages and launch files)
- How to create basic ROS2 programs (C++ based)
- Basic ROS2 concepts: Nodes, Client Libraries, etc.

## 2.1   What is ROS2?
ros2 is the keyword used for all the ROS2 commands. For launching programs, you will basically have two options:

- Launch the ROS2 program by directly running the executable file.
- Launch the ROS2 program by starting a launch file.

For directly running an executable file, the structure of the command goes as follows:

```console
ros2 run <package_name> <executable_file>
```

For using a launch file, the structure of the command would go as follows:

```console
ros2 launch <package_name> <launch_file>
```

## 2.2   ROS1 Bridge

the ROS1 Bridge provides a network bridge that enables the exchange of messages between ROS1 and ROS2. This way, we are able to use packages or simulations that are made for ROS1, in ROS2.

## 2.3 package:
ROS uses packages to organize its programs. You can think of a package as all the files that a specific ROS program contains.

- launch folder: Contains launch files
- src folder: Source files (cpp, python)
- CMakeLists.txt: List of cmake rules for compilation
- package.xml: Package information and dependencies

## 2.4   Create a package:

```console
ros2 pkg create <package_name> --build-type ament_cmake --dependencies <package_dependecies>
```

List all avalible package

```console
ros2 pkg list
```

## 2.5   Compile a package

```console
colcon build
```

Sometimes (for example, in large projects) you will not want to compile all of your packages, but just the one(s) where you've made changes. You can do this with the following command:

```console
colcon build --packages-select <package_name>
```

When compilation ends, you will need to source your workspace.

```console
source ~/ros2_ws/install/setup.bash
```

## 2.6 launch file

teleop_twist_keyboard.launch.py
```python
from launch import LaunchDescription
import launch_ros.actions


def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='teleop_twist_keyboard', executable='teleop_twist_keyboard', output='screen'),
    ])

```

Next, we define a function that will return a LaunchDescription object.

## 2.7 ROS2 program
```cpp
// Here we are including all the headers necessary to use the most common public pieces of the ROS system
// In this case we use the rclcpp client library, which provides a C++ Api for interacting with ROS
// Always, when we create a new C++ file, we will need to add this include:
#include "rclcpp/rclcpp.hpp"

// We start the main C++ program
int main(int argc, char * argv[])
{
  // We initiate the rclcpp client library
  rclcpp::init(argc, argv);
  // We initiate a ROS node called test
  auto node = rclcpp::Node::make_shared("test");

  // This is the same as a print in ROS
  RCLCPP_INFO(node->get_logger(), "hello ROS 2"); 
  
  // We shutdown the rclcpp client library
  rclcpp::shutdown();
  // We end our program
  return 0;
}
```

Create a new launch file inside the launch directory.

```console
touch my_package_launch_file.launch.py
chmod +x my_package_launch_file.launch.py
```
```python
from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='my_package', executable='simple_node', output='screen'),
    ])

```

Modify the CMakeLists.txt file to generate an executable from the C++ file you have just created.

In the Build section of your CMakeLists.txt file, add the following lines to your CMakeLists.txt file, right above the ament_package() line.
```cmake
add_executable(simple_node src/simple.cpp)
ament_target_dependencies(simple_node rclcpp)

install(TARGETS
   simple_node
   DESTINATION lib/${PROJECT_NAME}
 )

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
```

 Compile your package as explained previously.

```console
cd ~/ros2_ws;
colcon build
source ~/ros2_ws/install/setup.bash
```
Execute the roslaunch command
 ```console
ros2 launch my_package my_package_launch_file.launch.py
```
**NOTE**: If you create your C++ file from the shell, it may happen that it's created without execution permissions. If this happens, ROS won't be able to find it. If this is the case for you, you can give execution permissions to the file by typing the next command: **chmod +x name_of_the_file.cpp**

## 2.8  Modifying the CMakeLists.txt file
When coding with C++, it will be necessary to create binaries (executables) of your programs in order to be able to execute them. For that, you will need to modify the CMakeLists.txt file of your package, in order to indicate that you want to create an executable of your C++ file.

```cmake
add_executable(simple_node src/simple.cpp)
```
This line generates an executable from the simple.cpp file, which is in the src folder of your package. This executable will be called simple_node.
```cmake
ament_target_dependencies(simple_node rclcpp)
```
This line adds all the ament target dependencies of the executable.
```cmake
install(TARGETS
   simple_node
   DESTINATION lib/${PROJECT_NAME}
 )
 ```

 This snippet will currently install our node (simple_node) into our install space inside the ROS2 workspace. So, this executable will be placed into the package directory of your install space, which is located, by default, at ~/ros2_ws/install/<package name>/lib.

```cmake
 install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
 ```
 Finally, this code snippet will install the launch files into tne install space so that they can be executed using the ros2 launch expression.

 ## 2.9   ROS2 Nodes
```cpp
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("ObiWan");
  // We create a Rate object of 2Hz
  rclcpp::WallRate loop_rate(2);

  // Endless loop until Ctrl + C
  while (rclcpp::ok()) {

    RCLCPP_INFO(node->get_logger(), "Help me Obi-Wan Kenobi, you're my only hope");
    rclcpp::spin_some(node);
    // We sleep the needed time to maintain the Rate fixed above
    loop_rate.sleep();
        
  }
  rclcpp::shutdown();
  return 0;
}
// This program creates an endless loop that repeats itself 2 times per second (2Hz) until somebody presses Ctrl + C
// in the Shell
```
```console
ros2 node info /ObiWan
```

## 2.10   Client Libraries
In the previous exercise, you were using the rclcpp client library. But what is this exactly? Basically, ROS client libraries allow nodes written in different programming languages to communicate. There is a core ROS client library (RCL) that implements the common functionality needed for the ROS APIs of different languages. This makes it so that language-specific client libraries are easier to write and they have more consistent behavior.
The following client libraries are currently maintained by the ROS2 team:

- rclcpp = C++ client library
- rclpy = Python client library

## 2.11   Environment Variables

ROS uses a set of Linux system environment variables in order to work properly. You can check these variables by typing:
```console
export | grep ROS
```
The most important variables are the ROS_MASTER_URI and the ROS_DISTRO.

- ROS_MASTER_URI -> Contains the url where the ROS Core is being executed.
- ROS_DISTRO -> Contains the ROS distribution that you are currently using.


NOTE 1: Since ROS2 doesn't has a roscore, the ROS_MASTER_URI is used here to point to the roscore running in ROS1, when communicating to it using the ROS1 Bridge.