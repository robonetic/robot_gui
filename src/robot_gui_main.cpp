#include "robot_gui/robot_gui.h"
#include "ros/node_handle.h"
#include <iostream>
#include <ros/ros.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void my_handler(int s) {
  cout << "Caught signal - Terminating program." << endl;
  exit(1);
}

void setup_sig_handler() {
  struct sigaction sig_int_handler;

  sig_int_handler.sa_handler = my_handler;
  sigemptyset(&sig_int_handler.sa_mask);
  sig_int_handler.sa_flags = 0;

  sigaction(SIGINT, &sig_int_handler, NULL);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_gui_node");
  setup_sig_handler();
  RobotGUI robot_gui{};
}