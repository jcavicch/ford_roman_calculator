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
include src/CMakeFiles/roman.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/roman.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/roman.dir/flags.make

src/CMakeFiles/roman.dir/roman.c.o: src/CMakeFiles/roman.dir/flags.make
src/CMakeFiles/roman.dir/roman.c.o: src/roman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Cavicchio/roman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/roman.dir/roman.c.o"
	cd /home/Cavicchio/roman/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/roman.dir/roman.c.o   -c /home/Cavicchio/roman/src/roman.c

src/CMakeFiles/roman.dir/roman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/roman.dir/roman.c.i"
	cd /home/Cavicchio/roman/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/Cavicchio/roman/src/roman.c > CMakeFiles/roman.dir/roman.c.i

src/CMakeFiles/roman.dir/roman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/roman.dir/roman.c.s"
	cd /home/Cavicchio/roman/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/Cavicchio/roman/src/roman.c -o CMakeFiles/roman.dir/roman.c.s

src/CMakeFiles/roman.dir/roman.c.o.requires:

.PHONY : src/CMakeFiles/roman.dir/roman.c.o.requires

src/CMakeFiles/roman.dir/roman.c.o.provides: src/CMakeFiles/roman.dir/roman.c.o.requires
	$(MAKE) -f src/CMakeFiles/roman.dir/build.make src/CMakeFiles/roman.dir/roman.c.o.provides.build
.PHONY : src/CMakeFiles/roman.dir/roman.c.o.provides

src/CMakeFiles/roman.dir/roman.c.o.provides.build: src/CMakeFiles/roman.dir/roman.c.o


# Object files for target roman
roman_OBJECTS = \
"CMakeFiles/roman.dir/roman.c.o"

# External object files for target roman
roman_EXTERNAL_OBJECTS =

src/libroman.a: src/CMakeFiles/roman.dir/roman.c.o
src/libroman.a: src/CMakeFiles/roman.dir/build.make
src/libroman.a: src/CMakeFiles/roman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Cavicchio/roman/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libroman.a"
	cd /home/Cavicchio/roman/src && $(CMAKE_COMMAND) -P CMakeFiles/roman.dir/cmake_clean_target.cmake
	cd /home/Cavicchio/roman/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/roman.dir/build: src/libroman.a

.PHONY : src/CMakeFiles/roman.dir/build

src/CMakeFiles/roman.dir/requires: src/CMakeFiles/roman.dir/roman.c.o.requires

.PHONY : src/CMakeFiles/roman.dir/requires

src/CMakeFiles/roman.dir/clean:
	cd /home/Cavicchio/roman/src && $(CMAKE_COMMAND) -P CMakeFiles/roman.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/roman.dir/clean

src/CMakeFiles/roman.dir/depend:
	cd /home/Cavicchio/roman && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Cavicchio/roman /home/Cavicchio/roman/src /home/Cavicchio/roman /home/Cavicchio/roman/src /home/Cavicchio/roman/src/CMakeFiles/roman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/roman.dir/depend
