# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/danny.paleyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/danny.paleyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danny.paleyev/PathPlanningProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danny.paleyev/PathPlanningProject/cmake-build-debug

# Include any dependencies generated for this target.
include Tests/CMakeFiles/testbench.dir/depend.make
# Include the progress variables for this target.
include Tests/CMakeFiles/testbench.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/testbench.dir/flags.make

Tests/CMakeFiles/testbench.dir/testbench.cpp.o: Tests/CMakeFiles/testbench.dir/flags.make
Tests/CMakeFiles/testbench.dir/testbench.cpp.o: ../Tests/testbench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/testbench.dir/testbench.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testbench.dir/testbench.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Tests/testbench.cpp

Tests/CMakeFiles/testbench.dir/testbench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testbench.dir/testbench.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Tests/testbench.cpp > CMakeFiles/testbench.dir/testbench.cpp.i

Tests/CMakeFiles/testbench.dir/testbench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testbench.dir/testbench.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Tests/testbench.cpp -o CMakeFiles/testbench.dir/testbench.cpp.s

# Object files for target testbench
testbench_OBJECTS = \
"CMakeFiles/testbench.dir/testbench.cpp.o"

# External object files for target testbench
testbench_EXTERNAL_OBJECTS =

Tests/testbench: Tests/CMakeFiles/testbench.dir/testbench.cpp.o
Tests/testbench: Tests/CMakeFiles/testbench.dir/build.make
Tests/testbench: Src/libPPLIB.a
Tests/testbench: Tests/CMakeFiles/testbench.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testbench"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testbench.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeFiles/testbench.dir/build: Tests/testbench
.PHONY : Tests/CMakeFiles/testbench.dir/build

Tests/CMakeFiles/testbench.dir/clean:
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests && $(CMAKE_COMMAND) -P CMakeFiles/testbench.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/testbench.dir/clean

Tests/CMakeFiles/testbench.dir/depend:
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danny.paleyev/PathPlanningProject /Users/danny.paleyev/PathPlanningProject/Tests /Users/danny.paleyev/PathPlanningProject/cmake-build-debug /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Tests/CMakeFiles/testbench.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/testbench.dir/depend

