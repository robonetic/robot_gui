#include "robot_gui/robot_gui.h"
#include "robot_gui/general_info.h"
#include "ros/init.h"
#include <ros/ros.h>

RobotGUI::RobotGUI() {
  cvui::init(WINDOW_NAME);
  cv::Mat frame = cv::Mat(700, 300, CV_8UC3);
  ros::NodeHandle node_handle;

  GeneralInfo general_info(frame, &node_handle);

  while (ros::ok) {
    frame = cv::Scalar(49, 52, 49);
    // General Info Area
    general_info.render();

    cvui::imshow(WINDOW_NAME, frame);

    if (cv::waitKey(20) == 27) {
      break;
    }

    ros::spinOnce();
  }
}

RobotGUI::~RobotGUI(){};