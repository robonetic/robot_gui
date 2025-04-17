#pragma once

#include <geometry_msgs/Twist.h>
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class CurrentVelocities {
public:
  CurrentVelocities(cv::Mat main_frame, ros::NodeHandle *node_handle);

  void topic_subscriber_callback(const geometry_msgs::Twist::ConstPtr &msg);
  void render();

private:
  float linear_velocity = 0.0;
  float angular_velocity = 0.0;
  ros::NodeHandle *node_handler;
  ros::Subscriber topic_subscriber;
  cv::Mat frame;
};