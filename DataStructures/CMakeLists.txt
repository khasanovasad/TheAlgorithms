add_executable(DS Main.cpp
    "Include/List.hpp"
    "Include/Vector.hpp"
)

target_include_directories(DS PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include")
