# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrsinho/Desktop/Foggy-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrsinho/Desktop/Foggy-Engine/build

# Utility rule file for docs.

# Include the progress variables for this target.
include -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/progress.make

-DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/mrsinho/Desktop/Foggy-Engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating HTML documentation"
	cd /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/docs && /usr/bin/doxygen

docs: -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs
docs: -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/build.make

.PHONY : docs

# Rule to build all files generated by this target.
-DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/build: docs

.PHONY : -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/build

-DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/clean:
	cd /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/docs && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/clean

-DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/depend:
	cd /home/mrsinho/Desktop/Foggy-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrsinho/Desktop/Foggy-Engine /home/mrsinho/Desktop/Foggy-Engine/Externals/glfw/docs /home/mrsinho/Desktop/Foggy-Engine/build /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/docs /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : -DGLFW_VULKAN_STATIC/docs/CMakeFiles/docs.dir/depend

