cmake_minimum_required(VERSION 3.0)

project(hw_1)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(hw_1 hw_1.cpp)
target_link_libraries(hw_1 ${OpenCV_LIBS})