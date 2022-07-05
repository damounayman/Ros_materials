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

Due to the fact that calling an action server does not interrupt your thread, action servers provide a message called the feedback. The feedback is a message that the action server generates every once in a while to indicate how the action is going (informing the caller of the status of the requested action). It is generated while the action is in progress.

### 9.2.2   How to call an action server

let's create a new package where we'll place our action client code.

```bash
$ cd ~/ros2_ws/src
$ ros2 pkg create my_action_client --build-type ament_cmake --dependencies rclcpp rclcpp_action t3_action_msg
```


```cpp
#include <inttypes.h>
#include <memory>
#include <string>
#include <iostream>

#include "t3_action_msg/action/move.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

class T3ActionClient : public rclcpp::Node
{
public:
  using Move = t3_action_msg::action::Move;
  using GoalHandleMove = rclcpp_action::ClientGoalHandle<Move>;

  explicit T3ActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("t3_action_client", node_options), goal_done_(false)
  {
    this->client_ptr_ = rclcpp_action::create_client<Move>(
      this->get_node_base_interface(),
      this->get_node_graph_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "turtlebot3_as");

    this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&T3ActionClient::send_goal, this));
  }

  bool is_goal_done() const
  {
    return this->goal_done_;
  }

  void send_goal()
  {
    using namespace std::placeholders;

    this->timer_->cancel();

    this->goal_done_ = false;

    if (!this->client_ptr_) {
      RCLCPP_ERROR(this->get_logger(), "Action client not initialized");
    }

    if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
      this->goal_done_ = true;
      return;
    }

    auto goal_msg = Move::Goal();
    goal_msg.secs = 5;

    RCLCPP_INFO(this->get_logger(), "Sending goal");

    auto send_goal_options = rclcpp_action::Client<Move>::SendGoalOptions();
    send_goal_options.goal_response_callback =
      std::bind(&T3ActionClient::goal_response_callback, this, _1);
    send_goal_options.feedback_callback =
      std::bind(&T3ActionClient::feedback_callback, this, _1, _2);
    send_goal_options.result_callback =
      std::bind(&T3ActionClient::result_callback, this, _1);
    auto goal_handle_future = this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
  }

private:
  rclcpp_action::Client<Move>::SharedPtr client_ptr_;
  rclcpp::TimerBase::SharedPtr timer_;
  bool goal_done_;

  void goal_response_callback(std::shared_future<GoalHandleMove::SharedPtr> future)
  {
    auto goal_handle = future.get();
    if (!goal_handle) {
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
  }

  void feedback_callback(
    GoalHandleMove::SharedPtr,
    const std::shared_ptr<const Move::Feedback> feedback)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Feedback received: " +
      feedback->feedback);
  }

  void result_callback(const GoalHandleMove::WrappedResult & result)
  {
    this->goal_done_ = true;
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Result received: " + result.result->status);
    //for (auto res : result.result->status) {
    //  RCLCPP_INFO(this->get_logger(), res);
    //}
  }
};  // class T3ActionClient

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto action_client = std::make_shared<T3ActionClient>();

  while (!action_client->is_goal_done()) {
    rclcpp::spin_some(action_client);
  }

  rclcpp::shutdown();
  return 0;
}
```

### 9.2.3   Action Client code explanation
As always, we start by creating a class, which inherits from the Node class:

```cpp
class T3ActionClient : public rclcpp::Node
```

Next we define the 2 most important interfaces that we will use in the action client:

```cpp
using Move = t3_action_msg::action::Move;
using GoalHandleMove = rclcpp_action::ClientGoalHandle<Move>;
```

Move, as you already know, will contain the action interface.
GoalHandleMove, as the name indicates, will be in charge of handling the goal message from Move.

Next we are initializing the node of our program. As you can see, the node name is t3_action_client:
```cpp
explicit T3ActionClient(const rclcpp::NodeOptions & node_options = rclcpp::NodeOptions())
  : Node("t3_action_client", node_options), goal_done_(false)
```
Right below we create the action client:

```cpp
this->client_ptr_ = rclcpp_action::create_client<Move>(
      this->get_node_base_interface(),
      this->get_node_graph_interface(),
      this->get_node_logging_interface(),
      this->get_node_waitables_interface(),
      "turtlebot3_as");
```

We also create a timer:

```cpp
this->timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&T3ActionClient::send_goal, this));
```

When the time expires (500ms), the timer will call the function send_goal().

Within this send_goal() function we are doing several things. Let's start by the beginning:

```cpp
this->goal_done_ = false;

if (!this->client_ptr_) {
  RCLCPP_ERROR(this->get_logger(), "Action client not initialized");
}

if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) {
  RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
  this->goal_done_ = true;
  return;
}
```

First of all we set the goal_done_ variable to false. This variable will help us to know when the action has finished. Also, we check if the action server is up and running, to make sure that it is able to receive goals.

Right below, we specify the goal message to be sent to the server:


```cpp
auto goal_msg = Move::Goal();
goal_msg.secs = 5;

RCLCPP_INFO(this->get_logger(), "Sending goal");
```

As you can see, we are specifying 5 seconds in the goal message. That's why in the previous exercise the robot moves forward for 5 seconds.

Next we are defining 3 important functions: goal_response_callback, feedback_callback and result_callback. We will see in a moment what they are for.

```cpp
auto send_goal_options = rclcpp_action::Client<Move>::SendGoalOptions();
send_goal_options.goal_response_callback =
  std::bind(&T3ActionClient::goal_response_callback, this, _1);
send_goal_options.feedback_callback =
  std::bind(&T3ActionClient::feedback_callback, this, _1, _2);
send_goal_options.result_callback =
  std::bind(&T3ActionClient::result_callback, this, _1);
```
And finally, we send the goal to the server:

```cpp
auto goal_handle_future = this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
```

When the action server receives and accepts the goal sent from the client, it will send a response back to the client The goal_response_callback function is in charge of dealing with this response:

```cpp
void goal_response_callback(std::shared_future<GoalHandleMove::SharedPtr> future)
  {
    auto goal_handle = future.get();
    if (!goal_handle) {
      RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
    } else {
      RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
    }
  }
```

As you already know, action servers can send feedback to the client while the action is being executed. This feedback is handled by the feedback_callback function:

```cpp
void feedback_callback(
    GoalHandleMove::SharedPtr,
    const std::shared_ptr<const Move::Feedback> feedback)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Feedback received: " +
      feedback->feedback);
  }
```

Also, when the action finishes, it sends a result back to the client. This result is handled by the result_callback function:
```cpp
void result_callback(const GoalHandleMove::WrappedResult & result)
  {
    this->goal_done_ = true;
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
        return;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
        return;
      default:
        RCLCPP_ERROR(this->get_logger(), "Unknown result code");
        return;
    }

    RCLCPP_INFO(this->get_logger(), "Result received: " + result.result->status);
  }
  ```