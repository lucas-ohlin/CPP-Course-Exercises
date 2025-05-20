cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME assignment_2)

project(
  ${PROJECT_NAME} 
  DESCRIPTION "Assignment from cpp course."
)

set(WAREHOUSE_CAPACITY 12)

add_executable(main
  main.cpp
)

target_compile_options(main PRIVATE -Wall -Wextra -std=c++17)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_definitions(main PRIVATE VEHICLE_WAREHOUSE_CAPACITY=${WAREHOUSE_CAPACITY})

if(WIN32)
  target_link_options(main PRIVATE -static -static-libgcc -static-libstdc++)
endif()