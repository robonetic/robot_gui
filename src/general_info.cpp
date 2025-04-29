#include "robot_gui/general_info.h"
#include "robot_gui/cvui.h"
#include "robot_info/RobotInfoMsg.h"
#include <ros/ros.h>

GeneralInfo::GeneralInfo(cv::Mat main_frame, ros::NodeHandle *node_handle) {
  frame = main_frame;
  node_handler = node_handle;
  topic_subscriber = node_handler->subscribe<robot_info::RobotInfoMsg>(
      "robot_info", 2, &GeneralInfo::topic_subscriber_callback, this);
}

void GeneralInfo::render() {
  cvui::window(frame, 10, 10, 280, 150, "Info");

  cvui::printf(frame, 15, 40, 0.4, 0x00ff00, "%s",
               robot_info.data_field_01.c_str());
  cvui::printf(frame, 15, 55, 0.4, 0x00ff00, "%s",
               robot_info.data_field_02.c_str());
  cvui::printf(frame, 15, 70, 0.4, 0x00ff00, "%s",
               robot_info.data_field_03.c_str());
  cvui::printf(frame, 15, 85, 0.4, 0x00ff00, "%s",
               robot_info.data_field_04.c_str());
  cvui::printf(frame, 15, 100, 0.4, 0x00ff00, "%s",
               robot_info.data_field_05.c_str());
  cvui::printf(frame, 15, 115, 0.4, 0x00ff00, "%s",
               robot_info.data_field_06.c_str());
  cvui::printf(frame, 15, 130, 0.4, 0x00ff00, "%s",
               robot_info.data_field_07.c_str());
  cvui::printf(frame, 15, 145, 0.4, 0x00ff00, "%s",
               robot_info.data_field_08.c_str());
}

void GeneralInfo::topic_subscriber_callback(
    const robot_info::RobotInfoMsg::ConstPtr &msg) {
  robot_info = *msg;
}