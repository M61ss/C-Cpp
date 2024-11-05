cmake_minimum_required(VERSION 3.8)
project(root)

find_package(Eigen3 REQUIRED)      # Looks for the package Eigen3 inside the filesystem

add_executable(my_executable src/main.cpp)
target_link_libraries(my_executable Eigen3::Eigen)
