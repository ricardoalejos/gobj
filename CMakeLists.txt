cmake_minimum_required(VERSION 3.0)

execute_process(
    COMMAND git describe
    OUTPUT_VARIABLE GOBJ_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE)

project(
    GOBJ
    LANGUAGES C
    VERSION "${GOBJ_VERSION}")

message("Preparing build for ${CMAKE_PROJECT_NAME} v${GOBJ_VERSION}")
include(${CMAKE_CURRENT_SOURCE_DIR}/utils.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(gobj)

add_subdirectory(gobj)
add_subdirectory(apps)
