cmake_minimum_required(VERSION 3.7)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR "D:/vcpkg/installed/x86-windows/share/sdl2")
set(SDL2_INCLUDE_DIR "D:/vcpkg/installed/x86-windows/include/SDL2")
set(SDL2_LIBRARY_DIR "D:/vcpkg/installed/x86-windows/lib")


link_directories(SDL2_LIBRARY_DIR)
include_directories(SDL2_INCLUDE_DIR)

find_package(SDL2 CONFIG REQUIRED)

add_executable(Game Main.cpp)
target_link_libraries(Game PRIVATE SDL2::SDL2 SDL2::SDL2main)