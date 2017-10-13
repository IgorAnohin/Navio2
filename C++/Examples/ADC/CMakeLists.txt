cmake_minimum_required(VERSION 3.5) 

project(ADC)


add_definitions(-std=c++11)

include_directories(../../Navio/)

set(SOURSE
	ADC.cpp
	)
add_executable(ADC ${SOURSE})

target_link_libraries(ADC Navio)

