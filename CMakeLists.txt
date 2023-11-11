cmake_minimum_required(VERSION 3.25)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 code/main.cpp code/Matrix/Matrix.h code/Matrix/Matrix.cpp code/Input/Input.h code/Input/Input.cpp)
