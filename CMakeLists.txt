cmake_minimum_required(VERSION 3.10.2)
project(OOP2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")

add_executable(OOP2 main.cpp functions.h functions.cpp libraries.h)
