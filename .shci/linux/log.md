
# shengine

![linux-badge](exit_code.svg)

## [linux build logs:](https://github.com/mrsinho/shci)



Build ran for `55.14s`

---

```bash
function PREREQUISITES {
    sudo apt -y update
    sudo apt install -y libvulkan-dev libvulkan1
    sudo apt install -y libx11-dev libwayland-dev
    sudo apt install -y python3.9 python3-pip
    sudo apt install -y gcc cmake make libc6-dev
    cd requirements
    sudo bash debian-requirements.sh
}

PREREQUISITES > .shci/linux/prerequisites-output.txt

```

```bash
Hit:1 http://ftp.debian.org/debian bullseye-backports InRelease
Hit:2 http://deb.debian.org/debian bullseye InRelease
Hit:3 http://security.debian.org/debian-security bullseye-security InRelease
Hit:4 http://deb.debian.org/debian bullseye-updates InRelease
Reading package lists...
Building dependency tree...
Reading state information...
All packages are up to date.
Reading package lists...
Building dependency tree...
Reading state information...
libvulkan-dev is already the newest version (1.2.162.0-1).
libvulkan1 is already the newest version (1.2.162.0-1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
The following additional packages will be installed:
  libffi-dev libpthread-stubs0-dev libwayland-bin libwayland-cursor0
  libwayland-egl1 libwayland-server0 libxau-dev libxcb1-dev libxdmcp-dev
  x11proto-dev xorg-sgml-doctools xtrans-dev
Suggested packages:
  libwayland-doc libx11-doc libxcb-doc
The following NEW packages will be installed:
  libffi-dev libpthread-stubs0-dev libwayland-bin libwayland-cursor0
  libwayland-dev libwayland-egl1 libwayland-server0 libx11-dev libxau-dev
  libxcb1-dev libxdmcp-dev x11proto-dev xorg-sgml-doctools xtrans-dev
0 upgraded, 14 newly installed, 0 to remove and 0 not upgraded.
Need to get 2,011 kB of archives.
After this operation, 6,930 kB of additional disk space will be used.
Get:1 http://security.debian.org/debian-security bullseye-security/main amd64 libx11-dev amd64 2:1.7.2-1+deb11u1 [843 kB]
Get:2 http://deb.debian.org/debian bullseye/main amd64 libffi-dev amd64 3.3-6 [56.5 kB]
Get:3 http://deb.debian.org/debian bullseye/main amd64 libpthread-stubs0-dev amd64 0.4-1 [5,344 B]
Get:4 http://deb.debian.org/debian bullseye/main amd64 libwayland-bin amd64 1.18.0-2~exp1.1 [23.1 kB]
Get:5 http://deb.debian.org/debian bullseye/main amd64 libwayland-cursor0 amd64 1.18.0-2~exp1.1 [14.6 kB]
Get:6 http://deb.debian.org/debian bullseye/main amd64 libwayland-server0 amd64 1.18.0-2~exp1.1 [34.4 kB]
Get:7 http://deb.debian.org/debian bullseye/main amd64 libwayland-egl1 amd64 1.18.0-2~exp1.1 [8,448 B]
Get:8 http://deb.debian.org/debian bullseye/main amd64 libwayland-dev amd64 1.18.0-2~exp1.1 [69.0 kB]
Get:9 http://deb.debian.org/debian bullseye/main amd64 xorg-sgml-doctools all 1:1.11-1.1 [22.1 kB]
Get:10 http://deb.debian.org/debian bullseye/main amd64 x11proto-dev all 2020.1-1 [594 kB]
Get:11 http://deb.debian.org/debian bullseye/main amd64 libxau-dev amd64 1:1.0.9-1 [22.9 kB]
Get:12 http://deb.debian.org/debian bullseye/main amd64 libxdmcp-dev amd64 1:1.1.2-3 [42.2 kB]
Get:13 http://deb.debian.org/debian bullseye/main amd64 xtrans-dev all 1.4.0-1 [98.7 kB]
Get:14 http://deb.debian.org/debian bullseye/main amd64 libxcb1-dev amd64 1.14-3 [176 kB]
Fetched 2,011 kB in 1s (2,967 kB/s)
Selecting previously unselected package libffi-dev:amd64.
(Reading database ... 
(Reading database ... 5%
(Reading database ... 10%
(Reading database ... 15%
(Reading database ... 20%
(Reading database ... 25%
(Reading database ... 30%
(Reading database ... 35%
(Reading database ... 40%
(Reading database ... 45%
(Reading database ... 50%
(Reading database ... 55%
(Reading database ... 60%
(Reading database ... 65%
(Reading database ... 70%
(Reading database ... 75%
(Reading database ... 80%
(Reading database ... 85%
(Reading database ... 90%
(Reading database ... 95%
(Reading database ... 100%
(Reading database ... 25394 files and directories currently installed.)
Preparing to unpack .../00-libffi-dev_3.3-6_amd64.deb ...
Unpacking libffi-dev:amd64 (3.3-6) ...
Selecting previously unselected package libpthread-stubs0-dev:amd64.
Preparing to unpack .../01-libpthread-stubs0-dev_0.4-1_amd64.deb ...
Unpacking libpthread-stubs0-dev:amd64 (0.4-1) ...
Selecting previously unselected package libwayland-bin.
Preparing to unpack .../02-libwayland-bin_1.18.0-2~exp1.1_amd64.deb ...
Unpacking libwayland-bin (1.18.0-2~exp1.1) ...
Selecting previously unselected package libwayland-cursor0:amd64.
Preparing to unpack .../03-libwayland-cursor0_1.18.0-2~exp1.1_amd64.deb ...
Unpacking libwayland-cursor0:amd64 (1.18.0-2~exp1.1) ...
Selecting previously unselected package libwayland-server0:amd64.
Preparing to unpack .../04-libwayland-server0_1.18.0-2~exp1.1_amd64.deb ...
Unpacking libwayland-server0:amd64 (1.18.0-2~exp1.1) ...
Selecting previously unselected package libwayland-egl1:amd64.
Preparing to unpack .../05-libwayland-egl1_1.18.0-2~exp1.1_amd64.deb ...
Unpacking libwayland-egl1:amd64 (1.18.0-2~exp1.1) ...
Selecting previously unselected package libwayland-dev:amd64.
Preparing to unpack .../06-libwayland-dev_1.18.0-2~exp1.1_amd64.deb ...
Unpacking libwayland-dev:amd64 (1.18.0-2~exp1.1) ...
Selecting previously unselected package xorg-sgml-doctools.
Preparing to unpack .../07-xorg-sgml-doctools_1%3a1.11-1.1_all.deb ...
Unpacking xorg-sgml-doctools (1:1.11-1.1) ...
Selecting previously unselected package x11proto-dev.
Preparing to unpack .../08-x11proto-dev_2020.1-1_all.deb ...
Unpacking x11proto-dev (2020.1-1) ...
Selecting previously unselected package libxau-dev:amd64.
Preparing to unpack .../09-libxau-dev_1%3a1.0.9-1_amd64.deb ...
Unpacking libxau-dev:amd64 (1:1.0.9-1) ...
Selecting previously unselected package libxdmcp-dev:amd64.
Preparing to unpack .../10-libxdmcp-dev_1%3a1.1.2-3_amd64.deb ...
Unpacking libxdmcp-dev:amd64 (1:1.1.2-3) ...
Selecting previously unselected package xtrans-dev.
Preparing to unpack .../11-xtrans-dev_1.4.0-1_all.deb ...
Unpacking xtrans-dev (1.4.0-1) ...
Selecting previously unselected package libxcb1-dev:amd64.
Preparing to unpack .../12-libxcb1-dev_1.14-3_amd64.deb ...
Unpacking libxcb1-dev:amd64 (1.14-3) ...
Selecting previously unselected package libx11-dev:amd64.
Preparing to unpack .../13-libx11-dev_2%3a1.7.2-1+deb11u1_amd64.deb ...
Unpacking libx11-dev:amd64 (2:1.7.2-1+deb11u1) ...
Setting up libwayland-server0:amd64 (1.18.0-2~exp1.1) ...
Setting up libffi-dev:amd64 (3.3-6) ...
Setting up libpthread-stubs0-dev:amd64 (0.4-1) ...
Setting up xtrans-dev (1.4.0-1) ...
Setting up libwayland-bin (1.18.0-2~exp1.1) ...
Setting up libwayland-cursor0:amd64 (1.18.0-2~exp1.1) ...
Setting up xorg-sgml-doctools (1:1.11-1.1) ...
Setting up libwayland-egl1:amd64 (1.18.0-2~exp1.1) ...
Setting up x11proto-dev (2020.1-1) ...
Setting up libxau-dev:amd64 (1:1.0.9-1) ...
Setting up libwayland-dev:amd64 (1.18.0-2~exp1.1) ...
Setting up libxdmcp-dev:amd64 (1:1.1.2-3) ...
Setting up libxcb1-dev:amd64 (1.14-3) ...
Setting up libx11-dev:amd64 (2:1.7.2-1+deb11u1) ...
Processing triggers for libc-bin (2.31-13+deb11u6) ...
Reading package lists...
Building dependency tree...
Reading state information...
python3-pip is already the newest version (20.3.4-4+deb11u1).
python3.9 is already the newest version (3.9.2-1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
cmake is already the newest version (3.18.4-2+deb11u1).
gcc is already the newest version (4:10.2.1-1).
libc6-dev is already the newest version (2.31-13+deb11u6).
make is already the newest version (4.3-4.1).
0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.
Reading package lists...
Building dependency tree...
Reading state information...
Reading package lists...
Building dependency tree...
Reading state information...
Reading package lists...
Building dependency tree...
Reading state information...

```

---

    
```bash
function BUILD {
	python3.9 export-application.py name=triangle target=EXECUTABLE path=applications/triangle
	python3.9 export-application.py name=noise target=EXECUTABLE path=applications/noise
	cd applications/triangle/linux/build
	cmake --build .
	cd ../../../noise/linux/build
	cmake --build .
}

BUILD > .shci/linux/build-output.txt

```

```bash
-- shvulkan message: found Vulkan
-- shvulkan message: Vulkan_INCLUDE_DIR: /usr/include
-- shvulkan message: Vulkan_LIBRARY:     /usr/lib/x86_64-linux-gnu/libvulkan.so
-- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE) 
-- Including X11 support
-- Found X11: /usr/include   
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
-- Configuring incomplete, errors occurred!
See also "/mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux/build/CMakeFiles/CMakeOutput.log".
See also "/mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux/build/CMakeFiles/CMakeError.log".
--------------------------------------------------------------------------------
EXAMPLE CALL: python export-application.py name=noise target=SHARED
EXAMPLE CALL: python export-application.py name=noise target=STATIC path=applications/noise
EXAMPLE CALL: python export-application.py name=noise target=SHARED path=applications/noise generator=MinGW-Makefiles
EXAMPLE CALL: python export-application.py name=noise target=EXECUTABLE path=applications/noise generator=MinGW-Makefiles CLEAN-CACHE
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
platform:       linux
python_src_dir: /mnt/d/home/desktop/GitHub/shengine
name:           triangle
path:           /mnt/d/home/desktop/GitHub/shengine/applications/triangle
target_type:    EXECUTABLE
generator:      
clean-cache:    
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
loading /mnt/d/home/desktop/GitHub/shengine/applications/triangle/source-files.txt
src files:
	src/triangle.c

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
loading /mnt/d/home/desktop/GitHub/shengine/applications/triangle/libs.txt
additional libraries:
	
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
CMake subdirectories:
		

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
CMake file:
cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

	

project(triangle C)

option(SH_APPLICATION_BINARY_TYPE CACHE "EXECUTABLE")
if("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "STATIC")
    add_library(${SH_APPLICATION_NAME} STATIC 
        	/mnt/d/home/desktop/GitHub/shengine/applications/triangle/src/triangle.c

    )
    
elseif("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "SHARED")
    add_library(${SH_APPLICATION_NAME} SHARED 
        	/mnt/d/home/desktop/GitHub/shengine/applications/triangle/src/triangle.c

    )
    target_compile_definitions(shengine PUBLIC SH_APPLICATION_TARGET_TYPE_SHARED=1)
    set_target_properties(${SH_APPLICATION_NAME} sheditor PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/ 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
        VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
    )
elseif("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "EXECUTABLE")
    add_executable(${SH_APPLICATION_NAME}  
        	/mnt/d/home/desktop/GitHub/shengine/applications/triangle/src/triangle.c

        /mnt/d/home/desktop/GitHub/shengine/collection/sheditor/src/shEditor.c
    )
    target_include_directories(${SH_APPLICATION_NAME} PUBLIC /mnt/d/home/desktop/GitHub/shengine/collection/sheditor/include)
    target_compile_definitions(${SH_APPLICATION_NAME} PUBLIC SH_APPLICATION_TARGET_TYPE_EXECUTABLE=1)
    set_target_properties(${SH_APPLICATION_NAME} PROPERTIES 
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/ 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
        VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
    )
endif()

target_include_directories(${SH_APPLICATION_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    ${SH_APPLICATION_NAME} PUBLIC shengine 	
)

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
writing to CMake file: /mnt/d/home/desktop/GitHub/shengine/applications/triangle/CMakeLists.txt
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
Os path: /mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux
Build path: /mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux/build

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
creating build directory: /mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux/build
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
running command:
	cd /mnt/d/home/desktop/GitHub/shengine/applications/triangle/linux/build && cmake /mnt/d/home/desktop/GitHub/shengine -DSH_ENGINE_BUILD_EDITOR=ON -DSH_APPLICATION_PATH=/mnt/d/home/desktop/GitHub/shengine/applications/triangle -DSH_APPLICATION_NAME=triangle -DSH_APPLICATION_BINARY_TYPE=EXECUTABLE 
--------------------------------------------------------------------------------

-- shvulkan message: found Vulkan
-- shvulkan message: Vulkan_INCLUDE_DIR: /usr/include
-- shvulkan message: Vulkan_LIBRARY:     /usr/lib/x86_64-linux-gnu/libvulkan.so
-- Could NOT find Doxygen (missing: DOXYGEN_EXECUTABLE) 
-- Including X11 support
-- Found X11: /usr/include   
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
-- Configuring incomplete, errors occurred!
See also "/mnt/d/home/desktop/GitHub/shengine/applications/noise/linux/build/CMakeFiles/CMakeOutput.log".
See also "/mnt/d/home/desktop/GitHub/shengine/applications/noise/linux/build/CMakeFiles/CMakeError.log".
--------------------------------------------------------------------------------
EXAMPLE CALL: python export-application.py name=noise target=SHARED
EXAMPLE CALL: python export-application.py name=noise target=STATIC path=applications/noise
EXAMPLE CALL: python export-application.py name=noise target=SHARED path=applications/noise generator=MinGW-Makefiles
EXAMPLE CALL: python export-application.py name=noise target=EXECUTABLE path=applications/noise generator=MinGW-Makefiles CLEAN-CACHE
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
platform:       linux
python_src_dir: /mnt/d/home/desktop/GitHub/shengine
name:           noise
path:           /mnt/d/home/desktop/GitHub/shengine/applications/noise
target_type:    EXECUTABLE
generator:      
clean-cache:    
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
loading /mnt/d/home/desktop/GitHub/shengine/applications/noise/source-files.txt
src files:
	src/noise.c

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
loading /mnt/d/home/desktop/GitHub/shengine/applications/noise/libs.txt
additional libraries:
	
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
CMake subdirectories:
		

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
CMake file:
cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

	

project(noise C)

option(SH_APPLICATION_BINARY_TYPE CACHE "EXECUTABLE")
if("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "STATIC")
    add_library(${SH_APPLICATION_NAME} STATIC 
        	/mnt/d/home/desktop/GitHub/shengine/applications/noise/src/noise.c

    )
    
elseif("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "SHARED")
    add_library(${SH_APPLICATION_NAME} SHARED 
        	/mnt/d/home/desktop/GitHub/shengine/applications/noise/src/noise.c

    )
    target_compile_definitions(shengine PUBLIC SH_APPLICATION_TARGET_TYPE_SHARED=1)
    set_target_properties(${SH_APPLICATION_NAME} sheditor PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/ 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
        VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
    )
elseif("${SH_APPLICATION_BINARY_TYPE}" STREQUAL "EXECUTABLE")
    add_executable(${SH_APPLICATION_NAME}  
        	/mnt/d/home/desktop/GitHub/shengine/applications/noise/src/noise.c

        /mnt/d/home/desktop/GitHub/shengine/collection/sheditor/src/shEditor.c
    )
    target_include_directories(${SH_APPLICATION_NAME} PUBLIC /mnt/d/home/desktop/GitHub/shengine/collection/sheditor/include)
    target_compile_definitions(${SH_APPLICATION_NAME} PUBLIC SH_APPLICATION_TARGET_TYPE_EXECUTABLE=1)
    set_target_properties(${SH_APPLICATION_NAME} PROPERTIES 
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/ 
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
        VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/linux/bin/
    )
endif()

target_include_directories(${SH_APPLICATION_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    ${SH_APPLICATION_NAME} PUBLIC shengine 	
)

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
writing to CMake file: /mnt/d/home/desktop/GitHub/shengine/applications/noise/CMakeLists.txt
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
Os path: /mnt/d/home/desktop/GitHub/shengine/applications/noise/linux
Build path: /mnt/d/home/desktop/GitHub/shengine/applications/noise/linux/build

--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
creating build directory: /mnt/d/home/desktop/GitHub/shengine/applications/noise/linux/build
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
running command:
	cd /mnt/d/home/desktop/GitHub/shengine/applications/noise/linux/build && cmake /mnt/d/home/desktop/GitHub/shengine -DSH_ENGINE_BUILD_EDITOR=ON -DSH_APPLICATION_PATH=/mnt/d/home/desktop/GitHub/shengine/applications/noise -DSH_APPLICATION_NAME=noise -DSH_APPLICATION_BINARY_TYPE=EXECUTABLE 
--------------------------------------------------------------------------------


```

---

    

Build terminated with exit code 2

---
