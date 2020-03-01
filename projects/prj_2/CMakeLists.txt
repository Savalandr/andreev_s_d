cmake_minimum_required(VERSION 3.0)

project(prj_2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(prj_2 prj_2.cpp)
target_link_libraries(prj_2 ${OpenCV_LIBS})