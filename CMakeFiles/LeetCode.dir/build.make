# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/soumya/tools/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/soumya/tools/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/soumya/CLionProjects/LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/soumya/CLionProjects/LeetCode

# Include any dependencies generated for this target.
include CMakeFiles/LeetCode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeetCode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeetCode.dir/flags.make

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o: CMakeFiles/LeetCode.dir/flags.make
CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o: ReverseWordsInString.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/soumya/CLionProjects/LeetCode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o -c /home/soumya/CLionProjects/LeetCode/ReverseWordsInString.cpp

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/soumya/CLionProjects/LeetCode/ReverseWordsInString.cpp > CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.i

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/soumya/CLionProjects/LeetCode/ReverseWordsInString.cpp -o CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.s

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.requires:

.PHONY : CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.requires

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.provides: CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.requires
	$(MAKE) -f CMakeFiles/LeetCode.dir/build.make CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.provides.build
.PHONY : CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.provides

CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.provides.build: CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o


# Object files for target LeetCode
LeetCode_OBJECTS = \
"CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o"

# External object files for target LeetCode
LeetCode_EXTERNAL_OBJECTS =

LeetCode: CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o
LeetCode: CMakeFiles/LeetCode.dir/build.make
LeetCode: CMakeFiles/LeetCode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/soumya/CLionProjects/LeetCode/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LeetCode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeetCode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeetCode.dir/build: LeetCode

.PHONY : CMakeFiles/LeetCode.dir/build

CMakeFiles/LeetCode.dir/requires: CMakeFiles/LeetCode.dir/ReverseWordsInString.cpp.o.requires

.PHONY : CMakeFiles/LeetCode.dir/requires

CMakeFiles/LeetCode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeetCode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeetCode.dir/clean

CMakeFiles/LeetCode.dir/depend:
	cd /home/soumya/CLionProjects/LeetCode && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/soumya/CLionProjects/LeetCode /home/soumya/CLionProjects/LeetCode /home/soumya/CLionProjects/LeetCode /home/soumya/CLionProjects/LeetCode /home/soumya/CLionProjects/LeetCode/CMakeFiles/LeetCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LeetCode.dir/depend
