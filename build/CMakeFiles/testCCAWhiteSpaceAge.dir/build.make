# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Coexist-Zigbee-WiFi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Coexist-Zigbee-WiFi/build

# Include any dependencies generated for this target.
include CMakeFiles/testCCAWhiteSpaceAge.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testCCAWhiteSpaceAge.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o: ../testCCAWhiteSpaceAge.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o -c /home/pi/Coexist-Zigbee-WiFi/testCCAWhiteSpaceAge.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-WiFi/testCCAWhiteSpaceAge.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-WiFi/testCCAWhiteSpaceAge.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.s

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o: ../driver/CC2520.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o   -c /home/pi/Coexist-Zigbee-WiFi/driver/CC2520.c

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Coexist-Zigbee-WiFi/driver/CC2520.c > CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.i

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Coexist-Zigbee-WiFi/driver/CC2520.c -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.s

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o: ../driver/CC2520_HW.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o   -c /home/pi/Coexist-Zigbee-WiFi/driver/CC2520_HW.c

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Coexist-Zigbee-WiFi/driver/CC2520_HW.c > CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.i

CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Coexist-Zigbee-WiFi/driver/CC2520_HW.c -o CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.s

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o: CMakeFiles/testCCAWhiteSpaceAge.dir/flags.make
CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o: ../cca_utils/cca_utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o -c /home/pi/Coexist-Zigbee-WiFi/cca_utils/cca_utils.cc

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-WiFi/cca_utils/cca_utils.cc > CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.i

CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-WiFi/cca_utils/cca_utils.cc -o CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.s

# Object files for target testCCAWhiteSpaceAge
testCCAWhiteSpaceAge_OBJECTS = \
"CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o" \
"CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o"

# External object files for target testCCAWhiteSpaceAge
testCCAWhiteSpaceAge_EXTERNAL_OBJECTS =

testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/testCCAWhiteSpaceAge.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520.c.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/driver/CC2520_HW.c.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/cca_utils/cca_utils.cc.o
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/build.make
testCCAWhiteSpaceAge: libDRIVER_LIB.a
testCCAWhiteSpaceAge: /usr/lib/libwiringPi.so
testCCAWhiteSpaceAge: CMakeFiles/testCCAWhiteSpaceAge.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable testCCAWhiteSpaceAge"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testCCAWhiteSpaceAge.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testCCAWhiteSpaceAge.dir/build: testCCAWhiteSpaceAge

.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/build

CMakeFiles/testCCAWhiteSpaceAge.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testCCAWhiteSpaceAge.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/clean

CMakeFiles/testCCAWhiteSpaceAge.dir/depend:
	cd /home/pi/Coexist-Zigbee-WiFi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Coexist-Zigbee-WiFi /home/pi/Coexist-Zigbee-WiFi /home/pi/Coexist-Zigbee-WiFi/build /home/pi/Coexist-Zigbee-WiFi/build /home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles/testCCAWhiteSpaceAge.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testCCAWhiteSpaceAge.dir/depend

