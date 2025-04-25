cmake_minimum_required(VERSION 3.10)
project(Survidle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(deps/bgfx.cmake)
add_subdirectory(deps/glm)
add_subdirectory(deps/glfw)
add_subdirectory(deps/nanovg)


add_executable(${PROJECT_NAME} 
  src/core/main.cpp 
  src/core/game.cpp 
  src/core/inputHandler.cpp
  src/entities/Player.cpp

  #"include/test.h" 
  #"include/game.h" 
  #"include/inputHandler.h" 
 #"include/Player.h"
)


target_include_directories(${PROJECT_NAME} PUBLIC 
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/deps/bgfx.cmake/bgfx/examples/common # include Utils
  ${PROJECT_SOURCE_DIR}/deps/nanovg  # include NanoVG
)

target_link_libraries(${PROJECT_NAME} 
    bgfx
    bx
    glm
    bimg
    glfw
    nanovg
)