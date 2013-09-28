cmake_minimum_required(VERSION 2.6)
project(OpenRobot)

set(OpenRobot_VERSION_MAJOR 1)
set(OpenRobot_VERSION_MINOR 0)

set(OpenRobot_ROOT_DIR ${OpenRobot_SOURCE_DIR}/../)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(INSTALL_DIR "/usr")

#if(NOT INSTALL_DIR STREQUAL "")
#set(INSTALL_DIR "/usr")
#endif()

add_subdirectory(Base)
