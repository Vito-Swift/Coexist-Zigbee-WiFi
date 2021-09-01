project(ZigBeeTestbed)
message(${CMAKE_CURRENT_SOURCE_DIR})
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

set(WISE_SRC
        WISE/WISE.h
        WISE/WISE_Send.c
        WISE/WISE_Recv.c
        WISE/Utils.c)

include_directories(driver)
include_directories(WISE)

add_library(DRIVER_LIB ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(DRIVER_LIB PRIVATE pthread)

add_library(WISE_LIB ${WISE_SRC})
target_link_libraries(WISE_LIB PRIVATE DRIVER_LIB)

add_executable(test_cca test_cca.c ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca PRIVATE Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca PRIVATE pthread)

add_executable(test_cca_sample test_cca_sample.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca_sample DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca_sample PRIVATE pthread)


add_executable(test_driver test_driver.c)
target_link_libraries(test_driver PRIVATE DRIVER_LIB)

add_executable(test_wise test_wise.c)
target_link_libraries(test_wise PRIVATE WISE_LIB DRIVER_LIB)

add_executable(auto_cca_collect auto_cca_collect.cc)
target_link_libraries(auto_cca_collect PRIVATE DRIVER_LIB)

add_executable(testCCAWhiteSpaceAge testCCAWhiteSpaceAge.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(testCCAWhiteSpaceAge DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(testCCAWhiteSpaceAge PRIVATE pthread)
