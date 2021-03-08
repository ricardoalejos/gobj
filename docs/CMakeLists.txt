add_custom_target(
    gob_object_graph ALL
    COMMAND dot ${CMAKE_CURRENT_SOURCE_DIR}/gobj_object.dot -Tsvg -o ${CMAKE_CURRENT_SOURCE_DIR}/gobj_object.svg
    SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/gobj_object.dot
)
