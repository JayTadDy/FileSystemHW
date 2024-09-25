cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 14)

project(file_system_info
        VERSION 0.1
        LANGUAGES CXX)

add_library(file_system_info_lib SHARED src/menu.cpp)

target_include_directories(file_system_info_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(file_system_info src/main.cpp)

target_link_libraries(file_system_info file_system_info_lib)
