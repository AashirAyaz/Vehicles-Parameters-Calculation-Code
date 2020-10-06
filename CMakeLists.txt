cmake_minimum_required(VERSION 3.13) # CMake version check

project(simple_task) # Create project "simple_task"

set(SOURCE_FILES main.cpp) # Add main.cpp file of project root directory as source file

add_executable(simple_task ${SOURCE_FILES}) # Add executable target with source files listed in SOURCE_FILES variable
