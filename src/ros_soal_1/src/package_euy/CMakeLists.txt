cmake_minimum_required(VERSION 3.8)
project(package_euy)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(chatter src/chatter.cpp)
ament_target_dependencies(chatter rclcpp std_msgs)

add_executable(display src/display.cpp)
ament_target_dependencies(display rclcpp std_msgs)

install (TARGETS
  chatter
  display
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()