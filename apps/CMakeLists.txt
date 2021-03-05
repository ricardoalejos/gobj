subdirlist(SUBDIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

message("Adding apps from ${CMAKE_CURRENT_SOURCE_DIR}")

foreach(SUBDIRECTORY ${SUBDIRECTORIES})
  if(NOT "${SUBDIRECTORY}" STREQUAL "CMakeFiles")
    message("Adding application: ${SUBDIRECTORY}")
    add_subdirectory(${SUBDIRECTORY})
  endif()
endforeach()

