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
CMAKE_SOURCE_DIR = /tmp/tmp.XKlURGbl6R

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi

# Include any dependencies generated for this target.
include CMakeFiles/test_cca.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_cca.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_cca.dir/flags.make

CMakeFiles/test_cca.dir/test_cca.cc.o: CMakeFiles/test_cca.dir/flags.make
CMakeFiles/test_cca.dir/test_cca.cc.o: ../test_cca.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_cca.dir/test_cca.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cca.dir/test_cca.cc.o -c /tmp/tmp.XKlURGbl6R/test_cca.cc

CMakeFiles/test_cca.dir/test_cca.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cca.dir/test_cca.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.XKlURGbl6R/test_cca.cc > CMakeFiles/test_cca.dir/test_cca.cc.i

CMakeFiles/test_cca.dir/test_cca.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cca.dir/test_cca.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.XKlURGbl6R/test_cca.cc -o CMakeFiles/test_cca.dir/test_cca.cc.s

CMakeFiles/test_cca.dir/driver/CC2520.cc.o: CMakeFiles/test_cca.dir/flags.make
CMakeFiles/test_cca.dir/driver/CC2520.cc.o: ../driver/CC2520.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_cca.dir/driver/CC2520.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cca.dir/driver/CC2520.cc.o -c /tmp/tmp.XKlURGbl6R/driver/CC2520.cc

CMakeFiles/test_cca.dir/driver/CC2520.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cca.dir/driver/CC2520.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.XKlURGbl6R/driver/CC2520.cc > CMakeFiles/test_cca.dir/driver/CC2520.cc.i

CMakeFiles/test_cca.dir/driver/CC2520.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cca.dir/driver/CC2520.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.XKlURGbl6R/driver/CC2520.cc -o CMakeFiles/test_cca.dir/driver/CC2520.cc.s

CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o: CMakeFiles/test_cca.dir/flags.make
CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o: ../driver/CC2520_HW.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o -c /tmp/tmp.XKlURGbl6R/driver/CC2520_HW.cc

CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.XKlURGbl6R/driver/CC2520_HW.cc > CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.i

CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.XKlURGbl6R/driver/CC2520_HW.cc -o CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.s

CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o: CMakeFiles/test_cca.dir/flags.make
CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o: ../cca_utils/cca_utils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o -c /tmp/tmp.XKlURGbl6R/cca_utils/cca_utils.cc

CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.XKlURGbl6R/cca_utils/cca_utils.cc > CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.i

CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.XKlURGbl6R/cca_utils/cca_utils.cc -o CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.s

# Object files for target test_cca
test_cca_OBJECTS = \
"CMakeFiles/test_cca.dir/test_cca.cc.o" \
"CMakeFiles/test_cca.dir/driver/CC2520.cc.o" \
"CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o" \
"CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o"

# External object files for target test_cca
test_cca_EXTERNAL_OBJECTS =

test_cca: CMakeFiles/test_cca.dir/test_cca.cc.o
test_cca: CMakeFiles/test_cca.dir/driver/CC2520.cc.o
test_cca: CMakeFiles/test_cca.dir/driver/CC2520_HW.cc.o
test_cca: CMakeFiles/test_cca.dir/cca_utils/cca_utils.cc.o
test_cca: CMakeFiles/test_cca.dir/build.make
test_cca: /usr/lib/libwiringPi.so
test_cca: CMakeFiles/test_cca.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable test_cca"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_cca.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_cca.dir/build: test_cca

.PHONY : CMakeFiles/test_cca.dir/build

CMakeFiles/test_cca.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_cca.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_cca.dir/clean

CMakeFiles/test_cca.dir/depend:
	cd /tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.XKlURGbl6R /tmp/tmp.XKlURGbl6R /tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi /tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi /tmp/tmp.XKlURGbl6R/cmake-build-release-raspberrypi/CMakeFiles/test_cca.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_cca.dir/depend

