#include "robot_gui/distance_traveled.h"
#include "robot_gui/cvui.h"
#include "ros/node_handle.h"
#include <iostream>
#include <std_srvs/Trigger.h>

DistanceTraveled::DistanceTraveled(cv::Mat main_frame,
                                   ros::NodeHandle *node_handle) {
  frame = main_frame;
  node_handler = node_handle;
  get_distance_service =
      node_handle->serviceClient<std_srvs::Trigger>("get_distance");
  reset_distance_service =
      node_handle->serviceClient<std_srvs::Trigger>("reset_distance");
}

void DistanceTraveled::render() {
  cvui::text(frame, 5, 565, "Distance Traveled");

  if (cvui::button(frame, 5, 585, 80, 55, "Call")) {
    std_srvs::Trigger srv;
    if (get_distance_service.call(srv)) {
      total_distance_traveled = srv.response.message;
      ROS_INFO("Success! - Total Distance Traveled: %s",
               total_distance_traveled.c_str());
    } else {
      ROS_ERROR("Error! - An unexpected error has occurred when calling the "
                "/get_distance service.");
    }
  }

  if (cvui::button(frame, 5, 640, 80, 55, "Reset")) {
    std_srvs::Trigger srv;
    if (reset_distance_service.call(srv)) {
      total_distance_traveled = srv.response.message;
      ROS_INFO("Success! - Total Distance Has been reset to: %s",
               total_distance_traveled.c_str());
    } else {
      cout << "Error " << srv.response.message << endl;
      ROS_ERROR("Error! - An unexpected error has occurred when calling the "
                "/reset_distance service.");
    }
  }

  cvui::window(frame, 95, 585, 200, 55, "Distance in meters:");
  cvui::printf(frame, 180, 615, 0.7, 0x00ff00, "%s",
               total_distance_traveled.c_str());
}