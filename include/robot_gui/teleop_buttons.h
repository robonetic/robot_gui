#pragma once

#include <geometry_msgs/Twist.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class TeleopButtons {
public:
  TeleopButtons(cv::Mat main_frame, ros::NodeHandle *node_handle);

  void publish_cmd_vel(const ros::TimerEvent &event);
  void render();
  void forward();
  void left();
  void right();
  void backward();
  void stop();

private:
  double positive_max_speed = 1;
  double positive_min_speed = 0.2;
  double negative_max_speed = -1;
  double negative_min_speed = -0.2;

  double precision = 1e-6;
  double step = 0.2;

  bool forward_increase = true;
  bool left_increase = true;
  bool right_increase = true;
  bool backward_increase = true;

  ros::Publisher topic_publisher;
  ros::NodeHandle *node_handler;
  ros::Timer cmd_vel_timer;
  geometry_msgs::Twist cmd_vel_msg;
  cv::Mat frame;
};