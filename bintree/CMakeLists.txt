cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -pthread ")

INCLUDE_DIRECTORIES(../../utilities/)

ADD_SUBDIRECTORY(test)
