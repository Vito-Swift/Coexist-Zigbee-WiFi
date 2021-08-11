project(ZigBeeTestbed)
message(${CMAKE_CURRENT_SOURCE_DIR})

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DRIVER_SRCS
    driver/CC2520.c
    driver/CC2520_HW.c)
set(DRIVER_INCLUDE
    driver/CC2520.h
    driver/CC2520_HW.h)
include_directories(driver)
add_definitions(-L/usr/lib/libwiringPi.so -lwiringPi)
add_library(CC2520_LIB SHARED ${DRIVER_SRCS} ${DRIVER_INCLUDE})

add_executable(test_cca test_cca.cpp)
target_link_libraries(test_cca PRIVATE CC2520_LIB)
