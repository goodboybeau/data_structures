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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jaronhalt/dev/lnklst/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jaronhalt/dev/lnklst/bb

# Include any dependencies generated for this target.
include lnklst/CMakeFiles/lnklst.dir/depend.make

# Include the progress variables for this target.
include lnklst/CMakeFiles/lnklst.dir/progress.make

# Include the compile flags for this target's objects.
include lnklst/CMakeFiles/lnklst.dir/flags.make

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o: lnklst/CMakeFiles/lnklst.dir/flags.make
lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o: /home/jaronhalt/dev/lnklst/src/lnklst/lnklst.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaronhalt/dev/lnklst/bb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o"
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/lnklst.dir/lnklst.cpp.o -c /home/jaronhalt/dev/lnklst/src/lnklst/lnklst.cpp

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lnklst.dir/lnklst.cpp.i"
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jaronhalt/dev/lnklst/src/lnklst/lnklst.cpp > CMakeFiles/lnklst.dir/lnklst.cpp.i

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lnklst.dir/lnklst.cpp.s"
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jaronhalt/dev/lnklst/src/lnklst/lnklst.cpp -o CMakeFiles/lnklst.dir/lnklst.cpp.s

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.requires:

.PHONY : lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.requires

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.provides: lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.requires
	$(MAKE) -f lnklst/CMakeFiles/lnklst.dir/build.make lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.provides.build
.PHONY : lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.provides

lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.provides.build: lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o


# Object files for target lnklst
lnklst_OBJECTS = \
"CMakeFiles/lnklst.dir/lnklst.cpp.o"

# External object files for target lnklst
lnklst_EXTERNAL_OBJECTS =

lnklst/liblnklst.a: lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o
lnklst/liblnklst.a: lnklst/CMakeFiles/lnklst.dir/build.make
lnklst/liblnklst.a: lnklst/CMakeFiles/lnklst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jaronhalt/dev/lnklst/bb/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblnklst.a"
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && $(CMAKE_COMMAND) -P CMakeFiles/lnklst.dir/cmake_clean_target.cmake
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lnklst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lnklst/CMakeFiles/lnklst.dir/build: lnklst/liblnklst.a

.PHONY : lnklst/CMakeFiles/lnklst.dir/build

lnklst/CMakeFiles/lnklst.dir/requires: lnklst/CMakeFiles/lnklst.dir/lnklst.cpp.o.requires

.PHONY : lnklst/CMakeFiles/lnklst.dir/requires

lnklst/CMakeFiles/lnklst.dir/clean:
	cd /home/jaronhalt/dev/lnklst/bb/lnklst && $(CMAKE_COMMAND) -P CMakeFiles/lnklst.dir/cmake_clean.cmake
.PHONY : lnklst/CMakeFiles/lnklst.dir/clean

lnklst/CMakeFiles/lnklst.dir/depend:
	cd /home/jaronhalt/dev/lnklst/bb && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jaronhalt/dev/lnklst/src /home/jaronhalt/dev/lnklst/src/lnklst /home/jaronhalt/dev/lnklst/bb /home/jaronhalt/dev/lnklst/bb/lnklst /home/jaronhalt/dev/lnklst/bb/lnklst/CMakeFiles/lnklst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lnklst/CMakeFiles/lnklst.dir/depend
