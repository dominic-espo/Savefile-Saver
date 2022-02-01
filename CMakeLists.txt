cmake_minimum_required(VERSION 3.21.1)
project(Savefile_Saver)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "-O0 -std=c++20 -pipe -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wconversion -Wsign-conversion -Wcast-align -Wlogical-op -Wunused")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-O2 -std=c++20 -pipe -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wconversion -Wsign-conversion -Wcast-align -Wlogical-op -Wunused")
endif()

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Savefile Saver")
