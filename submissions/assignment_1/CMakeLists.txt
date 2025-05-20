cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME exercise_14)

project(
  ${PROJECT_NAME} 
  DESCRIPTION "Assignment from cpp course."
)

add_executable(main
  test_queue.cpp
  circular_queue.cpp
)

target_compile_options(main PRIVATE -Wall -Wextra)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(WIN32)
  target_link_options(main PRIVATE -static -static-libgcc -static-libstdc++)
endif()
