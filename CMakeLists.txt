cmake_minimum_required(VERSION 2.8)
project(GOBJ C)
include(${CMAKE_CURRENT_SOURCE_DIR}/utils.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(gobj)

add_subdirectory(gobj)
add_subdirectory(apps)
