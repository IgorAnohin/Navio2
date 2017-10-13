cmake_minimum_required(VERSION 3.5) 

project(LED)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	LED.cpp
	)
add_executable(LED ${SOURSE})

target_link_libraries(LED Navio)
