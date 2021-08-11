project(ZigBeeTestbed)
message(${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.7)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(DRIVER_SRCS
        driver/CC2520.c
        driver/CC2520_HW.c
        cca_utils/cca_utils.c)
set(DRIVER_INCLUDE
        driver/CC2520.h
        driver/CC2520_HW.h
        cca_utils/cca_utils.h)

set(WISE_SRC
        WISE/WISE.h
        WISE/WISE_Send.c
        WISE/WISE_Recv.c
        WISE/Utils.c)

include_directories(driver)
include_directories(WISE)

add_definitions(-L/usr/lib/libwiringPi.so -lwiringPi)
set(CMAKE_CXX_FLAGS "-L/usr/lib/libwiringPi.so -lwiringPi")
set(CMAKE_C_FLAGS "-L/usr/lib/libwiringPi.so -lwiringPi")
add_library(DRIVER_LIB ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(DRIVER_LIB PRIVATE Threads::Threads)
target_include_directories(DRIVER_LIB PRIVATE pthread)

add_library(WISE_LIB ${WISE_SRC})
target_link_libraries(WISE_LIB PRIVATE DRIVER_LIB)

add_executable(test_cca test_cca.c ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca PRIVATE DRIVER_LIB Threads::Threads)
target_include_directories(test_cca PRIVATE pthread)

add_executable(test_driver test_driver.c)
target_link_libraries(test_driver PRIVATE DRIVER_LIB)

add_executable(test_wise test_wise.c)
target_link_libraries(test_wise PRIVATE WISE_LIB DRIVER_LIB)