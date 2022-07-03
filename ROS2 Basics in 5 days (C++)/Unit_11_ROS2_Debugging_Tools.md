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

```bash
rviz2
```



```bash
ros2 topic pub /cmd_vel geometry_msgs/msg/Twist "linear:
  x: 0.2
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.2
"
```

## 11.3   tf2_tools view_frames


Another very useful tool is the view_frames program. This program allows you to visualize a tree diagram showing you the relationship between the different frames of your robot.

To execute it, perform the following steps:

```bash
ros2 run tf2_tools view_frames.py
```

![](https://s3.eu-west-1.amazonaws.com/notebooks.ws/basic_ROS2_Cpp/img/frames-tree.png)

This tool is useful because it allows you to see the connection between each frame and determine if a transform is not well executed. For example, there may be no relationship between a generated map and the robot that wants to navigate, or a sensor and its base, etc

## 11.4   ROS2 Doctor

What happens when your ROS2 setup is not working as expected? Here you use ROS2's great tool, ros2 doctor.

This powerful tool reviews the total ROS2 setup from the platform, versions, network, environment, etc. In addition to giving you a proper diagnosis with precautions, errors, and possible reasons for problems.

Don't forget that ros2doctor belongs to the ros2cli package, so you will need to have it installed to use it.

### 11.4.1   Check Your Entire Setup

This is the first and most significant level of ros2doctor tool checking. You only need to execute ros2 doctor.

```bash
ros2 doctor
```

If the ROS2 setup is in perfect shape, it will pass all checks as stated in the last line of output in the shell.

You can disregard the UserWarning messages. Don't worry about it. It means that something is not configured as a default or in the ideal way or maybe the last version. 

### 11.4.3   Get a Full Report with ROS2 Doctor

If you want to know more details to analyze issues, a --report is the best option.

To get a full report, run the following command:

```bash
ros2 doctor --report
```

You will see that the report is categorized into six sections:

- NETWORK CONFIGURATION
- PACKAGE VERSION
- PLATFORM CONFIGURATION
- RMW MIDDLEWARE
- ROS 2 INFORMATION
- TOPIC LIST

Let's review each category:

### NETWORK CONFIGURATION
You can see all the information related to the system's network configuration.

### PACKAGE VERSION
These are packages that can be updated to the last version.

### PLATFORM CONFIGURATION

This is information about the platform you are using.


### RMW MIDDLEWARE

This is information about the RMW MIDDLEWARE that defines an interface of middleware primitives used by the higher level ROS API's. 

### ROS2 INFORMATION

This is information about the ROS2 that you are using.

### TOPIC LIST

This is information about the topics that are working with the subscribers and publishers.





