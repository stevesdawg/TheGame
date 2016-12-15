cmake_minimum_required(VERSION 3.6)
project(TheGame)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "TheGame")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
        main.cpp DE2Bot.cpp DE2Bot.h Drawable.h Movable.h Map.cpp Map.h
        Wall.h Wall.cpp Bullet.cpp Bullet.h main2.cpp GameState.cpp GameState.h)
#copy file to where my executable is
file(COPY "content/arial.ttf" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})