## 4.1   Topic Publishers

Remember, in order to create a package with roscpp and std_msgs as dependencies, you should use a command like the one below:

```console
ros2 pkg create topic_publisher_pkg --build-type ament_cmake --dependencies rclcpp std_msgs
```
 The lines to add into the CmakeLists.txt file could be something like this:

```cmake
add_executable(simple_publisher_node src/simple_topic_publisher.cpp)
ament_target_dependencies(simple_publisher_node rclcpp std_msgs)

install(TARGETS
   simple_publisher_node
   DESTINATION lib/${PROJECT_NAME}
 )

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
```

```cpp
// Import all the necessary ROS libraries and import the Int32 message from the std_msgs package
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  // Initiate a Node named 'simple_publisher'
  auto node = rclcpp::Node::make_shared("simple_publisher");
  // Create a Publisher object that will publish on the /counter topic, messages of the type Int32
  // The 10 indicates the size of the queue
  auto publisher = node->create_publisher<std_msgs::msg::Int32>("counter", 10);
  // Create a variable named 'message' of type Int32
  auto message = std::make_shared<std_msgs::msg::Int32>();
  // Initialize the 'message' variable
  message->data = 0;
  // Set a publish rate of 2 Hz
  rclcpp::WallRate loop_rate(2);

  // Create a loop that will go until someone stops the program execution
  while (rclcpp::ok()) {
    
    // Publish the message within the 'message' variable
    publisher->publish(*message);
    // Increment the 'message' variable
    message->data++;
    rclcpp::spin_some(node);
    // Make sure the publish rate maintains at 2 Hz
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
```


To get a list of available topics in a ROS system, you have to use the following command:

```console
ros2 topic list
```

To read the information that is being published in a topic, use the following command:
```console
ros2 topic echo <topic_name>
```

To get information about a certain topic, use the following command:
```console
ros2 topic info <topic_name>
```

you can check the different options that rostopic command has by using the following command:
```console
ros2 topic -h
```

## 4.2   Node Composition
In ROS2, as a notable difference from ROS1, the concept of Composition is introduced. Basically, this means that you will have the ability to compose (execute) multiple nodes in a single process. You will learn more about node composition in following units.

In order to be able to use node composition, though, you will need to program your scripts in a more object-oriented way. 

Below, you can have a look at a script that does exactly the same thing, but it is coded using a composable method, using classes.

```cpp
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include <chrono>

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */
// First, we define our class, which inherits from the rclcpp::Node class.
class SimplePublisher : public rclcpp::Node
{
public:
//he constructor of our class
 //we are initializing our node by calling to the constructor of the superclass Node, and also initializing a variable named count_ to 0.
  SimplePublisher()
  : Node("simple_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("counter", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&SimplePublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = std_msgs::msg::Int32();
    message.data = count_;
    count_++;
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimplePublisher>());
  rclcpp::shutdown();
  return 0;
}

```

In the private section, we have the definition of the timer_callback function we introduced before. Inside this function, we are creating an Int32 message, which is given the value of the count_ variable. Then, we are going to increase the value of the count variable in 1, and we are going to publish the message into our topic. Remember that this function will be called every 500ms, as defined in the timer_ object.

Also in the private section, we are creating the shared pointers to our publisher and timer objects defined above, and we are also creating the variable count.

## 4.3   Messages (interfaces)
Interfaces for topics are defined in .msg files, which are located inside a msg directory of a package.

To get information about an interface, use the following command:

```console
ros2 interface show <message>
```