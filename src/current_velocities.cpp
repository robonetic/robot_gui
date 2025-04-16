#include "robot_gui/current_velocities.h"
#include "robot_gui/cvui.h"
#include "ros/node_handle.h"
#include <ctime>
#include <geometry_msgs/Twist.h>

using namespace std;

CurrentVelocities::CurrentVelocities(cv::Mat main_frame,
                                     ros::NodeHandle *node_handle) {
  frame = main_frame;
  node_handler = node_handle;
  topic_subscriber = node_handler->subscribe<geometry_msgs::Twist>(
      "/cmd_vel", 2, &CurrentVelocities::topic_subscriber_callback, this);
}

void CurrentVelocities::render() {
  cvui::window(frame, 5, 400, 140, 45, "Linear velocity:");
  cvui::printf(frame, 25, 425, 0.4, 0xff0000, "%.2f m/sec", linear_velocity);

  cvui::window(frame, 150, 400, 140, 45, "Angular velocity:");
  cvui::printf(frame, 175, 425, 0.4, 0xff0000, "%.2f rad/sec",
               angular_velocity);
}

void CurrentVelocities::topic_subscriber_callback(
    const geometry_msgs::Twist::ConstPtr &msg) {
  geometry_msgs::Twist cmd_vel_msg = *msg;

  linear_velocity = cmd_vel_msg.linear.x;
  angular_velocity = cmd_vel_msg.angular.z;
}
