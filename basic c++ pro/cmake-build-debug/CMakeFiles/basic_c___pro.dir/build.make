# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\10154\Desktop\acwing\basic c++ pro"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/basic_c___pro.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basic_c___pro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic_c___pro.dir/flags.make

CMakeFiles/basic_c___pro.dir/p2249.cpp.obj: CMakeFiles/basic_c___pro.dir/flags.make
CMakeFiles/basic_c___pro.dir/p2249.cpp.obj: ../p2249.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basic_c___pro.dir/p2249.cpp.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\basic_c___pro.dir\p2249.cpp.obj -c "C:\Users\10154\Desktop\acwing\basic c++ pro\p2249.cpp"

CMakeFiles/basic_c___pro.dir/p2249.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_c___pro.dir/p2249.cpp.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\10154\Desktop\acwing\basic c++ pro\p2249.cpp" > CMakeFiles\basic_c___pro.dir\p2249.cpp.i

CMakeFiles/basic_c___pro.dir/p2249.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_c___pro.dir/p2249.cpp.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\10154\Desktop\acwing\basic c++ pro\p2249.cpp" -o CMakeFiles\basic_c___pro.dir\p2249.cpp.s

# Object files for target basic_c___pro
basic_c___pro_OBJECTS = \
"CMakeFiles/basic_c___pro.dir/p2249.cpp.obj"

# External object files for target basic_c___pro
basic_c___pro_EXTERNAL_OBJECTS =

basic_c___pro.exe: CMakeFiles/basic_c___pro.dir/p2249.cpp.obj
basic_c___pro.exe: CMakeFiles/basic_c___pro.dir/build.make
basic_c___pro.exe: CMakeFiles/basic_c___pro.dir/linklibs.rsp
basic_c___pro.exe: CMakeFiles/basic_c___pro.dir/objects1.rsp
basic_c___pro.exe: CMakeFiles/basic_c___pro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basic_c___pro.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\basic_c___pro.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic_c___pro.dir/build: basic_c___pro.exe

.PHONY : CMakeFiles/basic_c___pro.dir/build

CMakeFiles/basic_c___pro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\basic_c___pro.dir\cmake_clean.cmake
.PHONY : CMakeFiles/basic_c___pro.dir/clean

CMakeFiles/basic_c___pro.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\10154\Desktop\acwing\basic c++ pro" "C:\Users\10154\Desktop\acwing\basic c++ pro" "C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug" "C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug" "C:\Users\10154\Desktop\acwing\basic c++ pro\cmake-build-debug\CMakeFiles\basic_c___pro.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/basic_c___pro.dir/depend

