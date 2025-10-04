cmake_minimum_required(VERSION 3.18.4)

project (booster)

set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(EnTT CONFIG REQUIRED)
find_package(mp-units CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_compile_options(-std=c++23)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(apps)
