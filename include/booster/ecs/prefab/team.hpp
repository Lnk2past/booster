#pragma once

#include <entt/entt.hpp>
#include <nlohmann/json.hpp>

#include <vector>

namespace booster::prefab
{
auto team(entt::registry &registry, const std::vector<entt::entity> &entities, const nlohmann::json &config) -> void;
} // namespace booster::prefab
