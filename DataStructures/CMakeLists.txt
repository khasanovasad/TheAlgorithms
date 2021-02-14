add_executable(DS Main.cpp
    "Include/List.hpp"
    "Include/Vector.hpp"
    "Include/Stack.hpp"
    "Include/Queue.hpp"
)

target_include_directories(DS PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Include")
