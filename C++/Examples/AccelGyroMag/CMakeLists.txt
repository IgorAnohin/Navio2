cmake_minimum_required(VERSION 3.5) 

project(AccelGyroMag)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	AccelGyroMag.cpp
	)
add_executable(AccelGyroMag ${SOURSE})

target_link_libraries(AccelGyroMag Navio)
