cmake_minimum_required(VERSION 3.1)
project(ray-chess)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/raylib)
include_directories(lib/raylib/src)

add_executable(chess
    game.c
    src/grid.c)

target_link_libraries(chess raylib)