cmake_minimum_required(VERSION 3.9)
project("DM Maths" VERSION 0.3.1)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Ofast")

include_directories(include)
add_subdirectory(src)
