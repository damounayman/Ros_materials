#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/empty.hpp"
#include <inttypes.h>
#include <memory>

using Empty = std_srvs::srv::Empty;
rclcpp::Node::SharedPtr g_node = nullptr;

using namespace std::chrono_literals;
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;

void my_handle_service(const std::shared_ptr<rmw_request_id_t> request_header,
                       const std::shared_ptr<Empty::Request> request,
                       const std::shared_ptr<Empty::Response> response) {
  (void)request_header;
  RCLCPP_INFO(g_node->get_logger(), "bb8_move_in_square_service_server");

  geometry_msgs::msg::Twist vel;
  vel.linear.x = 0.2;
  vel.angular.z = 0;
  pub_->publish(vel);
  std::this_thread::sleep_for(3000ms);
  vel.linear.x = 0;
  vel.angular.y = 0.2;
  pub_->publish(vel);
  std::this_thread::sleep_for(3000ms);
  vel.linear.x = -0.2;
  vel.angular.z = 0;
  pub_->publish(vel);
  std::this_thread::sleep_for(3000ms);
  vel.linear.x = 0;
  vel.angular.z = -0.2;
  pub_->publish(vel);
  std::this_thread::sleep_for(3000ms);
  vel.linear.x = 0;
  vel.angular.z = 0;
  pub_->publish(vel);
}

int main(int argc, char **argv) {

  rclcpp::init(argc, argv);

  g_node = rclcpp::Node::make_shared("move_in_square");

  pub_ = g_node->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
  auto server =
      g_node->create_service<Empty>("/move_bb8_in_square", my_handle_service);
  rclcpp::spin(g_node);
  rclcpp::shutdown();
  g_node = nullptr;
  return 0;
}