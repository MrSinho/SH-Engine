
# shengine

![linux-badge](linux-exit_code.svg)

## [linux build logs:](https://github.com/mrsinho/shci)

        

Build ran for `371.00s`

---

```bash
sudo apt install -y gcc cmake make gdb libc6-dev
```

```bash
Reading package lists...
Building dependency tree...
Reading state information...
cmake is already the newest version (3.18.4-2+deb11u1).
gcc is already the newest version (4:10.2.1-1).
gdb is already the newest version (10.1-1.7).
make is already the newest version (4.3-4.1).
The following additional packages will be installed:
  libc-dev-bin libc6 libc6-dbg
Suggested packages:
  glibc-doc
Recommended packages:
  libnss-nis libnss-nisplus
The following packages will be upgraded:
  libc-dev-bin libc6 libc6-dbg libc6-dev
4 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
Need to get 13.0 MB of archives.
After this operation, 2,048 B disk space will be freed.
Get:1 http://deb.debian.org/debian bullseye-updates/main amd64 libc6-dbg amd64 2.31-13+deb11u5 [7,521 kB]
Get:2 http://deb.debian.org/debian bullseye-updates/main amd64 libc6-dev amd64 2.31-13+deb11u5 [2,359 kB]
Get:3 http://deb.debian.org/debian bullseye-updates/main amd64 libc-dev-bin amd64 2.31-13+deb11u5 [276 kB]
Get:4 http://deb.debian.org/debian bullseye-updates/main amd64 libc6 amd64 2.31-13+deb11u5 [2,825 kB]
Preconfiguring packages ...
Fetched 13.0 MB in 1s (8,753 kB/s)
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
(Reading database ... 27169 files and directories currently installed.)
Preparing to unpack .../libc6-dbg_2.31-13+deb11u5_amd64.deb ...
Unpacking libc6-dbg:amd64 (2.31-13+deb11u5) over (2.31-13+deb11u4) ...
Preparing to unpack .../libc6-dev_2.31-13+deb11u5_amd64.deb ...
Unpacking libc6-dev:amd64 (2.31-13+deb11u5) over (2.31-13+deb11u4) ...
Preparing to unpack .../libc-dev-bin_2.31-13+deb11u5_amd64.deb ...
Unpacking libc-dev-bin (2.31-13+deb11u5) over (2.31-13+deb11u4) ...
Preparing to unpack .../libc6_2.31-13+deb11u5_amd64.deb ...
Unpacking libc6:amd64 (2.31-13+deb11u5) over (2.31-13+deb11u4) ...
Setting up libc6:amd64 (2.31-13+deb11u5) ...
Setting up libc6-dbg:amd64 (2.31-13+deb11u5) ...
Setting up libc-dev-bin (2.31-13+deb11u5) ...
Setting up libc6-dev:amd64 (2.31-13+deb11u5) ...
Processing triggers for libc-bin (2.31-13+deb11u4) ...

```

---

    
```bash
cd shengine 
python3 export-simulation.py flappy-circle SHARED 
cd build 
cmake --build .
```

```bash
-- The C compiler identification is GNU 10.2.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Found Vulkan: /usr/lib/x86_64-linux-gnu/libvulkan.so  
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Found Doxygen: /usr/bin/doxygen (found version "1.9.1") found components: doxygen 
-- Including X11 support
-- Found X11: /usr/include   
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so
-- Looking for XOpenDisplay in /usr/lib/x86_64-linux-gnu/libX11.so;/usr/lib/x86_64-linux-gnu/libXext.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
-- Setting build type to 'Release' as none was specified.
-- Looking for fcntl.h
-- Looking for fcntl.h - found
-- Looking for inttypes.h
-- Looking for inttypes.h - found
-- Looking for stdarg.h
-- Looking for stdarg.h - found
-- Looking for strings.h
-- Looking for strings.h - found
-- Looking for string.h
-- Looking for string.h - found
-- Looking for syslog.h
-- Looking for syslog.h - found
-- Looking for 4 include files stdlib.h, ..., float.h
-- Looking for 4 include files stdlib.h, ..., float.h - found
-- Looking for unistd.h
-- Looking for unistd.h - found
-- Looking for sys/types.h
-- Looking for sys/types.h - found
-- Looking for sys/resource.h
-- Looking for sys/resource.h - found
-- Looking for dlfcn.h
-- Looking for dlfcn.h - found
-- Looking for endian.h
-- Looking for endian.h - found
-- Looking for limits.h
-- Looking for limits.h - found
-- Looking for locale.h
-- Looking for locale.h - found
-- Looking for memory.h
-- Looking for memory.h - found
-- Looking for stdint.h
-- Looking for stdint.h - found
-- Looking for stdlib.h
-- Looking for stdlib.h - found
-- Looking for sys/cdefs.h
-- Looking for sys/cdefs.h - found
-- Looking for sys/param.h
-- Looking for sys/param.h - found
-- Looking for sys/random.h
-- Looking for sys/random.h - found
-- Looking for sys/stat.h
-- Looking for sys/stat.h - found
-- Looking for xlocale.h
-- Looking for xlocale.h - not found
-- Looking for _isnan
-- Looking for _isnan - not found
-- Looking for _finite
-- Looking for _finite - not found
-- Looking for INFINITY
-- Looking for INFINITY - found
-- Looking for isinf
-- Looking for isinf - found
-- Looking for isnan
-- Looking for isnan - found
-- Looking for nan
-- Looking for nan - found
-- Looking for _doprnt
-- Looking for _doprnt - not found
-- Looking for snprintf
-- Looking for snprintf - found
-- Looking for vasprintf
-- Looking for vasprintf - found
-- Looking for vsnprintf
-- Looking for vsnprintf - found
-- Looking for vprintf
-- Looking for vprintf - found
-- Looking for arc4random
-- Looking for arc4random - not found
-- Looking for bsd/stdlib.h
-- Looking for bsd/stdlib.h - not found
-- Looking for open
-- Looking for open - found
-- Looking for realloc
-- Looking for realloc - found
-- Looking for setlocale
-- Looking for setlocale - found
-- Looking for uselocale
-- Looking for uselocale - found
-- Looking for strcasecmp
-- Looking for strcasecmp - found
-- Looking for strncasecmp
-- Looking for strncasecmp - found
-- Looking for strdup
-- Looking for strdup - found
-- Looking for strerror
-- Looking for strerror - found
-- Looking for vsyslog
-- Looking for vsyslog - found
-- Looking for getrandom
-- Looking for getrandom - found
-- Looking for getrusage
-- Looking for getrusage - found
-- Looking for strtoll
-- Looking for strtoll - found
-- Looking for strtoull
-- Looking for strtoull - found
-- Looking for stddef.h
-- Looking for stddef.h - found
-- Check size of int
-- Check size of int - done
-- Check size of int64_t
-- Check size of int64_t - done
-- Check size of long
-- Check size of long - done
-- Check size of long long
-- Check size of long long - done
-- Check size of size_t
-- Check size of size_t - done
-- Check size of ssize_t
-- Check size of ssize_t - done
-- Performing Test HAS_GNU_WARNING_LONG
-- Performing Test HAS_GNU_WARNING_LONG - Failed
-- Performing Test HAVE_ATOMIC_BUILTINS
-- Performing Test HAVE_ATOMIC_BUILTINS - Success
-- Performing Test HAVE___THREAD
-- Performing Test HAVE___THREAD - Success
-- Wrote /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build/shengine/externals/json-c/config.h
-- Wrote /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build/shengine/externals/json-c/json_config.h
-- Performing Test REENTRANT_WORKS
-- Performing Test REENTRANT_WORKS - Success
-- Performing Test BSYMBOLIC_WORKS
-- Performing Test BSYMBOLIC_WORKS - Success
-- Performing Test VERSION_SCRIPT_WORKS
-- Performing Test VERSION_SCRIPT_WORKS - Success
-- Found Doxygen: /usr/bin/doxygen (found version "1.9.1") found components: doxygen missing components: dot
-- Wrote /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build/shengine/externals/json-c/doc/Doxyfile
-- Wrote /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build/shengine/externals/json-c/apps_config.h
-- The CXX compiler identification is GNU 10.2.1
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build
loading /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/source-files.txt
src/flappy-circle.c
loading /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/libs.txt

subdirectories:
		

cmake_minimum_required(VERSION 3.0)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

	

option(SH_SIMULATION_NAME CACHE emptytarget)
project(${SH_SIMULATION_NAME})

option(SH_SIMULATION_BINARY_TYPE CACHE "EXECUTABLE")
if("${SH_SIMULATION_BINARY_TYPE}" STREQUAL "STATIC")
    add_library(${SH_SIMULATION_NAME} STATIC 
    	/mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/src/flappy-circle.c

)
elseif("${SH_SIMULATION_BINARY_TYPE}" STREQUAL "SHARED")
    add_library(${SH_SIMULATION_NAME} SHARED 
    	/mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/src/flappy-circle.c

)
elseif("${SH_SIMULATION_BINARY_TYPE}" STREQUAL "EXECUTABLE")
    add_executable(${SH_SIMULATION_NAME}  
    	/mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/src/flappy-circle.c

)
endif()
target_include_directories(${SH_SIMULATION_NAME} PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/${SH_SIMULATION_NAME}/include
)
target_link_libraries(${SH_SIMULATION_NAME} PUBLIC shengine 	)
set_target_properties(${SH_SIMULATION_NAME} PROPERTIES 
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin  
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

running command cd /mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/build && cmake .. -DSH_ENGINE_BUILD_EDITOR=ON -DSIMULATION_PATH=/mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations -DSH_EDITOR_ASSETS_PATH=/mnt/c/Users/sino3/Desktop/shci-unix-test/shengine/shengine/simulations/flappy-circle/assets/ -DSH_SIMULATION_NAME=flappy-circle -DSH_SIMULATION_BINARY_TYPE=SHARED 
Scanning dependencies of target json-c
[  1%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/arraylist.c.o
[  2%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/debug.c.o
[  3%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_c_version.c.o
[  4%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_object.c.o
[  4%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_object_iterator.c.o
[  5%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_tokener.c.o
[  6%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_util.c.o
[  7%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_visit.c.o
[  8%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/linkhash.c.o
[  9%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/printbuf.c.o
[  9%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/random_seed.c.o
[ 10%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/strerror_override.c.o
[ 11%] Building C object shengine/externals/json-c/CMakeFiles/json-c.dir/json_pointer.c.o
[ 12%] Linking C static library libjson-c.a
[ 12%] Built target json-c
Scanning dependencies of target shvulkan
[ 13%] Building C object shengine/externals/shvulkan/CMakeFiles/shvulkan.dir/shvulkan/src/shvulkan/shVkCore.c.o
[ 13%] Building C object shengine/externals/shvulkan/CMakeFiles/shvulkan.dir/shvulkan/src/shvulkan/shVkMemoryInfo.c.o
[ 14%] Building C object shengine/externals/shvulkan/CMakeFiles/shvulkan.dir/shvulkan/src/shvulkan/shVkPipelineData.c.o
[ 15%] Building C object shengine/externals/shvulkan/CMakeFiles/shvulkan.dir/shvulkan/src/shvulkan/shVkCheck.c.o
[ 16%] Building C object shengine/externals/shvulkan/CMakeFiles/shvulkan.dir/shvulkan/src/shvulkan/shVkDrawLoop.c.o
[ 17%] Linking C static library ../../../../bin/libshvulkan.a
[ 17%] Built target shvulkan
Scanning dependencies of target plyimporter
[ 18%] Building C object shengine/externals/plyimporter/CMakeFiles/plyimporter.dir/PlyImporter/src/plyimporter/plyImporter.c.o
[ 19%] Linking C static library ../../../../bin/libplyimporter.a
[ 19%] Built target plyimporter
Scanning dependencies of target shfd
[ 19%] Building C object shengine/CMakeFiles/shfd.dir/shfd/src/shFile.c.o
[ 20%] Building C object shengine/CMakeFiles/shfd.dir/shfd/src/shfd.c.o
[ 21%] Linking C static library ../../bin/libshfd.a
[ 21%] Built target shfd
Scanning dependencies of target shsharedhost
[ 22%] Building C object shengine/CMakeFiles/shsharedhost.dir/shsharedhost/src/shSharedHost.c.o
[ 23%] Linking C static library libshsharedhost.a
[ 23%] Built target shsharedhost
Scanning dependencies of target shserial
[ 24%] Building C object shengine/externals/shserial/CMakeFiles/shserial.dir/ShSerial/src/shserial/shSerial.c.o
[ 24%] Linking C static library ../../../../shengine/externals/shserial/bin/libshserial.a
[ 24%] Built target shserial
Scanning dependencies of target shgui
[ 25%] Building C object shengine/externals/shgui/CMakeFiles/shgui.dir/shgui/src/shgui.c.o
[ 26%] Linking C static library ../../../../bin/libshgui.a
[ 26%] Built target shgui
Scanning dependencies of target shthreads
[ 27%] Building C object shengine/externals/shthreads/CMakeFiles/shthreads.dir/shthreads/src/shthreads.c.o
[ 28%] Linking C static library ../../../../bin/libshthreads.a
[ 28%] Built target shthreads
Scanning dependencies of target glfw
[ 29%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/context.c.o
[ 30%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/init.c.o
[ 31%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/input.c.o
[ 32%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/monitor.c.o
[ 32%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/platform.c.o
[ 33%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/vulkan.c.o
[ 34%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/window.c.o
[ 35%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/egl_context.c.o
[ 36%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/osmesa_context.c.o
[ 37%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/null_init.c.o
[ 37%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/null_monitor.c.o
[ 38%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/null_window.c.o
[ 39%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/null_joystick.c.o
[ 40%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/posix_module.c.o
[ 41%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/posix_time.c.o
[ 42%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/posix_thread.c.o
[ 42%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/x11_init.c.o
[ 43%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/x11_monitor.c.o
[ 44%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/x11_window.c.o
[ 45%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/xkb_unicode.c.o
[ 46%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/glx_context.c.o
[ 47%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/linux_joystick.c.o
[ 47%] Building C object shengine/externals/glfw/src/CMakeFiles/glfw.dir/posix_poll.c.o
[ 48%] Linking C static library libglfw3.a
[ 48%] Built target glfw
Scanning dependencies of target cglm
[ 48%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/euler.c.o
[ 49%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/affine.c.o
[ 50%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/io.c.o
[ 51%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/quat.c.o
[ 52%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/cam.c.o
[ 53%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/vec2.c.o
[ 53%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/ivec2.c.o
[ 54%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/vec3.c.o
[ 55%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/ivec3.c.o
[ 56%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/vec4.c.o
[ 57%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/ivec4.c.o
[ 58%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/mat2.c.o
[ 58%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/mat3.c.o
[ 59%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/mat4.c.o
[ 60%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/plane.c.o
[ 61%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/frustum.c.o
[ 62%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/box.c.o
[ 63%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/project.c.o
[ 63%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/sphere.c.o
[ 64%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/ease.c.o
[ 65%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/curve.c.o
[ 66%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/bezier.c.o
[ 67%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/ray.c.o
[ 68%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/affine2d.c.o
[ 68%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/ortho_lh_no.c.o
[ 69%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/ortho_lh_zo.c.o
[ 70%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/ortho_rh_no.c.o
[ 71%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/ortho_rh_zo.c.o
[ 72%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/persp_lh_no.c.o
[ 73%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/persp_lh_zo.c.o
[ 73%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/persp_rh_no.c.o
[ 74%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/persp_rh_zo.c.o
[ 75%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/view_lh_no.c.o
[ 76%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/view_lh_zo.c.o
[ 77%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/view_rh_no.c.o
[ 78%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/view_rh_zo.c.o
[ 78%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/project_no.c.o
[ 79%] Building C object shengine/externals/cglm/CMakeFiles/cglm.dir/src/clipspace/project_zo.c.o
[ 80%] Linking C shared library libcglm.so
[ 80%] Built target cglm
Scanning dependencies of target shengine
[ 81%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shengine/shEngine.c.o
[ 82%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shengine/shInput.c.o
[ 83%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shengine/shTime.c.o
[ 84%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shengine/shWindow.c.o
[ 84%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shlinear-algebra/shProjection.c.o
[ 85%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shlinear-algebra/shView.c.o
[ 86%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shscene/shScene.c.o
[ 87%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shmaterialhost/shMaterialHost.c.o
[ 88%] Building C object shengine/CMakeFiles/shengine.dir/shengine/src/shegui/shEgui.c.o
[ 89%] Linking C static library ../../bin/libshengine.a
[ 89%] Built target shengine
Scanning dependencies of target sheditor
[ 89%] Building C object shengine/CMakeFiles/sheditor.dir/sheditor/src/shEditor.c.o
[ 90%] Linking C executable ../../bin/sheditor
[ 90%] Built target sheditor
Scanning dependencies of target shecs-example
[ 91%] Building C object shengine/externals/shecs/CMakeFiles/shecs-example.dir/shecs-example/src/shecs-example.c.o
[ 92%] Linking C executable ../../../../bin/shecs-example
[ 92%] Built target shecs-example
Scanning dependencies of target native-export
[ 92%] Building C object shengine/externals/shgui/externals/native-export/c/CMakeFiles/native-export.dir/native-export/src/native-export.c.o
[ 93%] Linking C static library ../../../../../../../bin/libnative-export.a
[ 93%] Built target native-export
Scanning dependencies of target export-shaders
[ 94%] Building C object shengine/externals/shgui/CMakeFiles/export-shaders.dir/shaders/export-shaders.c.o
[ 95%] Linking C executable export-shaders
[ 95%] Built target export-shaders
Scanning dependencies of target docs
[ 96%] Generating HTML documentation
[ 96%] Built target docs
Scanning dependencies of target json_parse
[ 97%] Building C object shengine/externals/json-c/apps/CMakeFiles/json_parse.dir/json_parse.c.o
[ 98%] Linking C executable json_parse
[ 98%] Built target json_parse
Scanning dependencies of target flappy-circle
[ 98%] Building C object [EXCLUDE_FROM_ALL]/CMakeFiles/flappy-circle.dir/flappy-circle/src/flappy-circle.c.o
[100%] Linking C shared library libflappy-circle.so
[100%] Built target flappy-circle

```

---

    

Build terminated with exit code 0

---

