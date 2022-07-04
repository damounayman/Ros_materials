Unit 9   ROS2 Actions: Clients

## 9.1   What are actions?

Actions are very similar to services. When you call an action, you are calling a functionality that another node is providing. Also, actions are based on a client-server model. Just the same as with services.

However, there are 2 main differences between actions and services:

- First, actions are preemptable. This means that you can cancel an action while it is being executing.

- Second, actions provide feedback. This means that, while the action is being executed, the server can send feedback back to the client.

Below you can see a diagram that describes the workflow of an action.

![](https://s3.eu-west-1.amazonaws.com/notebooks.ws/basic_ROS2_Cpp/img/ros2_actions_diagram.png)


- The node that provides the action functionality has to contain an action server. The action server allows other nodes to call that action functionality.
- The node that calls to the action functionality has to contain an action client. The action client allows a node to connect to the action server of another node.

In order to find which actions are available on a robot, you must use the command ros2 action list.

```bash
ros2 action list
```

```bash
ros2 action info /turtlebot3_as -t
```

```bash
ros2 interface show t3_action_msg/action/Move
```

In order to call an action server, you can use the command ros2 action send_goal. The structure of the command is the following:

```bash
ros2 action send_goal <action_name> <action_type> <values>
```

```bash
ros2 action send_goal /turtlebot3_as t3_action_msg/action/Move "{secs: 5}"
```

To get feedback : 

```bash
ros2 action send_goal -f /turtlebot3_as t3_action_msg/action/Move "{secs: 5}"
```
Note the "-f" argument added to the command.

## 9.2   Calling an action server:


Calling an action server means sending a message to it. In the same way as with topics and services, it all works by passing messages around.

- The message of a topic is composed of a single part: the information the topic provides.
- The message of a service has two parts: the request and the response.
- The message of an action server is divided into three parts: the goal, the result, and the feedback.

All of the action messages used are defined in the action directory of their package.

### 9.2.1   Actions provide feedback