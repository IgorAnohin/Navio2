cmake_minimum_required(VERSION 3.5) 

project(Multithread)


add_definitions(-std=c++11)

include_directories(../../Navio)

set(SOURSE
	threaded_baro.cpp
	)
add_executable(Multithread ${SOURSE})

target_link_libraries(Multithread Navio -pthread)
