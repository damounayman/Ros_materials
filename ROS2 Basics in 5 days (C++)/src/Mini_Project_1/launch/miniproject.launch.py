"""Launch a talker and a listener."""

from launch import LaunchDescription
import launch_ros.actions


def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='Mini_Project_1', executable='topics_project', output='screen'),
    ])
