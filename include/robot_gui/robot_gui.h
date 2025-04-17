#pragma once

#define CVUI_IMPLEMENTATION
#define WINDOW_NAME "Robot GUI"

#include "robot_gui/cvui.h"
#include "robot_info/RobotInfoMsg.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>

class RobotGUI {
public:
  RobotGUI();

private:
  ros::NodeHandle node_handle;
  cv::Mat main_frame;
};