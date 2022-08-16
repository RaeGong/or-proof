# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build"

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/PaillierEncryption.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/PaillierEncryption.cpp.o: ../src/PaillierEncryption.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/PaillierEncryption.cpp.o"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/PaillierEncryption.cpp.o -c "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/PaillierEncryption.cpp"

src/CMakeFiles/src.dir/PaillierEncryption.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/PaillierEncryption.cpp.i"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/PaillierEncryption.cpp" > CMakeFiles/src.dir/PaillierEncryption.cpp.i

src/CMakeFiles/src.dir/PaillierEncryption.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/PaillierEncryption.cpp.s"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/PaillierEncryption.cpp" -o CMakeFiles/src.dir/PaillierEncryption.cpp.s

src/CMakeFiles/src.dir/ConvertUtils.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/ConvertUtils.cpp.o: ../src/ConvertUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/ConvertUtils.cpp.o"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/ConvertUtils.cpp.o -c "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/ConvertUtils.cpp"

src/CMakeFiles/src.dir/ConvertUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/ConvertUtils.cpp.i"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/ConvertUtils.cpp" > CMakeFiles/src.dir/ConvertUtils.cpp.i

src/CMakeFiles/src.dir/ConvertUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/ConvertUtils.cpp.s"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src/ConvertUtils.cpp" -o CMakeFiles/src.dir/ConvertUtils.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/PaillierEncryption.cpp.o" \
"CMakeFiles/src.dir/ConvertUtils.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/PaillierEncryption.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/ConvertUtils.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libsrc.a"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a

.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/src" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/src/CMakeFiles/src.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend
