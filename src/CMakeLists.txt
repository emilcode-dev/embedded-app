add_subdirectory(localmodule)

add_executable(embeddedapp embeddedapp_main.c)

target_link_libraries(embeddedapp PRIVATE localmodule)