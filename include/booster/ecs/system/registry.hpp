#pragma once

#include "booster/ecs/registry.hpp"

#include <entt/entt.hpp>

#include <chrono>

namespace booster::system
{
using Registry = booster::FunctionRegistry<auto(entt::registry &, const std::chrono::duration<double>)->void>;
} // namespace booster::system
