# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "/Users/danny.paleyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.5744.254/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/danny.paleyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.5744.254/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danny.paleyev/PathPlanningProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danny.paleyev/PathPlanningProject/cmake-build-debug

# Include any dependencies generated for this target.
include Src/CMakeFiles/PPLIB.dir/depend.make
# Include the progress variables for this target.
include Src/CMakeFiles/PPLIB.dir/progress.make

# Include the compile flags for this target's objects.
include Src/CMakeFiles/PPLIB.dir/flags.make

Src/CMakeFiles/PPLIB.dir/MDD.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/MDD.cpp.o: ../Src/MDD.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Src/CMakeFiles/PPLIB.dir/MDD.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/MDD.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/MDD.cpp

Src/CMakeFiles/PPLIB.dir/MDD.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/MDD.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/MDD.cpp > CMakeFiles/PPLIB.dir/MDD.cpp.i

Src/CMakeFiles/PPLIB.dir/MDD.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/MDD.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/MDD.cpp -o CMakeFiles/PPLIB.dir/MDD.cpp.s

Src/CMakeFiles/PPLIB.dir/config.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/config.cpp.o: ../Src/config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Src/CMakeFiles/PPLIB.dir/config.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/config.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/config.cpp

Src/CMakeFiles/PPLIB.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/config.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/config.cpp > CMakeFiles/PPLIB.dir/config.cpp.i

Src/CMakeFiles/PPLIB.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/config.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/config.cpp -o CMakeFiles/PPLIB.dir/config.cpp.s

Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.o: ../Src/environmentoptions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/environmentoptions.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/environmentoptions.cpp

Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/environmentoptions.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/environmentoptions.cpp > CMakeFiles/PPLIB.dir/environmentoptions.cpp.i

Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/environmentoptions.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/environmentoptions.cpp -o CMakeFiles/PPLIB.dir/environmentoptions.cpp.s

Src/CMakeFiles/PPLIB.dir/map.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/map.cpp.o: ../Src/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Src/CMakeFiles/PPLIB.dir/map.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/map.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/map.cpp

Src/CMakeFiles/PPLIB.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/map.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/map.cpp > CMakeFiles/PPLIB.dir/map.cpp.i

Src/CMakeFiles/PPLIB.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/map.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/map.cpp -o CMakeFiles/PPLIB.dir/map.cpp.s

Src/CMakeFiles/PPLIB.dir/mission.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/mission.cpp.o: ../Src/mission.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Src/CMakeFiles/PPLIB.dir/mission.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/mission.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/mission.cpp

Src/CMakeFiles/PPLIB.dir/mission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/mission.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/mission.cpp > CMakeFiles/PPLIB.dir/mission.cpp.i

Src/CMakeFiles/PPLIB.dir/mission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/mission.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/mission.cpp -o CMakeFiles/PPLIB.dir/mission.cpp.s

Src/CMakeFiles/PPLIB.dir/search.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/search.cpp.o: ../Src/search.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Src/CMakeFiles/PPLIB.dir/search.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/search.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/search.cpp

Src/CMakeFiles/PPLIB.dir/search.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/search.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/search.cpp > CMakeFiles/PPLIB.dir/search.cpp.i

Src/CMakeFiles/PPLIB.dir/search.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/search.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/search.cpp -o CMakeFiles/PPLIB.dir/search.cpp.s

Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.o: ../Src/tinyxml2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/tinyxml2.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/tinyxml2.cpp

Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/tinyxml2.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/tinyxml2.cpp > CMakeFiles/PPLIB.dir/tinyxml2.cpp.i

Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/tinyxml2.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/tinyxml2.cpp -o CMakeFiles/PPLIB.dir/tinyxml2.cpp.s

Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.o: ../Src/xmllogger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/xmllogger.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/xmllogger.cpp

Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/xmllogger.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/xmllogger.cpp > CMakeFiles/PPLIB.dir/xmllogger.cpp.i

Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/xmllogger.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/xmllogger.cpp -o CMakeFiles/PPLIB.dir/xmllogger.cpp.s

Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o: ../Src/highLevelSearch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/highLevelSearch.cpp

Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/highLevelSearch.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/highLevelSearch.cpp > CMakeFiles/PPLIB.dir/highLevelSearch.cpp.i

Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/highLevelSearch.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/highLevelSearch.cpp -o CMakeFiles/PPLIB.dir/highLevelSearch.cpp.s

Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.o: Src/CMakeFiles/PPLIB.dir/flags.make
Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.o: ../Src/TreeNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.o"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLIB.dir/TreeNode.cpp.o -c /Users/danny.paleyev/PathPlanningProject/Src/TreeNode.cpp

Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLIB.dir/TreeNode.cpp.i"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danny.paleyev/PathPlanningProject/Src/TreeNode.cpp > CMakeFiles/PPLIB.dir/TreeNode.cpp.i

Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLIB.dir/TreeNode.cpp.s"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danny.paleyev/PathPlanningProject/Src/TreeNode.cpp -o CMakeFiles/PPLIB.dir/TreeNode.cpp.s

# Object files for target PPLIB
PPLIB_OBJECTS = \
"CMakeFiles/PPLIB.dir/MDD.cpp.o" \
"CMakeFiles/PPLIB.dir/config.cpp.o" \
"CMakeFiles/PPLIB.dir/environmentoptions.cpp.o" \
"CMakeFiles/PPLIB.dir/map.cpp.o" \
"CMakeFiles/PPLIB.dir/mission.cpp.o" \
"CMakeFiles/PPLIB.dir/search.cpp.o" \
"CMakeFiles/PPLIB.dir/tinyxml2.cpp.o" \
"CMakeFiles/PPLIB.dir/xmllogger.cpp.o" \
"CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o" \
"CMakeFiles/PPLIB.dir/TreeNode.cpp.o"

# External object files for target PPLIB
PPLIB_EXTERNAL_OBJECTS =

Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/MDD.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/config.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/environmentoptions.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/map.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/mission.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/search.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/tinyxml2.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/xmllogger.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/highLevelSearch.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/TreeNode.cpp.o
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/build.make
Src/libPPLIB.a: Src/CMakeFiles/PPLIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danny.paleyev/PathPlanningProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libPPLIB.a"
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && $(CMAKE_COMMAND) -P CMakeFiles/PPLIB.dir/cmake_clean_target.cmake
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PPLIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Src/CMakeFiles/PPLIB.dir/build: Src/libPPLIB.a
.PHONY : Src/CMakeFiles/PPLIB.dir/build

Src/CMakeFiles/PPLIB.dir/clean:
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src && $(CMAKE_COMMAND) -P CMakeFiles/PPLIB.dir/cmake_clean.cmake
.PHONY : Src/CMakeFiles/PPLIB.dir/clean

Src/CMakeFiles/PPLIB.dir/depend:
	cd /Users/danny.paleyev/PathPlanningProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danny.paleyev/PathPlanningProject /Users/danny.paleyev/PathPlanningProject/Src /Users/danny.paleyev/PathPlanningProject/cmake-build-debug /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src /Users/danny.paleyev/PathPlanningProject/cmake-build-debug/Src/CMakeFiles/PPLIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Src/CMakeFiles/PPLIB.dir/depend

