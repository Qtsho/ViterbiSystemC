# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/quangtien/viterbi_HWSW/Viterbi_Encoder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quangtien/viterbi_HWSW/Viterbi_Encoder/build

# Include any dependencies generated for this target.
include CMakeFiles/viterbi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/viterbi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/viterbi.dir/flags.make

CMakeFiles/viterbi.dir/src/encoder.cpp.o: CMakeFiles/viterbi.dir/flags.make
CMakeFiles/viterbi.dir/src/encoder.cpp.o: ../src/encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quangtien/viterbi_HWSW/Viterbi_Encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/viterbi.dir/src/encoder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viterbi.dir/src/encoder.cpp.o -c /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/encoder.cpp

CMakeFiles/viterbi.dir/src/encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viterbi.dir/src/encoder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/encoder.cpp > CMakeFiles/viterbi.dir/src/encoder.cpp.i

CMakeFiles/viterbi.dir/src/encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viterbi.dir/src/encoder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/encoder.cpp -o CMakeFiles/viterbi.dir/src/encoder.cpp.s

CMakeFiles/viterbi.dir/src/encoder.cpp.o.requires:

.PHONY : CMakeFiles/viterbi.dir/src/encoder.cpp.o.requires

CMakeFiles/viterbi.dir/src/encoder.cpp.o.provides: CMakeFiles/viterbi.dir/src/encoder.cpp.o.requires
	$(MAKE) -f CMakeFiles/viterbi.dir/build.make CMakeFiles/viterbi.dir/src/encoder.cpp.o.provides.build
.PHONY : CMakeFiles/viterbi.dir/src/encoder.cpp.o.provides

CMakeFiles/viterbi.dir/src/encoder.cpp.o.provides.build: CMakeFiles/viterbi.dir/src/encoder.cpp.o


CMakeFiles/viterbi.dir/src/driver.cpp.o: CMakeFiles/viterbi.dir/flags.make
CMakeFiles/viterbi.dir/src/driver.cpp.o: ../src/driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quangtien/viterbi_HWSW/Viterbi_Encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/viterbi.dir/src/driver.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viterbi.dir/src/driver.cpp.o -c /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/driver.cpp

CMakeFiles/viterbi.dir/src/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viterbi.dir/src/driver.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/driver.cpp > CMakeFiles/viterbi.dir/src/driver.cpp.i

CMakeFiles/viterbi.dir/src/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viterbi.dir/src/driver.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/driver.cpp -o CMakeFiles/viterbi.dir/src/driver.cpp.s

CMakeFiles/viterbi.dir/src/driver.cpp.o.requires:

.PHONY : CMakeFiles/viterbi.dir/src/driver.cpp.o.requires

CMakeFiles/viterbi.dir/src/driver.cpp.o.provides: CMakeFiles/viterbi.dir/src/driver.cpp.o.requires
	$(MAKE) -f CMakeFiles/viterbi.dir/build.make CMakeFiles/viterbi.dir/src/driver.cpp.o.provides.build
.PHONY : CMakeFiles/viterbi.dir/src/driver.cpp.o.provides

CMakeFiles/viterbi.dir/src/driver.cpp.o.provides.build: CMakeFiles/viterbi.dir/src/driver.cpp.o


CMakeFiles/viterbi.dir/src/testbench.cpp.o: CMakeFiles/viterbi.dir/flags.make
CMakeFiles/viterbi.dir/src/testbench.cpp.o: ../src/testbench.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quangtien/viterbi_HWSW/Viterbi_Encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/viterbi.dir/src/testbench.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viterbi.dir/src/testbench.cpp.o -c /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/testbench.cpp

CMakeFiles/viterbi.dir/src/testbench.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viterbi.dir/src/testbench.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/testbench.cpp > CMakeFiles/viterbi.dir/src/testbench.cpp.i

CMakeFiles/viterbi.dir/src/testbench.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viterbi.dir/src/testbench.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quangtien/viterbi_HWSW/Viterbi_Encoder/src/testbench.cpp -o CMakeFiles/viterbi.dir/src/testbench.cpp.s

CMakeFiles/viterbi.dir/src/testbench.cpp.o.requires:

.PHONY : CMakeFiles/viterbi.dir/src/testbench.cpp.o.requires

CMakeFiles/viterbi.dir/src/testbench.cpp.o.provides: CMakeFiles/viterbi.dir/src/testbench.cpp.o.requires
	$(MAKE) -f CMakeFiles/viterbi.dir/build.make CMakeFiles/viterbi.dir/src/testbench.cpp.o.provides.build
.PHONY : CMakeFiles/viterbi.dir/src/testbench.cpp.o.provides

CMakeFiles/viterbi.dir/src/testbench.cpp.o.provides.build: CMakeFiles/viterbi.dir/src/testbench.cpp.o


# Object files for target viterbi
viterbi_OBJECTS = \
"CMakeFiles/viterbi.dir/src/encoder.cpp.o" \
"CMakeFiles/viterbi.dir/src/driver.cpp.o" \
"CMakeFiles/viterbi.dir/src/testbench.cpp.o"

# External object files for target viterbi
viterbi_EXTERNAL_OBJECTS =

viterbi: CMakeFiles/viterbi.dir/src/encoder.cpp.o
viterbi: CMakeFiles/viterbi.dir/src/driver.cpp.o
viterbi: CMakeFiles/viterbi.dir/src/testbench.cpp.o
viterbi: CMakeFiles/viterbi.dir/build.make
viterbi: /home/quangtien/Downloads/systemc-2.3.2/build/src/libsystemc.so.2.3.2
viterbi: CMakeFiles/viterbi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quangtien/viterbi_HWSW/Viterbi_Encoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable viterbi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/viterbi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/viterbi.dir/build: viterbi

.PHONY : CMakeFiles/viterbi.dir/build

CMakeFiles/viterbi.dir/requires: CMakeFiles/viterbi.dir/src/encoder.cpp.o.requires
CMakeFiles/viterbi.dir/requires: CMakeFiles/viterbi.dir/src/driver.cpp.o.requires
CMakeFiles/viterbi.dir/requires: CMakeFiles/viterbi.dir/src/testbench.cpp.o.requires

.PHONY : CMakeFiles/viterbi.dir/requires

CMakeFiles/viterbi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/viterbi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/viterbi.dir/clean

CMakeFiles/viterbi.dir/depend:
	cd /home/quangtien/viterbi_HWSW/Viterbi_Encoder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quangtien/viterbi_HWSW/Viterbi_Encoder /home/quangtien/viterbi_HWSW/Viterbi_Encoder /home/quangtien/viterbi_HWSW/Viterbi_Encoder/build /home/quangtien/viterbi_HWSW/Viterbi_Encoder/build /home/quangtien/viterbi_HWSW/Viterbi_Encoder/build/CMakeFiles/viterbi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/viterbi.dir/depend

