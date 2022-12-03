cmake_minimum_required(VERSION 3.23)
project(Tankplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
link_directories(lib)

add_executable(Tankplusplus
        include/raylib.h
        src/main.cpp src/Player.cpp src/Player.h src/Pellet.cpp src/Pellet.h src/Block.cpp src/Block.h src/BlockGenerator.cpp src/BlockGenerator.h)
target_link_libraries(Tankplusplus raylib opengl32 gdi32 winmm)