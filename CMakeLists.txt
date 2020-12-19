cmake_minimum_required(VERSION 3.19)
project(PingBallX)

set(CMAKE_CXX_STANDARD 17)

add_executable(PingBallX src/main.cpp src/Game.h src/Game.cpp 3rdparty/olcPixelGameEngine/olcPixelGameEngine.cpp src/Player.cpp src/Player.h src/Ball.cpp src/Ball.h src/UserInterface.cpp src/UserInterface.h)

include_directories(${PROJECT_SOURCE_DIR}/3rdparty/olcPixelGameEngine)

target_link_libraries(PingBallX pthread png GL X11)