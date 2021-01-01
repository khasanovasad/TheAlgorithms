cmake_minimum_required(VERSION 3.16)

project(dsa CXX)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE MinSizeRel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (CMAKE_COMPILER_IS_GNUCC) # if gcc is in use
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()


add_executable(dsa main.cpp
    "include/list.h"
    "include/vector.h"
)

target_link_libraries(dsa pthread)

target_include_directories(dsa PUBLIC "${PROJECT_SOURCE_DIR}/include")
