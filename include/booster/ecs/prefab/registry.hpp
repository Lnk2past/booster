#pragma once

#include "booster/ecs/registry.hpp"

#include <entt/entt.hpp>
#include <nlohmann/json.hpp>

#include <vector>

namespace booster::prefab
{
using Registry =
    booster::FunctionRegistry<auto(entt::registry &, const std::vector<entt::entity> &, const nlohmann::json &)->void>;
} // namespace booster::prefab
