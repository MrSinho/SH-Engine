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

# Utility rule file for uninstall.

# Include the progress variables for this target.
include -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/progress.make

-DGLFW_VULKAN_STATIC/CMakeFiles/uninstall:
	cd /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC && /usr/bin/cmake -P /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/cmake_uninstall.cmake

uninstall: -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall
uninstall: -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
-DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/build

-DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/clean:
	cd /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/clean

-DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/depend:
	cd /home/mrsinho/Desktop/Foggy-Engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrsinho/Desktop/Foggy-Engine /home/mrsinho/Desktop/Foggy-Engine/Externals/glfw /home/mrsinho/Desktop/Foggy-Engine/build /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC /home/mrsinho/Desktop/Foggy-Engine/build/-DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : -DGLFW_VULKAN_STATIC/CMakeFiles/uninstall.dir/depend

