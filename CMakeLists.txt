cmake_minimum_required(VERSION 3.23)
project(embeddedapp LANGUAGES C)

find_package(embeddedlib REQUIRED)

# Default to production if not specified
if(NOT DEFINED TARGET_GROUP)
    set(TARGET_GROUP production)
endif()

if(TARGET_GROUP STREQUAL production)
    add_subdirectory(src)
    # add_library(${PROJECT_NAME}::embeddedapp ALIAS EmbeddedApp)
elseif(TARGET_GROUP STREQUAL test)
    enable_testing()
    add_subdirectory(src)
    add_subdirectory(unity)
    add_subdirectory(tests)
else()
  message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()

target_link_libraries(embeddedapp PRIVATE embeddedlib::embeddedlib)
