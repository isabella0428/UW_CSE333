# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/isabella/Desktop/CSE333/Exercise/EX4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex4.dir/flags.make

CMakeFiles/ex4.dir/Vector.c.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/Vector.c.o: ../Vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ex4.dir/Vector.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ex4.dir/Vector.c.o   -c /Users/isabella/Desktop/CSE333/Exercise/EX4/Vector.c

CMakeFiles/ex4.dir/Vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex4.dir/Vector.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/isabella/Desktop/CSE333/Exercise/EX4/Vector.c > CMakeFiles/ex4.dir/Vector.c.i

CMakeFiles/ex4.dir/Vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex4.dir/Vector.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/isabella/Desktop/CSE333/Exercise/EX4/Vector.c -o CMakeFiles/ex4.dir/Vector.c.s

CMakeFiles/ex4.dir/ex4.c.o: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/ex4.c.o: ../ex4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ex4.dir/ex4.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ex4.dir/ex4.c.o   -c /Users/isabella/Desktop/CSE333/Exercise/EX4/ex4.c

CMakeFiles/ex4.dir/ex4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex4.dir/ex4.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/isabella/Desktop/CSE333/Exercise/EX4/ex4.c > CMakeFiles/ex4.dir/ex4.c.i

CMakeFiles/ex4.dir/ex4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex4.dir/ex4.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/isabella/Desktop/CSE333/Exercise/EX4/ex4.c -o CMakeFiles/ex4.dir/ex4.c.s

# Object files for target ex4
ex4_OBJECTS = \
"CMakeFiles/ex4.dir/Vector.c.o" \
"CMakeFiles/ex4.dir/ex4.c.o"

# External object files for target ex4
ex4_EXTERNAL_OBJECTS =

ex4: CMakeFiles/ex4.dir/Vector.c.o
ex4: CMakeFiles/ex4.dir/ex4.c.o
ex4: CMakeFiles/ex4.dir/build.make
ex4: CMakeFiles/ex4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ex4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex4.dir/build: ex4

.PHONY : CMakeFiles/ex4.dir/build

CMakeFiles/ex4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex4.dir/clean

CMakeFiles/ex4.dir/depend:
	cd /Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/isabella/Desktop/CSE333/Exercise/EX4 /Users/isabella/Desktop/CSE333/Exercise/EX4 /Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug /Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug /Users/isabella/Desktop/CSE333/Exercise/EX4/cmake-build-debug/CMakeFiles/ex4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex4.dir/depend
