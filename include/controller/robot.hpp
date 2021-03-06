/*
 * This file is part of ROSbots ROS Drivers.
 *
 * Copyright
 *
 *     Copyright (C) 2019 Jack Pien <jack@rosbots.com>
 *
 * License
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published
 *     by the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details at
 *     <http://www.gnu.org/licenses/lgpl-3.0-standalone.html>
 *
 * Documentation
 *
 *     http://www.rosbots.com
 */

#ifndef _ROSBOTS_ROBOT_HPP
#define _ROSBOTS_ROBOT_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

namespace _rosbots_ns {

class Robot {

public:
  Robot(rclcpp::Node* parent_ros_node);

  void set_wheel_speed(double vr, double vl);

  double get_wheelbase() {return this->wheelbase_;}
  double get_wheel_radius() {return this->wheel_radius_;}

private:
  rclcpp::Node* p_parent_ros_node_;
  double wheelbase_;
  double wheel_radius_;

  double wheel_speed_min_;
  double wheel_speed_mid_;
  double wheel_speed_max_;
  double wheel_speed_min_power_;
  double wheel_speed_mid_power_;
  double wheel_speed_max_power_;
  std_msgs::msg::Float32 cur_wheel_power_right_;
  std_msgs::msg::Float32 cur_wheel_power_left_;

  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_power_right_;
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_power_left_;

  double velocity_to_power(double v);
};

} // namespace _rosbots_ns

#endif // _ROSBOTS_ROBOT_HPP
