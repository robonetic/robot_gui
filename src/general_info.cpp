#include "robot_gui/general_info.h"
#include "robot_gui/cvui.h"
#include "robot_info/RobotInfoMsg.h"
#include <iostream>
#include <ros/ros.h>

using namespace std;

GeneralInfo::GeneralInfo(cv::Mat main_frame, ros::NodeHandle *node_handle) {
  node_handler = node_handle;
  frame = main_frame;
  topic_subscriber = node_handler->subscribe<robot_info::RobotInfoMsg>(
      "robot_info", 2, &GeneralInfo::topic_subscriber_callback, this);
}

void GeneralInfo::render() {
  cvui::window(frame, 10, 10, 280, 150, "Info");

  cvui::printf(frame, 15, 40, "%s", robot_info.data_field_01.c_str());
  cvui::printf(frame, 15, 60, "%s", robot_info.data_field_02.c_str());
  cvui::printf(frame, 15, 80, "%s", robot_info.data_field_03.c_str());
  cvui::printf(frame, 15, 100, "%s", robot_info.data_field_04.c_str());
  cvui::printf(frame, 15, 120, "%s", robot_info.data_field_05.c_str());
}

void GeneralInfo::topic_subscriber_callback(
    const robot_info::RobotInfoMsg::ConstPtr &msg) {
  robot_info = *msg;
}