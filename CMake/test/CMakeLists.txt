cmake_minimum_required(VERSION 3.8)
project(test)

find_package(Eigen3 REQUIRED)      # Cerca il package nell'albero del filesystem

add_executable(my_executable src/main.cpp)
target_link_libraries(my_executable Eigen3::Eigen)
