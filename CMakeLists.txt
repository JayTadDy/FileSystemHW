cmake_minimum_required(VERSION 3.10)

project(file_system_info
        VERSION 0.1
        LANGUAGES CXX)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE data include/*.hpp)

add_executable(file_system_info ${sources} ${data})