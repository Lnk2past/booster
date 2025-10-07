add_library(libbooster STATIC ecs/manager.cpp ecs/system/movement.cpp ecs/prefab/dynamic_body.cpp ecs/prefab/team.cpp ecs/prefab/entity.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(libbooster PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(libbooster PUBLIC nlohmann_json::nlohmann_json EnTT::EnTT mp-units::mp-units spdlog::spdlog)
