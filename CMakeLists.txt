cmake_minimum_required(VERSION 3.0)

option(GOBJ_VERSION "Version of the GOBJ library" "0.0.0")

project(
    GOBJ
    LANGUAGES C
    VERSION "${GOBJ_VERSION}")

message("Preparing build for ${CMAKE_PROJECT_NAME} (version ${GOBJ_VERSION}).")
set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_INCLUDEDIR include)
configure_file(gobj.pc.in gobj.pc @ONLY)
install(
    FILES ${CMAKE_BINARY_DIR}/gobj.pc 
    DESTINATION lib/pkgconfig
)

include(${CMAKE_CURRENT_SOURCE_DIR}/utils.cmake)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(gobj)

add_subdirectory(gobj)
add_subdirectory(apps)
add_subdirectory(docs)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${GOBJ_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${GOBJ_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${GOBJ_VERSION_PATCH}")
include(CPack)
