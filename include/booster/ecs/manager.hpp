#pragma once

#include <entt/entt.hpp>

#include <chrono>
#include <functional>
#include <vector>

namespace booster
{
struct Manager
{
    Manager();

    auto initialize() -> void;

    auto update(const std::chrono::duration<double> t) -> void;

    auto finalize() -> void;

    entt::registry registry{};

    using System = auto(entt::registry &, const std::chrono::duration<double>) -> void;
    std::vector<std::function<System>> systems{};
};
} // namespace booster
