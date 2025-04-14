cmake_minimum_required(VERSION 3.30.4)
set(PROJECT_NAME exercise_13)

project(
  ${PROJECT_NAME}
  DESCRIPTION "Program to fill a 2D array (2x3) of type int with random numbers in the range of 0 and 99 and then print the array to the terminal."
)

add_executable(main main.cpp)

