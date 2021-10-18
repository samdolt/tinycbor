# Copyright (c) Microsoft Corporation.
# Licensed under the MIT License.

project(intel_tinycbor LANGUAGES C)

cmake_minimum_required(VERSION 3.10)

option(build_tools "Build the cbor tools. Note: This will install the cjson library as a dependency" OFF)

add_library(tinycbor
    ${CMAKE_CURRENT_LIST_DIR}/src/cborencoder.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborencoder_close_container_checked.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborencoder_float.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborerrorstrings.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborparser.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborparser_dup_string.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborparser_float.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborpretty.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborpretty_stdio.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cbortojson.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborvalidation.c
)

target_include_directories(tinycbor
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/src
)

include(CheckSymbolExists)
check_symbol_exists(open_memstream "stdio.h" HAVE_OPEN_MEMSTREAM)

if(HAVE_OPEN_MEMSTREAM)
    target_sources(tinycbor
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/src/open_memstream.c
    )
else()
    add_definitions(-DWITHOUT_OPEN_MEMSTREAM)
    message(
        WARNING
        "funopen and fopencookie unavailable, open_memstream can not be implemented and conversion to JSON will not work properly!"
    )
endif()


add_library(intel::tinycbor ALIAS tinycbor)

set_target_properties(tinycbor PROPERTIES PUBLIC_HEADER "src/cbor.h;src/cborjson.h;src/tinycbor-version.h")

include(GNUInstallDirs)
install(TARGETS tinycbor
        LIBRARY
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE
          DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tinycbor
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/examples)

if(${build_tools})
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tools)
endif()
