cmake_minimum_required(VERSION 3.24)
project(task01)

set(CMAKE_CXX_STANDARD 17)

set(BUILD_CPR_TEST OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

add_executable(task01 main.cpp main.h cpr_get.cpp cpr_get.h gpr_post.cpp gpr_post.h cpr_put.cpp cpr_put.h cpr_del.cpp cpr_del.h cpr_patch.cpp cpr_patch.h)
target_link_libraries(task01 PRIVATE cpr::cpr)
