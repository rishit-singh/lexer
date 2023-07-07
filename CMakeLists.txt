cmake_minimum_required(VERSION 2.8)
project(lexer)

set(CMAKE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -D_THREAD_SAFE --std=c++20")
file(GLOB lexer_SOURCES
		src/*.cpp)


include_directories( include/ )
add_executable(lexer ${lexer_SOURCES})
target_include_directories(lexer PRIVATE include/)
