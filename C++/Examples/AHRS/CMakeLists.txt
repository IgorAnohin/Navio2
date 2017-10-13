cmake_minimum_required(VERSION 3.5) 

project(AHRS)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	AHRS.cpp
	)
add_executable(AHRS ${SOURSE})

target_link_libraries(AHRS Navio)
