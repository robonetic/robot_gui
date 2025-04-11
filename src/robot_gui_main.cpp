#include "robot_gui/robot_gui.h"
#include "ros/node_handle.h"
#include <ros/ros.h>

using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui_node");

  RobotGUI robot_gui{};
}