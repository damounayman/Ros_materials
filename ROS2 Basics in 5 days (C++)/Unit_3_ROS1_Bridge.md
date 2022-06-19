## 3.1   Setup of ROS1 Bridge
Ros1-Bridge connects messages from ROS1 and ROS2. The prebuilt version supports some messages, and most of the ROS core messages used.

This mapping between messages from ROS1-ROS2 is defined at compile time through yaml files exported in the package.xml. More info on this Mapping Topic: https://github.com/ros2/ros1_bridge/blob/master/doc/index.rst

But in this course, we will concentrate on using only the default messages for the time being.

## 3.1.1   ROS1-Bridge sourcing
The first thing to do is to create a custom bridge bashrc configuration to be able to source both the ROS1 and ROS2 systems that ROS1-Bridge needs.


ROS1-Bridge is based on several concepts, but the most basic one is the fact that the shell where you launch ROS1-Bridge has to have sourced, all the paths to all the messages that it has access to. This means that it has to be able to reach both ROS1 and ROS2 message definitions. That's why both melodic and dashing are sourced, to be able to reach ROS1 and ROS2 system installed packages. And also, it has to be able to reach any workspace that you might use. In this case, the catkin_ws for ROS1 and ros2_ws for ROS2.

```console
cat /home/user/.bashrc_bridge
```

```console
source /opt/ros/noetic/setup.bash
source /opt/ros/foxy/local_setup.bash
source /home/simulations/ros2_sims_ws/install/setup.bash
source /home/user/catkin_ws/devel/setup.bash
source /home/user/ros2_ws/install/local_setup.bash
```

```console
ros2 run ros1_bridge dynamic_bridge
```

Once ros1_bridge is correctly sourced, it basically checks if the topics and services in ROS1 and ROS2 have the same names, message types, and so on. If so, it connects the corresponding topics and services.

## 3.2   Basic Examples

```console
ros2 topic pub /cmd_vel geometry_msgs/Twist "{linear:{x: 0.0,y: 0.0,z: 0.0}, angular:{x: 0.0,y: 0.0,z: 1.0}}"
```
Reset Simulation service through ROS2

```console
ros2 service call /gazebo/reset_simulation std_srvs/Empty '{}'
```

## 3.4   Additional Notes

With the default bridge configuration, `ros2 run ros1_bridge dynamic_bridge', topics are only bridged when a publisher-subscriber connection is detected for the topic.

if you try to echo a specific topic from ros 1, you won't be able to access to the data:

ros2 topic echo /odom

As you can see from the WARNING message above, you cannot access the data because ROS2 is not able to identify which type (message) the /odom topic uses. You can fix this by specifying the type of the topic.

```console
ros2 topic echo /odom nav_msgs/Odometry
```

Also, you have the option to automatically bridge all the topics without having to wait for a publisher-subscriber connection to be created. You can do this with the following command:

```console
ros2 run ros1_bridge dynamic_bridge --bridge-all-topics
```