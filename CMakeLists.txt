cmake_minimum_required(VERSION 3.20)

project(iortc)
set(project_name "I/O Realtime Core")
set(project_version 0.1)

option(DEBUG "debugging code" ON)
#option(BUILD_STATIC_LIBS "Build the static library" ON)
#option(BUILD_SHARED_LIBS "Build the shared library" ON)
#option(BUILD_TESTS "Build test programs" OFF)

include_directories(include)

add_executable( iocli
    src/cli.c
)
add_executable( iortc
    src/main.c
)

set(version_string "${project_version}")
if (DEBUG)
    add_compile_definitions(-DCONFIG_DEBUG)
    set(version_string "${version_string}-dirty")
endif(DEBUG)

add_compile_definitions(
    -D_APP_FULL_NAME="${project_name}"
    -D_VERSION=${project_version}
    -D_VERSION_STRING="${version_string}"
)