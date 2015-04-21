cmake_minimum_required(VERSION 2.8.3)
project(ColorTracker)

find_package(OpenCV REQUIRED)

include_directories(${ColorTracker_SOURCE_DIR}/include)

if (OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
  set(LIBS ${LIBS} ${OpenCV_LIBS})
  message(STATUS ${OpenCV_INCLUDE_DIRS})
  message(STATUS ${LIBS})
endif (OpenCV_FOUND)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

set(ColorTracker_SOURCES
    src/color_tracker.cpp
    src/color_tracker_parameters.cpp    
)

set(ColorTracker_INCLUDES
    include/ColorTracker/color_tracker.hpp
    include/ColorTracker/color_tracker_parameters.hpp
    include/ColorTracker/vot.hpp
)

add_executable( demo-video src/demo-video.cpp ${ColorTracker_SOURCES} ${ColorTracker_INCLUDES})
add_executable( demo-vot src/demo-vot.cpp ${ColorTracker_SOURCES} ${ColorTracker_INCLUDES})

target_link_libraries(demo-video ${LIBS} )
target_link_libraries(demo-vot ${LIBS} )
