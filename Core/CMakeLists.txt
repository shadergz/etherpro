
add_library(ether-core STATIC SHARED)
target_sources(ether-core PRIVATE Rt/application_core.cpp)
target_include_directories(ether-core PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

