cmake_minimum_required(VERSION 3.5)
project(DSAAC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ch10/dictionary.cpp ch10/sortedChain.cpp ch10/sortedChain.h ch10/skipList.h)
add_executable(DSAAC ${SOURCE_FILES})