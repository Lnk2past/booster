#pragma once

#include <entt/entt.hpp>

#include <cstdint>

namespace booster::prefab
{
auto dynamic_body(entt::registry &registry, const std::uint32_t n = 1) -> void;
} // namespace booster::prefab
