cmake_minimum_required(VERSION 3.5) 

project(Servo)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	Servo.cpp
	)
add_executable(Servo ${SOURSE})

target_link_libraries(Servo Navio)
