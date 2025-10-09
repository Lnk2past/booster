add_executable(runner main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(runner PUBLIC "${CMAKE_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(runner PUBLIC -rdynamic -Wl,--whole-archive libbooster -Wl,--no-whole-archive)
