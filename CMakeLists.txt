cmake_minimum_required(VERSION 3.10)

project(welcome-tour VERSION 1.0)

set(APP_ID "dev.rlxos.WeclomeTour")
string(REPLACE "." "/" APP_PREFIX "/${APP_ID}/")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(rlxosUtils)
find_package(GTKMM)
find_package(Handy)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DDEBUG)
    set(DATA_DIR "${CMAKE_BINARY_DIR}")
endif ()

configure_file(config.h.in ${CMAKE_BINARY_DIR}/config.h)

add_subdirectory(assets)
add_subdirectory(src)
