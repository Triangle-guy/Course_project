cmake_minimum_required(VERSION 3.7)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR "D:/vcpkg/installed/x64-windows/share/sdl2")
set(SDL2_INCLUDE_DIR "D:/vcpkg/installed/x64-windows/include/SDL2")
set(SDL2_LIBRARY_DIR "D:/vcpkg/installed/x64-windows/lib")

link_directories(SDL2_LIBRARY_DIR)
include_directories(SDL2_INCLUDE_DIR)

find_package(SDL2 REQUIRED)

add_executable(Game Main.cpp Main.h GameLoop.cpp GameLoop.h Actor.cpp Actor.h Bullet.cpp Bullet.h Enemy.cpp Enemy.h EventHandler.cpp EventHandler.h Graphics.cpp Graphics.h Player.cpp Player.h Shapes.cpp Shapes.h Timer.cpp Timer.h Vector2D.cpp Vector2D.h)
target_link_libraries(Game  SDL2::SDL2 SDL2::SDL2main)