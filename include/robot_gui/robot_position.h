#pragma once

#include <nav_msgs/Odometry.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class RobotPosition {
public:
  RobotPosition(cv::Mat main_frame, ros::NodeHandle *node_handle);

  void topic_subscriber_callback(const nav_msgs::Odometry::ConstPtr &msg);
  void render();

private:
  float x_pos;
  float y_pos;
  float z_pos;

  ros::Subscriber topic_subscriber;
  ros::NodeHandle *node_handler;
  cv::Mat frame;
};