#include "robot_gui/robot_position.h"
#include "robot_gui/cvui.h"
#include <iostream>
#include <nav_msgs/Odometry.h>
#include <ros/ros.h>

using namespace std;

RobotPosition::RobotPosition(cv::Mat main_frame, ros::NodeHandle *node_handle) {
  node_handler = node_handle;
  frame = main_frame;
  topic_subscriber = node_handler->subscribe<nav_msgs::Odometry>(
      "odom", 2, &RobotPosition::topic_subscriber_callback, this);
}

void RobotPosition::render() {
  cvui::text(frame, 5, 460, "Estimated robot position based off odmetry");

  cvui::window(frame, 5, 475, 85, 85, "X");
  cvui::printf(frame, 10, 500, 0.6, 0x00ff00, "%.2f", x_pos);

  cvui::window(frame, 110, 475, 85, 85, "Y");
  cvui::printf(frame, 120, 500, 0.6, 0x00ff00, "%.2f", y_pos);

  cvui::window(frame, 210, 475, 85, 85, "Z");
  cvui::printf(frame, 212, 500, 0.6, 0x00ff00, "%.2f", z_pos);
}

void RobotPosition::topic_subscriber_callback(
    const nav_msgs::Odometry::ConstPtr &msg) {
  x_pos = msg->pose.pose.position.x;
  y_pos = msg->pose.pose.position.y;
  z_pos = msg->pose.pose.orientation.z;
}