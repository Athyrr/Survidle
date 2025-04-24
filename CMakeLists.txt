cmake_minimum_required(VERSION 3.10)
project(Survidle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(deps/bgfx.cmake)
add_subdirectory(deps/glfw)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
 )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/deps/bgfx.cmake/bgfx/examples/common)
#target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/deps/bgfx.cmake/bgfx/examples/common/entry)

target_link_libraries(${PROJECT_NAME} 
    bgfx
    bx
    bimg
    glfw
)