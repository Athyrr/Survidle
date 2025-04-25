cmake_minimum_required(VERSION 3.10)
project(nanovg)

add_library(nanovg STATIC
    nanovg.cpp
    nanovg_bgfx.cpp
    stb_impl.cpp
)

target_include_directories(nanovg PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/stb
)

target_link_libraries(nanovg PUBLIC bgfx bx)
