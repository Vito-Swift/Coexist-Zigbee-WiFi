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
include CMakeFiles/test_wise.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_wise.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_wise.dir/flags.make

CMakeFiles/test_wise.dir/test_wise.c.o: CMakeFiles/test_wise.dir/flags.make
CMakeFiles/test_wise.dir/test_wise.c.o: ../test_wise.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_wise.dir/test_wise.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_wise.dir/test_wise.c.o   -c /home/pi/Coexist-Zigbee-WiFi/test_wise.c

CMakeFiles/test_wise.dir/test_wise.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_wise.dir/test_wise.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Coexist-Zigbee-WiFi/test_wise.c > CMakeFiles/test_wise.dir/test_wise.c.i

CMakeFiles/test_wise.dir/test_wise.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_wise.dir/test_wise.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Coexist-Zigbee-WiFi/test_wise.c -o CMakeFiles/test_wise.dir/test_wise.c.s

# Object files for target test_wise
test_wise_OBJECTS = \
"CMakeFiles/test_wise.dir/test_wise.c.o"

# External object files for target test_wise
test_wise_EXTERNAL_OBJECTS =

test_wise: CMakeFiles/test_wise.dir/test_wise.c.o
test_wise: CMakeFiles/test_wise.dir/build.make
test_wise: libWISE_LIB.a
test_wise: libDRIVER_LIB.a
test_wise: /usr/lib/libwiringPi.so
test_wise: CMakeFiles/test_wise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_wise"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_wise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_wise.dir/build: test_wise

.PHONY : CMakeFiles/test_wise.dir/build

CMakeFiles/test_wise.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_wise.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_wise.dir/clean

CMakeFiles/test_wise.dir/depend:
	cd /home/pi/Coexist-Zigbee-WiFi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Coexist-Zigbee-WiFi /home/pi/Coexist-Zigbee-WiFi /home/pi/Coexist-Zigbee-WiFi/build /home/pi/Coexist-Zigbee-WiFi/build /home/pi/Coexist-Zigbee-WiFi/build/CMakeFiles/test_wise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_wise.dir/depend

