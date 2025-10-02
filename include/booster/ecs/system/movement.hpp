#pragma once

#include <entt/entt.hpp>

#include <chrono>

namespace booster::system
{
auto movement(entt::registry &registry, const std::chrono::duration<double> t) -> void;
} // namespace booster::system
