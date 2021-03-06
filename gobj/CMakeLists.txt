add_library(gobj gobj.c)
install(TARGETS gobj DESTINATION lib)
install(FILES gobj.h DESTINATION include)
