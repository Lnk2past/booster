add_library(libbooster STATIC ecs/system/movement.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(libbooster PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(libbooster PUBLIC nlohmann_json::nlohmann_json EnTT::EnTT mp-units::mp-units)
