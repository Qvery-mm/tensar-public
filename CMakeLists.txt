cmake_minimum_required(VERSION 2.8)
project( workshop )
find_package( OpenCV REQUIRED )
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( main main.cpp FindLines.cpp FindLines.h Interface.cpp Interface.h configuration.h FindBreaks.h
        FindBreaks.cpp PrepareImage.h PrepareImage.cpp experimental.cpp experimental.h configuration.cpp)
target_link_libraries( main ${OpenCV_LIBS} )
target_link_libraries( main ${WIRINGPI_LIBRARIES}) 
