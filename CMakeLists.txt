cmake_minimum_required(VERSION 3.16)
project(
  rpgGame
  VERSION 1.0.0
  LANGUAGES C CXX
)

# Defualt build debug if not type was given
if(NOT CMAKE_BUILD_TYPE)
  set(DFT_BLD "Debug")
  message(STATUS "Set the build type to `${DFT_BLD}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${DFT_BLD} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Message project build
message(STATUS "${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory
# automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# For NeoVim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add vendor dependency
add_subdirectory(vendored EXCLUDE_FROM_ALL)

add_executable(
  rpgGame
  ${CMAKE_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(rpgGame SDL3::SDL3 glad)
