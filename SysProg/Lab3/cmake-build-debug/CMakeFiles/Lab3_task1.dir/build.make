# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/kate/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/kate/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/191.6707.69/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kate/CLionProjects/SysProg/Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab3_task1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab3_task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab3_task1.dir/flags.make

CMakeFiles/Lab3_task1.dir/task1/main.c.o: CMakeFiles/Lab3_task1.dir/flags.make
CMakeFiles/Lab3_task1.dir/task1/main.c.o: ../task1/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab3_task1.dir/task1/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Lab3_task1.dir/task1/main.c.o   -c /Users/kate/CLionProjects/SysProg/Lab3/task1/main.c

CMakeFiles/Lab3_task1.dir/task1/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab3_task1.dir/task1/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kate/CLionProjects/SysProg/Lab3/task1/main.c > CMakeFiles/Lab3_task1.dir/task1/main.c.i

CMakeFiles/Lab3_task1.dir/task1/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab3_task1.dir/task1/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kate/CLionProjects/SysProg/Lab3/task1/main.c -o CMakeFiles/Lab3_task1.dir/task1/main.c.s

# Object files for target Lab3_task1
Lab3_task1_OBJECTS = \
"CMakeFiles/Lab3_task1.dir/task1/main.c.o"

# External object files for target Lab3_task1
Lab3_task1_EXTERNAL_OBJECTS =

Lab3_task1: CMakeFiles/Lab3_task1.dir/task1/main.c.o
Lab3_task1: CMakeFiles/Lab3_task1.dir/build.make
Lab3_task1: CMakeFiles/Lab3_task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab3_task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab3_task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab3_task1.dir/build: Lab3_task1

.PHONY : CMakeFiles/Lab3_task1.dir/build

CMakeFiles/Lab3_task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab3_task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab3_task1.dir/clean

CMakeFiles/Lab3_task1.dir/depend:
	cd /Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kate/CLionProjects/SysProg/Lab3 /Users/kate/CLionProjects/SysProg/Lab3 /Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug /Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug /Users/kate/CLionProjects/SysProg/Lab3/cmake-build-debug/CMakeFiles/Lab3_task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab3_task1.dir/depend
