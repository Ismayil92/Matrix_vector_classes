# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ismayil/Qt_workspace/work1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ismayil/Qt_workspace/work1/build

# Include any dependencies generated for this target.
include CMakeFiles/work1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/work1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/work1.dir/flags.make

CMakeFiles/work1.dir/main.cpp.o: CMakeFiles/work1.dir/flags.make
CMakeFiles/work1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ismayil/Qt_workspace/work1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/work1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/work1.dir/main.cpp.o -c /home/ismayil/Qt_workspace/work1/main.cpp

CMakeFiles/work1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/work1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ismayil/Qt_workspace/work1/main.cpp > CMakeFiles/work1.dir/main.cpp.i

CMakeFiles/work1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/work1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ismayil/Qt_workspace/work1/main.cpp -o CMakeFiles/work1.dir/main.cpp.s

CMakeFiles/work1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/work1.dir/main.cpp.o.requires

CMakeFiles/work1.dir/main.cpp.o.provides: CMakeFiles/work1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/work1.dir/build.make CMakeFiles/work1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/work1.dir/main.cpp.o.provides

CMakeFiles/work1.dir/main.cpp.o.provides.build: CMakeFiles/work1.dir/main.cpp.o


# Object files for target work1
work1_OBJECTS = \
"CMakeFiles/work1.dir/main.cpp.o"

# External object files for target work1
work1_EXTERNAL_OBJECTS =

work1: CMakeFiles/work1.dir/main.cpp.o
work1: CMakeFiles/work1.dir/build.make
work1: CMakeFiles/work1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ismayil/Qt_workspace/work1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable work1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/work1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/work1.dir/build: work1

.PHONY : CMakeFiles/work1.dir/build

CMakeFiles/work1.dir/requires: CMakeFiles/work1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/work1.dir/requires

CMakeFiles/work1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/work1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/work1.dir/clean

CMakeFiles/work1.dir/depend:
	cd /home/ismayil/Qt_workspace/work1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ismayil/Qt_workspace/work1 /home/ismayil/Qt_workspace/work1 /home/ismayil/Qt_workspace/work1/build /home/ismayil/Qt_workspace/work1/build /home/ismayil/Qt_workspace/work1/build/CMakeFiles/work1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/work1.dir/depend

