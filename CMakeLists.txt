#cmake ver req
cmake_minimum_required(VERSION 2.8)
	
set(project_name linux_gl_fps)

#project name
project(${project_name})

#so that it talks to us
set(CMAKE_VERBOSE_MAKEFILE ON)

set( use_32_bit false )

#32 bits
if( use_32_bit )
  set(CMAKE_CXX_FLAGS "-m32")
  set(CMAKE_C_FLAGS "-m32")
  set(CMAKE_SHARED_LINKER_FLAGS "-m32")
endif()

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

#32 bits
if( use_32_bit )
	link_directories(/usr/lib/i386-linux-gnu)
	link_directories(/lib/i386-linux-gnu)
endif()

#header files source
include_directories(${CMAKE_SOURCE_DIR})
link_directories(${CMAKE_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/external/include/)
if( use_32_bit )
	link_directories(${CMAKE_SOURCE_DIR}/external/lib/32bit)
else()
	link_directories(${CMAKE_SOURCE_DIR}/external/lib/64bit)
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX)
	set(${project_name}_external_libs GLEW sfml-system GL freetype)
endif()
	
#adding the project's exe
add_library(${project_name} SHARED main font)

target_link_libraries(${project_name} ${${project_name}_external_libs})