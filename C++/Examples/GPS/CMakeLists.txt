cmake_minimum_required(VERSION 3.5) 

project(GPS)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	gps.cpp
	)
add_executable(GPS ${SOURSE})

target_link_libraries(GPS Navio)
