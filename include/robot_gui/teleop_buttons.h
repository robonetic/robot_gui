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
  double precision = 1e-6;
  double step = 0.2;

  bool forward_increase = true;
  bool left_increase = true;
  bool right_increase = true;
  bool backward_increase = true;

  geometry_msgs::Twist cmd_vel_msg;
  ros::Publisher topic_publisher;
  ros::Timer cmd_vel_timer;
  ros::NodeHandle *node_handler;
  cv::Mat frame;
};