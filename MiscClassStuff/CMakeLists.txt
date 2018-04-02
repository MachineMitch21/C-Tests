cmake_minimum_required(VERSION 3.5)

project(classes)

file(GLOB SOURCES ./*.cpp)

set (CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

add_executable(${PROJECT_NAME} ${SOURCES})
