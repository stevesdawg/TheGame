cmake_minimum_required(VERSION 3.6)
project(TheGame)

#define EXECUTABLE NAME HERE
set(EXECUTABLE_NAME "DE2Trouble")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Game.h DE2Bot.h DE2Bot.cpp Drawable.h Movable.h Map.h Map.cpp)
add_executable(TheGame ${SOURCE_FILES})

#copy file to where my executable is
file(COPY "content/botSprite.png" DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})