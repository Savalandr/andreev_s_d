cmake_minimum_required(VERSION 3.0)

project(prj_1)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(prj_1 prj_1.cpp)
target_link_libraries(prj_1 ${OpenCV_LIBS})