add_library(gobj gobj.c)
target_compile_definitions(gobj PUBLIC GOBJ_VERSION="v${GOBJ_VERSION}")
install(TARGETS gobj DESTINATION lib)
install(FILES gobj.h DESTINATION include)
