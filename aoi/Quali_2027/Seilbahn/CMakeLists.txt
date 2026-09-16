cmake_minimum_required(VERSION 4.3)
project(Seilbahn)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_DEBUG "-g")

set(CMAKE_CXX_STANDARD 20)

add_executable(Seilbahn main.cpp)



