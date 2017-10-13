cmake_minimum_required(VERSION 3.5) 

project(Barometer)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	Barometer.cpp
	)
add_executable(Barometer ${SOURSE})

target_link_libraries(Barometer Navio)
