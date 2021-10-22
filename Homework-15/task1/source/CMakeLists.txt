cmake_minimum_required(VERSION 3.20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(Simulator main.cpp ${INCLUDE_DIR}/operation.h operation.cpp)
target_include_directories(Simulator PUBLIC ${INCLUDE_DIR})