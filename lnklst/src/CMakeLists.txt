cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")


ADD_SUBDIRECTORY(lnklst)


ADD_EXECUTABLE(lnklst_main lnklst_main.cpp)

INCLUDE_DIRECTORIES("include")

ADD_DEPENDENCIES(lnklst_main lnklst)
TARGET_LINK_LIBRARIES(lnklst_main lnklst)

