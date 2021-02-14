file(GLOB easy "Easy/*.hpp")
file(GLOB medium "Medium/*.hpp")
file(GLOB hard "Hard/*.hpp")

add_executable(LeetCode Main.cpp ${easy} ${medium} ${hard})

list(APPEND includeDirs
    "${CMAKE_CURRENT_SOURCE_DIR}/Easy"
    "${CMAKE_CURRENT_SOURCE_DIR}/Medium"
    "${CMAKE_CURRENT_SOURCE_DIR}/Hard"
)

target_include_directories(LeetCode PUBLIC "$<BUILD_INTERFACE:${includeDirs}>")
