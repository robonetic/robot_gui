#include "robot_gui/robot_gui.h"
#include "robot_gui/current_velocities.h"
#include "robot_gui/distance_traveled.h"
#include "robot_gui/general_info.h"
#include "robot_gui/robot_position.h"
#include "robot_gui/teleop_buttons.h"
#include "ros/init.h"
#include <csignal>
#include <iostream>
#include <ros/ros.h>

using namespace std;

RobotGUI::RobotGUI() {
  cvui::init(WINDOW_NAME);
  cv::Mat frame = cv::Mat(700, 300, CV_8UC3);

  GeneralInfo general_info(frame, &node_handle);
  TeleopButtons teleop_buttons(frame, &node_handle);
  CurrentVelocities current_velocities(frame, &node_handle);
  RobotPosition robot_position(frame, &node_handle);
  DistanceTraveled distance_traveled(frame, &node_handle);

  while (ros::ok()) {
    frame = cv::Scalar(49, 52, 49);

    general_info.render();
    teleop_buttons.render();
    current_velocities.render();
    robot_position.render();
    distance_traveled.render();

    cvui::imshow(WINDOW_NAME, frame);

    if (cv::waitKey(20) == 3) {
      break;
    }

    ros::spinOnce();
  }
}