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
include CMakeFiles/auto_cca_collect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/auto_cca_collect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/auto_cca_collect.dir/flags.make

CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o: CMakeFiles/auto_cca_collect.dir/flags.make
CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o: ../auto_cca_collect.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o -c /home/pi/Coexist-Zigbee-Wifi/auto_cca_collect.cc

CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Coexist-Zigbee-Wifi/auto_cca_collect.cc > CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.i

CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Coexist-Zigbee-Wifi/auto_cca_collect.cc -o CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.s

# Object files for target auto_cca_collect
auto_cca_collect_OBJECTS = \
"CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o"

# External object files for target auto_cca_collect
auto_cca_collect_EXTERNAL_OBJECTS =

auto_cca_collect: CMakeFiles/auto_cca_collect.dir/auto_cca_collect.cc.o
auto_cca_collect: CMakeFiles/auto_cca_collect.dir/build.make
auto_cca_collect: libDRIVER_LIB.a
auto_cca_collect: /usr/lib/libwiringPi.so
auto_cca_collect: CMakeFiles/auto_cca_collect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable auto_cca_collect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/auto_cca_collect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/auto_cca_collect.dir/build: auto_cca_collect

.PHONY : CMakeFiles/auto_cca_collect.dir/build

CMakeFiles/auto_cca_collect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/auto_cca_collect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/auto_cca_collect.dir/clean

CMakeFiles/auto_cca_collect.dir/depend:
	cd /home/pi/Coexist-Zigbee-Wifi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Coexist-Zigbee-Wifi /home/pi/Coexist-Zigbee-Wifi /home/pi/Coexist-Zigbee-Wifi/build /home/pi/Coexist-Zigbee-Wifi/build /home/pi/Coexist-Zigbee-Wifi/build/CMakeFiles/auto_cca_collect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/auto_cca_collect.dir/depend

