cmake_minimum_required(VERSION 3.18.4)

project (booster)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(EnTT CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_compile_options(-std=c++20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(apps)

export(TARGETS booster FILE "${CMAKE_BINARY_DIR}/boosterTargets.cmake")
