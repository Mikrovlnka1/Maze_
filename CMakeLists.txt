cmake_minimum_required(VERSION 3.31)
project(Maze_)

set(CMAKE_CXX_STANDARD 20)



# Dependencies
include(FetchContent)
set(RAYLIB_VERSION 4.5.0)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(SOURCE_FILES
        main.cpp)

add_executable(Maze_
        main.cpp
        CCell.h
        CCell.cpp)
target_link_libraries(${PROJECT_NAME} raylib)