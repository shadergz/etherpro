cmake_minimum_required(VERSION 3.24)
project(etherpro)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)

add_subdirectory(Core)
add_subdirectory(Engine)

install(TARGETS ether-core ether-engine DESTINATION ${CMAKE_SOURCE_DIR}/Runtime)
