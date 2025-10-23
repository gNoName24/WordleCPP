cmake_minimum_required(VERSION 3.10)

project(wordlecpp)

add_executable(wordlecpp main.cpp)

install(TARGETS wordlecpp RUNTIME DESTINATION bin)
