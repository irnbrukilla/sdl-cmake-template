cmake_minimum_required(VERSION 2.6)

#
# Execute these commands in this directory:
#
# 1. mkdir build/; cd build/
#
# 2. Choose compiler:
#   Build with native toolchain:
#    cmake -DCMAKE_BUILD_TYPE=Debug ..
#
# 3. make
#

INCLUDE(FindPkgConfig)

set (PROJECT game)

PKG_CHECK_MODULES(SDL2 REQUIRED sdl2 SDL2_ttf SDL2_image)

if (UNIX)
  set(CMAKE_C_FLAGS "-Wall -std=c99 -g")
  set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g")
endif (UNIX)

if (WIN32)
  set(CMAKE_C_FLAGS "-Wall -std=c99 -g")
  set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g")
endif (WIN32)

# include libs
include_directories("lib/")

# add source files
file(GLOB_RECURSE GAME_SRCS "src/*.c" "src/*.cpp")

add_executable(${PROJECT} ${GAME_SRCS})

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT} ${SDL2_LIBRARIES})
