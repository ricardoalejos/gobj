MACRO(SUBDIRLIST result target_dir)
  FILE(GLOB children RELATIVE ${target_dir} ${target_dir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${target_dir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
