#pragma once

#include "ros/node_handle.h"
#include "ros/service_client.h"
#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <std_srvs/Trigger.h>

using namespace std;

class DistanceTraveled {
public:
  DistanceTraveled(cv::Mat main_frame, ros::NodeHandle *node_handle);

  void render();

private:
  string total_distance_traveled;

  ros::ServiceClient get_distance_service;
  ros::ServiceClient reset_distance_service;
  ros::NodeHandle *node_handler;
  cv::Mat frame;
};