
add_library(ether-core STATIC)
target_sources(ether-core PRIVATE Rt/application_core.cpp)
target_include_directories(ether-core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ether-core OpenGL::GL glfw external-imgui)
