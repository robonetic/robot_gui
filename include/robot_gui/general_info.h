#pragma once

// #include "robot_gui/cvui.h"
#include "robot_info/RobotInfoMsg.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class GeneralInfo {
public:
  GeneralInfo(cv::Mat frame, ros::NodeHandle *node_handle);

  void render();
  void topic_subscriber_callback(const robot_info::RobotInfoMsg::ConstPtr &msg);

private:
  ros::Subscriber topic_subscriber;
  ros::NodeHandle *node_handler;
  robot_info::RobotInfoMsg robot_info;
  cv::Mat main_frame;
};