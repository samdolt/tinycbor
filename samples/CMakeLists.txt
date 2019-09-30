
cmake_minimum_required(VERSION "3.2")

add_executable(tinycbor_sample
    ${CMAKE_CURRENT_LIST_DIR}/simplereader.c
)

target_link_libraries(tinycbor_sample
    PRIVATE
        tinycbor
)
