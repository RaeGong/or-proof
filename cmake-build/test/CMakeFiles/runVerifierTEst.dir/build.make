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
include test/CMakeFiles/runVerifierTest.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runVerifierTest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runVerifierTest.dir/flags.make

test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o: test/CMakeFiles/runVerifierTest.dir/flags.make
test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o: ../test/Verifier_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o -c "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/test/Verifier_test.cpp"

test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.i"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/test/Verifier_test.cpp" > CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.i

test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.s"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/test/Verifier_test.cpp" -o CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.s

# Object files for target runVerifierTest
runVerifierTest_OBJECTS = \
"CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o"

# External object files for target runVerifierTest
runVerifierTest_EXTERNAL_OBJECTS =

test/runVerifierTest: test/CMakeFiles/runVerifierTest.dir/Verifier_test.cpp.o
test/runVerifierTest: test/CMakeFiles/runVerifierTest.dir/build.make
test/runVerifierTest: src/libsrc_stac.a
test/runVerifierTest: src/utils/libutils_stac.a
test/runVerifierTest: lib/libgtest.a
test/runVerifierTest: lib/libgtest_main.a
test/runVerifierTest: /usr/local/lib/libntl.a
test/runVerifierTest: /usr/local/lib/libgmp.a
test/runVerifierTest: /usr/local/lib/libssl.dylib
test/runVerifierTest: /usr/local/lib/libcrypto.dylib
test/runVerifierTest: lib/libgtest.a
test/runVerifierTest: test/CMakeFiles/runVerifierTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runVerifierTest"
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runVerifierTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runVerifierTest.dir/build: test/runVerifierTest

.PHONY : test/CMakeFiles/runVerifierTest.dir/build

test/CMakeFiles/runVerifierTest.dir/clean:
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" && $(CMAKE_COMMAND) -P CMakeFiles/runVerifierTest.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runVerifierTest.dir/clean

test/CMakeFiles/runVerifierTest.dir/depend:
	cd "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/test" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test" "/Users/raegong/Dropbox/polyu projects/2021-zkp/code/or-proof/cmake-build/test/CMakeFiles/runVerifierTest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/runVerifierTest.dir/depend

