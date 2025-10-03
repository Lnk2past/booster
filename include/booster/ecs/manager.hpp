#pragma once

#include <entt/entt.hpp>

#include <chrono>

namespace booster
{
struct Manager
{
    Manager();

    auto initialize() -> void;

    auto update(const std::chrono::duration<double> t) -> void;

    auto finalize() -> void;

    entt::registry registry{};
};
} // namespace booster
