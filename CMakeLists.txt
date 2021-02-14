cmake_minimum_required(VERSION 3.16)

project(TheAlgorithms CXX)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE MinSizeRel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(DataStructures)
add_subdirectory(Algorithms/MaxSubarray)
add_subdirectory(Algorithms/Sorting)
add_subdirectory(LeetCode)
