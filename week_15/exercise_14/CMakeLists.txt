cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME exercise_14)

project(
  ${PROJECT_NAME}
  DESCRIPTION "Exercise from cpp course."
)

add_executable(main main.cpp)

if(WIN32)
  target_link_options(main PRIVATE -static -static-libgcc -static-libstdc++)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")