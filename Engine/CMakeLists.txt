add_executable(ether-engine)
target_sources(ether-engine PRIVATE entry.cpp)

target_link_libraries(ether-engine ether-core)
target_include_directories(ether-engine PRIVATE ${CMAKE_SOURCE_DIR}/Core)

target_include_directories(ether-engine PRIVATE Vendor/imgui)

