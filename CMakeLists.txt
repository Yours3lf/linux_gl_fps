#cmake ver req
cmake_minimum_required(VERSION 2.8)
	
set(project_name linux_gl_fps)

#project name
project(${project_name})

#so that it talks to us
set(CMAKE_VERBOSE_MAKEFILE ON)

if(UNIX)
	add_definitions( "-Wall -Wno-long-long -ansi -pedantic -std=c++0x" )
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
  add_definitions("-DDebug")
  message("Debug mode")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL Release)
  add_definitions("-DRelease")
  message("Release mode")
endif()

#header files source
include_directories(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/external/include/)
link_directories(${CMAKE_SOURCE_DIR}/external/lib/)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX)
	include_directories(
	/usr/include/gtk-2.0
	/usr/lib/x86_64-linux-gnu/gtk-2.0/include
	/usr/include/atk-1.0
	/usr/include/cairo
	/usr/include/gdk-pixbuf-2.0
	/usr/include/pango-1.0
	/usr/include/gio-unix-2.0/
	/usr/include/glib-2.0
	/usr/lib/x86_64-linux-gnu/glib-2.0/include
	/usr/include/pixman-1
	/usr/include/freetype2
	/usr/include/libpng12
	)
endif()

if(UNIX)
	set(${project_name}_external_libs sfml-system GL GLEW freetype)
endif()
	
#adding the project's exe
add_library(${project_name} SHARED main font)

target_link_libraries(${project_name} ${${project_name}_external_libs})