add_executable(ds main.cpp
    "include/list.h"
    "include/vector.h"
)

target_include_directories(ds PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(ds pthread)
