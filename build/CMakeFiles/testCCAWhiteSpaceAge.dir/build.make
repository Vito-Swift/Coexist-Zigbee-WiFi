# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Coexist-Zigbee-Wifi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Coexist-Zigbee-Wifi/build

# Include any dependencies generated for this target.
include CMakeFiles/testCCAWhiteSpaceAge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testCCAWhiteSpaceAge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o: ../testCCAWhiteSpaceAge.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o -c /home/pi/Coexist-Zigbee-Wifi/testCCAWhiteSpaceAge.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-Wifi/testCCAWhiteSpaceAge.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-Wifi/testCCAWhiteSpaceAge.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o: ../driver/CC2520.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o -c /home/pi/Coexist-Zigbee-Wifi/driver/CC2520.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-Wifi/driver/CC2520.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-Wifi/driver/CC2520.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.s

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o: ../driver/CC2520_HW.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o -c /home/pi/Coexist-Zigbee-Wifi/driver/CC2520_HW.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-Wifi/driver/CC2520_HW.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-Wifi/driver/CC2520_HW.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.s

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o: ../cca_utils/cca_utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o -c /home/pi/Coexist-Zigbee-Wifi/cca_utils/cca_utils.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-Wifi/cca_utils/cca_utils.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-Wifi/cca_utils/cca_utils.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s

# Object files for target testCCAWhiteSpaceAge
testCCAWhiteSpaceAge_OBJECTS = \
"CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o"

# External object files for target testCCAWhiteSpaceAge
testCCAWhiteSpaceAge_EXTERNAL_OBJECTS =

testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/build.make
testCCAWhiteSpaceAge: libDRIVER_LIB.a
testCCAWhiteSpaceAge: /usr/lib/libwiringPi.so
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable testCCAWhiteSpaceAge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testCCAWhiteSpaceAge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testCCAWhiteSpaceAge.dir/build: testCCAWhiteSpaceAge

.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/build

CMakeFiles/testCCAWhiteSpaceAge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testCCAWhiteSpaceAge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/clean

CMakeFiles/testCCAWhiteSpaceAge.dir/depend:
	cd /home/pi/Coexist-Zigbee-Wifi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Coexist-Zigbee-Wifi /home/pi/Coexist-Zigbee-Wifi /home/pi/Coexist-Zigbee-Wifi/build /home/pi/Coexist-Zigbee-Wifi/build /home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles/testCCAWhiteSpaceAge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/depend

