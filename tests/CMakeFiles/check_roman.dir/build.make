# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Cavicchio/roman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Cavicchio/roman

# Include any dependencies generated for this target.
include tests/CMakeFiles/check_roman.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/check_roman.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/check_roman.dir/flags.make

tests/CMakeFiles/check_roman.dir/check_roman.c.o: tests/CMakeFiles/check_roman.dir/flags.make
tests/CMakeFiles/check_roman.dir/check_roman.c.o: tests/check_roman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Cavicchio/roman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/check_roman.dir/check_roman.c.o"
	cd /home/Cavicchio/roman/tests && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/check_roman.dir/check_roman.c.o   -c /home/Cavicchio/roman/tests/check_roman.c

tests/CMakeFiles/check_roman.dir/check_roman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/check_roman.dir/check_roman.c.i"
	cd /home/Cavicchio/roman/tests && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/Cavicchio/roman/tests/check_roman.c > CMakeFiles/check_roman.dir/check_roman.c.i

tests/CMakeFiles/check_roman.dir/check_roman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/check_roman.dir/check_roman.c.s"
	cd /home/Cavicchio/roman/tests && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/Cavicchio/roman/tests/check_roman.c -o CMakeFiles/check_roman.dir/check_roman.c.s

tests/CMakeFiles/check_roman.dir/check_roman.c.o.requires:

.PHONY : tests/CMakeFiles/check_roman.dir/check_roman.c.o.requires

tests/CMakeFiles/check_roman.dir/check_roman.c.o.provides: tests/CMakeFiles/check_roman.dir/check_roman.c.o.requires
	$(MAKE) -f tests/CMakeFiles/check_roman.dir/build.make tests/CMakeFiles/check_roman.dir/check_roman.c.o.provides.build
.PHONY : tests/CMakeFiles/check_roman.dir/check_roman.c.o.provides

tests/CMakeFiles/check_roman.dir/check_roman.c.o.provides.build: tests/CMakeFiles/check_roman.dir/check_roman.c.o


# Object files for target check_roman
check_roman_OBJECTS = \
"CMakeFiles/check_roman.dir/check_roman.c.o"

# External object files for target check_roman
check_roman_EXTERNAL_OBJECTS =

tests/check_roman.exe: tests/CMakeFiles/check_roman.dir/check_roman.c.o
tests/check_roman.exe: tests/CMakeFiles/check_roman.dir/build.make
tests/check_roman.exe: src/libroman.a
tests/check_roman.exe: tests/CMakeFiles/check_roman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Cavicchio/roman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable check_roman.exe"
	cd /home/Cavicchio/roman/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/check_roman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/check_roman.dir/build: tests/check_roman.exe

.PHONY : tests/CMakeFiles/check_roman.dir/build

tests/CMakeFiles/check_roman.dir/requires: tests/CMakeFiles/check_roman.dir/check_roman.c.o.requires

.PHONY : tests/CMakeFiles/check_roman.dir/requires

tests/CMakeFiles/check_roman.dir/clean:
	cd /home/Cavicchio/roman/tests && $(CMAKE_COMMAND) -P CMakeFiles/check_roman.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/check_roman.dir/clean

tests/CMakeFiles/check_roman.dir/depend:
	cd /home/Cavicchio/roman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Cavicchio/roman /home/Cavicchio/roman/tests /home/Cavicchio/roman /home/Cavicchio/roman/tests /home/Cavicchio/roman/tests/CMakeFiles/check_roman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/check_roman.dir/depend
