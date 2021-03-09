add_library(gobj STATIC gobj.c)
target_compile_definitions(gobj PUBLIC GOBJ_VERSION="v${GOBJ_VERSION}")
install(TARGETS gobj DESTINATION lib)
install(FILES gobj.h DESTINATION include)
