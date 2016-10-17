cmake_minimum_required(VERSION 3.0)
project(pi-am2315)

set(PI_AM2315_VERSION "pi-am2315-version-v1.0.0")

# Check to see if we are running on a Raspberry PI
#
if(EXISTS "/opt/vc/include/bcm_host.h")
    MESSAGE("-- bcm_host.h found, we must be on a Raspberry PI")
    set(BCMHOST found)
else()
    MESSAGE("-- bcm_host.h not found we must NOT on in a Raspberry PI")
endif()

# Set The correct compiler
#
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_C_FLAGS "-std=gnu99")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if(DEFINED BCMHOST)
        set(CMAKE_C_FLAGS "-std=gnu99 -lwiringPi -pthread -lrt")
    else()
        set(CMAKE_C_FLAGS "-std=gnu99 -pthread -lrt")
    endif()
endif ()


# Versioning
#
configure_file(src/version_config.h.in ${CMAKE_BINARY_DIR}/generated/version_config.h)
include_directories(${CMAKE_BINARY_DIR}/generated/)


set(SOURCE_FILES
        src/main.c
        src/pi_am2315.c
        src/pi_am2315.h)

add_executable(pi-am2315 ${SOURCE_FILES})

install(TARGETS pi-am2315 DESTINATION bin)