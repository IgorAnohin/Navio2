cmake_minimum_required(VERSION 3.5) 

project(FRAM)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	FRAM.cpp
	)
add_executable(FRAM ${SOURSE})

target_link_libraries(FRAM Navio)
