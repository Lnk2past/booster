#pragma once

#include <entt/entt.hpp>

#include <cstdint>
#include <vector>

namespace booster::prefab
{
auto create_entities(entt::registry &registry, std::uint32_t count) -> std::vector<entt::entity>;
} // namespace booster::prefab
