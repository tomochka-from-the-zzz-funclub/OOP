# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tamara/2_cours/OOP/lab_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tamara/2_cours/OOP/lab_4

# Utility rule file for start_test_point.

# Include any custom commands dependencies for this target.
include CMakeFiles/start_test_point.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/start_test_point.dir/progress.make

CMakeFiles/start_test_point: test_point
	./test_point

start_test_point: CMakeFiles/start_test_point
start_test_point: CMakeFiles/start_test_point.dir/build.make
.PHONY : start_test_point

# Rule to build all files generated by this target.
CMakeFiles/start_test_point.dir/build: start_test_point
.PHONY : CMakeFiles/start_test_point.dir/build

CMakeFiles/start_test_point.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/start_test_point.dir/cmake_clean.cmake
.PHONY : CMakeFiles/start_test_point.dir/clean

CMakeFiles/start_test_point.dir/depend:
	cd /home/tamara/2_cours/OOP/lab_4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tamara/2_cours/OOP/lab_4 /home/tamara/2_cours/OOP/lab_4 /home/tamara/2_cours/OOP/lab_4 /home/tamara/2_cours/OOP/lab_4 /home/tamara/2_cours/OOP/lab_4/CMakeFiles/start_test_point.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/start_test_point.dir/depend

