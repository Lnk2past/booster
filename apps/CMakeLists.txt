add_executable(booster main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(booster PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(booster PUBLIC libbooster)
