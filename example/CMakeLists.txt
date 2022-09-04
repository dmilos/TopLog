cmake_minimum_required(VERSION 2.9)

project(TopLog_Example)

include_directories( "../src")


add_executable(  TopLog_Example_step_1   step_1.cpp )
add_executable(  TopLog_Example_step_2   step_2.cpp )
add_executable(  TopLog_Example_step_3   step_3.cpp )
add_executable(  TopLog_Example_step_4   step_4.cpp )
add_executable(  TopLog_Example_TopLog   TopLog.cpp )