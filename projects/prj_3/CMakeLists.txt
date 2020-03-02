cmake_minimum_required(VERSION 3.0)

project(prj_3)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(prj_3 prj_3.cpp)
target_link_libraries(prj_3 ${OpenCV_LIBS})