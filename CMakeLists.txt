cmake_minimum_required(VERSION 3.20)

project(iortc LANGUAGES C)
set(project_name "I/O Realtime Core")

option(DEBUG "debugging code" ON)

## ALL TARGETS
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")

## TARGET "iortc"
add_executable( iortc
    src/main.c
)
target_include_directories(iortc PRIVATE include)
target_compile_options(iortc PRIVATE -Wall)

## TARGET "iocli"
add_executable( iocli
    src/cli.c
)
target_compile_options(iocli PRIVATE -Wall)

### ROUTINES ...
execute_process(COMMAND
    git describe --tag
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE project_version
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

set(version_string "v${project_version}")
if (DEBUG)
    add_compile_definitions(-DCONFIG_DEBUG)

    execute_process(COMMAND
        git describe --long --dirty
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_SHA1
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(COMMAND
        sh -c "${CMAKE_C_COMPILER} --version | head -1"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE COMPILER_VERSION_STRING
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    get_target_property(_ret iortc COMPILE_OPTIONS)
    string(STRIP "${CMAKE_C_FLAGS} ${_ret}" _ret)
    set(COMPILER_VERSION_STRING "${COMPILER_VERSION_STRING} & FLAGS: ${_ret}")

    set(version_string "${version_string} @ ${COMPILER_VERSION_STRING}")
endif(DEBUG)

add_compile_definitions(
    -D_APP_FULL_NAME="${project_name}"
    -D_VERSION=${project_version}
    -D_VERSION_STRING="${version_string}"
)