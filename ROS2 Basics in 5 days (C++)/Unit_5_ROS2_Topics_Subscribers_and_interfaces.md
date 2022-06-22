## 5.1   Topic Subscribers
``` cpp
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
using std::placeholders::_1;

class SimpleSubscriber : public rclcpp::Node
{
public:
  // Initiate a Node called 'simple_subscriber'
  SimpleSubscriber()
  : Node("simple_subscriber")
  {
    // Create a Subscriber object that will listen to the /counter topic and will call the 'topic_callback' function       // each time it reads something from the topic
    subscription_ = this->create_subscription<std_msgs::msg::Int32>(
      "counter", 10, std::bind(&SimpleSubscriber::topic_callback, this, _1));
  }

private:
  // Define a function called 'topic_callback' that receives a parameter named 'msg' 
  void topic_callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    // Print the value 'data' inside the 'msg' parameter
    RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg->data);
  }
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // Create a loop that will keep the program in execution
  rclcpp::spin(std::make_shared<SimpleSubscriber>());
  rclcpp::shutdown();
  return 0;
}
```

This command will publish the message you specify with the value you specify, in the topic you specify.

```bash
ros2 topic pub <topic_name> <message_type> <value>
```


``` cpp
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
using std::placeholders::_1;

class SimpleSubscriber : public rclcpp::Node
{
public:
  // Initiate a Node called 'simple_subscriber'
  SimpleSubscriber()
  : Node("simple_subscriber")
  {
    // Create a Subscriber object that will listen to the /counter topic and will call the 'topic_callback' function       // each time it reads something from the topic
    subscription_ = this->create_subscription<std_msgs::msg::Int32>(
      "counter", 10, std::bind(&SimpleSubscriber::topic_callback, this, _1));
  }

private:
  // Define a function called 'topic_callback' that receives a parameter named 'msg' 
  void topic_callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    // Print the value 'data' inside the 'msg' parameter
    RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg->data);
  }
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // Create a loop that will keep the program in execution
  rclcpp::spin(std::make_shared<SimpleSubscriber>());
  rclcpp::shutdown();
  return 0;
}
```

## 5.2   How to create a custom interface

In order to create a new message, you will need to do the following steps:

- Create a directory named 'msg' inside your package
- Inside this directory, create a file named Name_of_your_message.msg 
- Modify CMakeLists.txt file 
- Modify package.xml file 
- Compile and source
- Use in code

For example, let's create an interface that indicates age, with years, months, and days.

1) Create a directory msg in your package.

    ```bash
   cd ~/ros2_ws/src/<package_name>
   mkdir msg
    ```

2) The Age.msg file must contain this:

```bash
float32 years
float32 months
float32 days
```

3) In CMakeLists.txt

You will have to edit two functions inside CMakeLists.txt:

- find_package()
- rosidl_generate_interfaces()

I. find_package()
This is where all the packages required to COMPILE the messages of the topics, services, and actions go. In package.xml, you have to state them as build_depend and exec_depend.

```bash	
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
```

II. rosidl_generate_interfaces()
This function includes all of the messages of this package (in the msg folder) to be compiled. The function should look like this.
```bash	
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Age.msg"
)
```

4) Modify package.xml

Add the following lines to the package.xml file.

```xml	
<build_depend>rosidl_default_generators</build_depend>

<exec_depend>rosidl_default_runtime</exec_depend>

<member_of_group>rosidl_interface_packages</member_of_group>
```

**VERY IMPORTANT**: When you compile new messages, there is still an extra step before you can use the messages. You have to type in the Webshell, in the **ros2_ws**, the following command: **source install/setup.bash**.

This executes this bash file that sets, among other things, the newly generated messages created through the colcon build.

If you don't do this, it might give you an import error, saying it doesn't find the message generated.

```bash
ros2 interface show topic_subscriber_pkg/msg/Age
```

## Topics Mini Project

```bash
ros2 pkg create Mini_Project_1 --build-type ament_cmake --dependencies rclcpp std_msgs geometry_msgs sensor_msgs
```
