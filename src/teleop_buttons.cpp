#include "robot_gui/teleop_buttons.h"
#include "robot_gui/cvui.h"
#include <geometry_msgs/Twist.h>

using namespace std;
using namespace cvui;

TeleopButtons::TeleopButtons(cv::Mat main_frame, ros::NodeHandle *node_handle) {
  node_handler = node_handle;
  topic_publisher =
      node_handler->advertise<geometry_msgs::Twist>("cmd_vel", 10);
  cmd_vel_timer = node_handle->createTimer(
      ros::Duration(0.1), &TeleopButtons::publish_cmd_vel, this);
  frame = main_frame;
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
  if (cmd_vel_msg.linear.x < 0.0) {
    cmd_vel_msg.linear.x = positive_min_speed;
    return;
  }

  if (forward_increase) {
    if (abs(cmd_vel_msg.linear.x - positive_max_speed) < precision) {
      cmd_vel_msg.linear.x -= step;
      forward_increase = false;
      return;
    }

    cmd_vel_msg.linear.x += step;
  } else {
    if (cmd_vel_msg.linear.x <= positive_min_speed + precision) {
      cmd_vel_msg.linear.x += step;
      forward_increase = true;
      return;
    }

    cmd_vel_msg.linear.x -= step;
  }
}

void TeleopButtons::left() {
  if (cmd_vel_msg.angular.z < 0.0) {
    cmd_vel_msg.angular.z = positive_min_speed;
    return;
  }

  if (left_increase) {
    if (abs(cmd_vel_msg.angular.z - positive_max_speed) < precision) {
      cmd_vel_msg.angular.z -= step;
      left_increase = false;
      return;
    }

    cmd_vel_msg.angular.z += step;
  } else {
    if (cmd_vel_msg.angular.z <= positive_min_speed + precision) {
      cmd_vel_msg.angular.z += step;
      left_increase = true;
      return;
    }

    cmd_vel_msg.angular.z -= step;
  }
}

void TeleopButtons::right() {
  if (cmd_vel_msg.angular.z >= 0.0) {
    cmd_vel_msg.angular.z = negative_min_speed;
    return;
  }

  if (right_increase) {
    if (cmd_vel_msg.angular.z - negative_max_speed < precision) {
      cmd_vel_msg.angular.z += step;
      right_increase = false;
      return;
    }

    cmd_vel_msg.angular.z -= step;
  } else {
    if (cmd_vel_msg.angular.z >= negative_min_speed - precision) {
      cmd_vel_msg.angular.z -= step;
      right_increase = true;
      return;
    }

    cmd_vel_msg.angular.z += step;
  }
}

void TeleopButtons::backward() {
  if (cmd_vel_msg.linear.x >= 0.0) {
    cmd_vel_msg.linear.x = negative_min_speed;
    return;
  }

  if (backward_increase) {
    if (cmd_vel_msg.linear.x - negative_max_speed < precision) {
      cmd_vel_msg.linear.x += step;
      backward_increase = false;
      return;
    }

    cmd_vel_msg.linear.x -= step;
  } else {
    if (cmd_vel_msg.linear.x >= negative_min_speed - precision) {
      cmd_vel_msg.linear.x -= step;
      backward_increase = true;
      return;
    }

    cmd_vel_msg.linear.x += step;
  }
}

void TeleopButtons::stop() {
  cmd_vel_msg.linear.x = 0;
  cmd_vel_msg.angular.z = 0;
}
