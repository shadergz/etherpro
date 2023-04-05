cmake_minimum_required(VERSION 3.24)
project(etherpro)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binaries)

find_package(OpenGL REQUIRED)

add_subdirectory(Vendor/fmt)
add_subdirectory(Vendor/glfw)

add_library(external-imgui STATIC)
target_sources(external-imgui PRIVATE 
	Vendor/imgui/imgui.cpp
	Vendor/imgui/imgui_draw.cpp
	Vendor/imgui/imgui_tables.cpp
	Vendor/imgui/imgui_widgets.cpp

	Vendor/imgui/backends/imgui_impl_opengl3.cpp
	Vendor/imgui/backends/imgui_impl_glfw.cpp
)

target_include_directories(external-imgui PRIVATE Vendor/imgui)
target_link_libraries(external-imgui PRIVATE glfw OpenGL::GL)

add_subdirectory(Core)
add_subdirectory(Engine)

install(TARGETS ether-core ether-engine DESTINATION ${CMAKE_SOURCE_DIR}/Runtime)
