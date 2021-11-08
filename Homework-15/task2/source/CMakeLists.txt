cmake_minimum_required(VERSION 3.20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

add_executable(MyPCtool main.cpp ${INCLUDE_DIR}main.h ${INCLUDE_DIR}cpu.h ${INCLUDE_DIR}ram.h ${INCLUDE_DIR}disk.h ${INCLUDE_DIR}gpu.h ${INCLUDE_DIR}kbd.h cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp)

target_include_directories(MyPCtool PUBLIC ${INCLUDE_DIR})