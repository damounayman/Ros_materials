# 11.1   ROS2 Debugging Messages

Logs can be displayed on the screen, but they can also be saved in the ROS frame for sorting, filtering, and other uses. There are logging levels in systems, as seen in the image below. There are five levels in the case of ROS2 logs. Each level has a series of sub-levels. For example, if you use the Error level, the log will display the Error and Fatal messages. If your level is Warning, you'll see all of the messages for the levels Warning, Error, and Fatal.

![](https://s3.eu-west-1.amazonaws.com/notebooks.ws/basic_ROS2_Cpp/img/ros2_log_levels.png)

### Program: logger_example.cpp

```cpp
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("log_demo");
  rclcpp::WallRate loop_rate(0.5);
  rcutils_logging_set_logger_level(node->get_logger().get_name(), RCUTILS_LOG_SEVERITY_DEBUG);

  while (rclcpp::ok()) {

    RCLCPP_DEBUG(node->get_logger(), "There is a missing droid");
    RCLCPP_INFO(node->get_logger(), "The Emperor's cappuccino is done");
    RCLCPP_WARN(node->get_logger(), "Help me Obi-Wan Kenobi, you're my only hope");
    RCLCPP_ERROR(node->get_logger(), "The rebels are breaking our defenses");
    RCLCPP_FATAL(node->get_logger(), "The DeathStar Is EXPLODING");
    rclcpp::spin_some(node);
    loop_rate.sleep();
        
  }
  rclcpp::shutdown();
  return 0;
}
```

## 11.2   Visualize Complex Data and RVIZ2

RVIZ is a visualization tool that lets you view images, pointclouds, lasers, kinematic transformations, robot models, and more. The list goes on and on. It's even possible to create your own markers. It's one of the reasons ROS has been so well received. It wasn't easy to figure out what the robot was seeing before RVIZ. This is the main idea:

- RVIZ is NOT a simulation. I repeat: It's NOT a simulation.
- RVIZ represents what is being published in the topics by the simulation or the real robot.
- RVIZ is a complex tool, and it would take you a whole course to master it.

````bash
rviz2
```