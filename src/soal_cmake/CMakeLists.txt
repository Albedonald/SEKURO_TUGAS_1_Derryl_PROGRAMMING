cmake_minimum_required(VERSION 3.10)
project(robot)
#[TODO] Implentasikan CMakeList di bawah ini

include_directories(include)

add_executable(robot
    src/main.cpp
    src/robot.cpp
    src/robotair.cpp
)

message(STATUS "Install prefix before set: ${CMAKE_INSTALL_PREFIX}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Install prefix after set: ${CMAKE_INSTALL_PREFIX}")

install(TARGETS robot
    DESTINATION bin
)