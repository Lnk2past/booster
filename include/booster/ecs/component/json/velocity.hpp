#pragma once

#include <nlohmann/json.hpp>

#include "booster/ecs/component/velocity.hpp"
#include "booster/utility/json.hpp"

NLOHMANN_JSON_NAMESPACE_BEGIN
template <> struct adl_serializer<booster::component::Velocity>
{
    static auto to_json(json &j, const booster::component::Velocity &velocity) -> void
    {
        j = json::array({velocity.x, velocity.y});
    }

    static auto from_json(const json &j, booster::component::Velocity &velocity) -> void
    {
        velocity.x = j[0];
        velocity.y = j[1];
    }
};
NLOHMANN_JSON_NAMESPACE_END
