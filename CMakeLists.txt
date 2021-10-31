##################################################################################
######### PROJECT DEFINITIONS AND DEPENDENCIES
##################################################################################
project(ZigBeeTestbed)
message(${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.7)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)

##################################################################################
######### VARIABLES
##################################################################################
set(DRIVER_SRCS
        driver/CC2520.cc
        driver/CC2520_HW.cc
        cca_utils/cca_utils.cc)

set(DRIVER_INCLUDE
        driver/CC2520.h
        driver/CC2520_HW.h
        cca_utils/cca_utils.h)

set(WISE_SRC
        WISE/WISE.h
        WISE/WISE_Send.cc
        WISE/WISE_Recv.cc
        WISE/Utils.cc)

set(LEAD_SRC
        LEAD/LEAD.hh
        LEAD/LEAD_Send.cc
        LEAD/LEAD_Recv.cc)

##################################################################################
######### INCLUDE DIRECTORIES
##################################################################################
include_directories(driver)
include_directories(WISE)
include_directories(LEAD)

##################################################################################
######### ADD AUXILIARY LIBRARIES
##################################################################################
add_library(DRIVER_LIB ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(DRIVER_LIB PRIVATE pthread)

add_library(WISE_LIB ${WISE_SRC})
target_link_libraries(WISE_LIB PRIVATE DRIVER_LIB)

add_library(LEAD_LIB ${LEAD_SRC})
target_include_directories(LEAD_LIB PRIVATE "/usr/local/include/")
target_link_libraries(LEAD_LIB PRIVATE DRIVER_LIB correct correct_static)

##################################################################################
######### ADD WISE PROJECT TARGETS
##################################################################################
add_executable(test_cca test_cca.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca PRIVATE Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca PRIVATE pthread)

add_executable(test_cca_sample test_cca_sample.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_cca_sample DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(test_cca_sample PRIVATE pthread)

add_executable(test_driver test_driver.cc)
target_link_libraries(test_driver PRIVATE DRIVER_LIB)

add_executable(test_wise test_wise.cc)
target_link_libraries(test_wise PRIVATE WISE_LIB DRIVER_LIB)

add_executable(auto_cca_collect auto_cca_collect.cc)
target_link_libraries(auto_cca_collect PRIVATE DRIVER_LIB)

add_executable(testCCAWhiteSpaceAge testCCAWhiteSpaceAge.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(testCCAWhiteSpaceAge DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES})
target_include_directories(testCCAWhiteSpaceAge PRIVATE pthread)

add_executable(test_wise_throughput test_wise_throughput.cc ${DRIVER_SRCS} ${DRIVER_INCLUDE})
target_link_libraries(test_wise_throughput DRIVER_LIB Threads::Threads ${WIRINGPI_LIBRARIES} WISE_LIB)
target_include_directories(test_wise_throughput PRIVATE pthread)

##################################################################################
######### ADD LEAD PROJECT TARGETS
##################################################################################
