cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME exercise_13)

project(
  ${PROJECT_NAME}
  DESCRIPTION "Program to fill a 2D array (2x3) of type int with random numbers in the range of 0 and 99 and then print the array to the terminal."
)

add_executable(main main.cpp)

if(WIN32)
  target_link_options(main PRIVATE -static -static-libgcc -static-libstdc++)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")