#ifndef COMPOSITION__READODOM_COMPONENT_HPP_
#define COMPOSITION__READODOM_COMPONENT_HPP_

#include "my_components/visibility_control.h"
#include "nav_msgs/msg/odometry.hpp"
#include "rclcpp/rclcpp.hpp"

namespace my_components {

class OdomSubscriber : public rclcpp::Node {
public:
  COMPOSITION_PUBLIC
  explicit OdomSubscriber(const rclcpp::NodeOptions &options);

private:
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

} // namespace my_components

#endif // COMPOSITION__READODOM_COMPONENT_HPP_