#include "robot_gui/teleop_buttons.h"
#include "robot_gui/cvui.h"
#include <geometry_msgs/Twist.h>

using namespace std;
using namespace cvui;

TeleopButtons::TeleopButtons(cv::Mat main_frame, ros::NodeHandle *node_handle) {
  frame = main_frame;
  node_handler = node_handle;
  topic_publisher =
      node_handler->advertise<geometry_msgs::Twist>("cmd_vel", 10);
  cmd_vel_timer = node_handle->createTimer(
      ros::Duration(0.1), &TeleopButtons::publish_cmd_vel, this);
}

void TeleopButtons::publish_cmd_vel(const ros::TimerEvent &event) {
  topic_publisher.publish(cmd_vel_msg);
}

void TeleopButtons::render() {
  if (button(frame, 105, 175, 90, 65, "Forward"))
    forward();

  beginRow(frame, 5, 250, 300, 90, 10);
  if (button(90, 65, "Left"))
    left();

  if (button(90, 65, "Stop"))
    stop();

  if (button(90, 65, "Right"))
    right();
  endRow();

  if (button(frame, 105, 325, 90, 65, "Backward"))
    backward();
}

void TeleopButtons::forward() {
  if (cmd_vel_msg.linear.x < 1) {
    cmd_vel_msg.linear.x += 0.2;
  }
}

void TeleopButtons::left() {
  if (cmd_vel_msg.angular.z < 1) {
    cmd_vel_msg.angular.z += 0.2;
  }
}

void TeleopButtons::right() {
  if (cmd_vel_msg.angular.z > -1) {
    cmd_vel_msg.angular.z -= 0.2;
  }
}

void TeleopButtons::backward() {
  if (cmd_vel_msg.linear.x > -1) {
    cmd_vel_msg.linear.x -= step;
  }
}

void TeleopButtons::stop() {
  cmd_vel_msg.linear.x = 0;
  cmd_vel_msg.angular.z = 0;
}
