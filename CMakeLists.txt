cmake_minimum_required(VERSION 3.10)
project(Survidle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vcpkg
#set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
#set(CMAKE_PREFIX_PATH "D:/SFML Projects/Survidle/vcpkg/installed/x64-windows/share")
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/share")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# Force common exe location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# SFML
find_package(SFML 3.0 COMPONENTS System Window Graphics CONFIG REQUIRED)

if (NOT SFML_FOUND)
  message(STATUS "SFML not found with VCPKG. Fetching it...")
  include(FetchContent)
  FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.x
  )
  FetchContent_MakeAvailable(sfml)
endif()

add_subdirectory(src)