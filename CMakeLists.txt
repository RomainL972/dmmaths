cmake_minimum_required(VERSION 3.9)
project("DM Maths")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Ofast")

add_executable(DM main.cpp pile.cpp disque.cpp piles_manager.cpp turn.cpp logger.cpp)
add_executable(Tester tester.cpp)
