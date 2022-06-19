#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include <chrono>
using namespace std::chrono_literals;

class MoveRobot : public rclcpp::Node {

public:
  MoveRobot() : Node("move_robot") {
    publisher_ =
        this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MoveRobot::timer_callback, this));
  }

private:
  void timer_callback() {
    auto message = geometry_msgs::msg::Twist();
    message.linear.x = 0.3;
    message.angular.z = 0.3;
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MoveRobot>());
  rclcpp::shutdown();
  return 0;
}