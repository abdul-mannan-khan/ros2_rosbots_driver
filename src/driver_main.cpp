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

//#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "controller/supervisor.hpp"

using namespace _rosbots_ns;

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Supervisor>());
  rclcpp::shutdown();
  return 0;
}
