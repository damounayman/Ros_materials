cmake_minimum_required(VERSION 3.5)
project(cpp_unit_7_services)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(gazebo_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # remove the line when a copyright and license is present in all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # remove the line when this package is a git repo
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(cpp_simple_service_client src/cpp_simple_service_client.cpp)
ament_target_dependencies(cpp_simple_service_client rclcpp std_msgs gazebo_msgs)


add_executable(cpp_simple_service_client_ex7_1_node src/cpp_simple_service_client_ex7_1_node.cpp)
ament_target_dependencies(cpp_simple_service_client_ex7_1_node rclcpp std_msgs gazebo_msgs)


install(TARGETS
   cpp_simple_service_client
   DESTINATION lib/${PROJECT_NAME}
 )

 install(TARGETS
   cpp_simple_service_client_ex7_1_node
   DESTINATION lib/${PROJECT_NAME}
 )


ament_package()