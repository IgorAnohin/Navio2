add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Common")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Navio2")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Navio+")

include_directories(.)
add_definitions(-std=c++11)

add_library(Navio ${HeadersCommon} ${LibrariesCommon} ${LibrariesNavio+} ${HeadersNavio+} ${LibrariesNavio2} ${HeadersNavio2} ) 

