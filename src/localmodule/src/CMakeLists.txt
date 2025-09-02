add_library(localmodule STATIC localmodule.c)

target_include_directories(localmodule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include PRIVATE .)