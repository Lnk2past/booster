#pragma once

#include "booster/ecs/registry.hpp"

#include <entt/entt.hpp>

#include <cstdint>

namespace booster::prefab
{
using Registry = booster::FunctionRegistry<auto(entt::registry &, const std::uint32_t)->void>;
} // namespace booster::prefab
