
cmake_minimum_required(VERSION "3.2")

add_library(tinycbor
    ${CMAKE_CURRENT_LIST_DIR}/src/cborencoder.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborencoder_close_container_checked.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborerrorstrings.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborparser.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborparser_dup_string.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborpretty.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborpretty_stdio.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cbortojson.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cborvalidation.c
    ${CMAKE_CURRENT_LIST_DIR}/src/open_memstream.c
    ${CMAKE_CURRENT_LIST_DIR}/tools/json2cbor/json2cbor.c
)

target_include_directories(tinycbor
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/inc
        ${CMAKE_CURRENT_LIST_DIR}/tools/inc
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/samples)
