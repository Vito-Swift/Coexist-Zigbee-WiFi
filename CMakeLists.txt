project(ZigBeeTestbed)
message(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 11)
set (CMAKE_C_FLAGS "-std=c11 ${CMAKE_C_FLAGS}")
cmake_minimum_required(VERSION 3.7)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

set(DRIVER_SRCS
        driver/CC2520.c
        driver/CC2520_HW.c
        cca_utils/cca_utils.cc)
set(DRIVER_INCLUDE
        driver/CC2520.h
        driver/CC2520_HW.h
        cca_utils/cca_utils.h)
include_directories(driver)

add_library(DRIVER_LIB ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(DRIVER_LIB PRIVATE pthread)

add_executable(test_cca test_cca.c ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca PRIVATE Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca PRIVATE pthread)

add_executable(test_cca_sample test_cca_sample.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca_sample DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca_sample PRIVATE pthread)
