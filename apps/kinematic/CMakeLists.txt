add_executable(kinematic main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(kinematic PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(kinematic PUBLIC libbooster)
