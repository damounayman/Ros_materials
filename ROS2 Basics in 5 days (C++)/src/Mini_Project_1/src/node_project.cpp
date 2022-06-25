#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include <chrono>

using namespace std::chrono_literals;
using std::placeholders::_1;

class TopicsProject : public rclcpp::Node {
public:
  TopicsProject() : Node("topics_project") {
    publisher_ =
        this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
        "/kobuki/laser/scan", 10,
        std::bind(&TopicsProject::topic_callback, this, _1));
  }

private:
  geometry_msgs::msg::Twist twist;

  void topic_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {

    if (msg->ranges[360] > 1) {
      twist.linear.x = 0.1;
      twist.angular.z = 0.0;
    }
    // If the distance to an obstacle in front of the robot is smaller than 1
    // meter, the robot will turn left
    if (msg->ranges[360] < 1) {
      twist.linear.x = 0.0;
      twist.angular.z = 0.2;
    }
    // If the distance to an obstacle at the left side of the robot is smaller
    // than 0.3 meters, the robot will turn right
    if (msg->ranges[719] < 0.3) {
      twist.linear.x = 0.0;
      twist.angular.z = -0.2;
    }
    // If the distance to an obstacle at the right side of the robot is smaller
    // than 0.3 meters, the robot will turn left
    if (msg->ranges[0] < 0.3) {
      twist.linear.x = 0.0;
      twist.angular.z = 0.2;
    }

    publisher_->publish(twist);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TopicsProject>());
  rclcpp::shutdown();
  return 0;
}