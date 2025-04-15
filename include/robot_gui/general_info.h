#pragma once

#include "robot_info/RobotInfoMsg.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class GeneralInfo {
public:
  GeneralInfo(cv::Mat main_frame, ros::NodeHandle *node_handle);

  void render();
  void topic_subscriber_callback(const robot_info::RobotInfoMsg::ConstPtr &msg);

private:
  robot_info::RobotInfoMsg robot_info;
  ros::Subscriber topic_subscriber;
  ros::NodeHandle *node_handler;
  cv::Mat frame;
};