#pragma once

#include <nlohmann/json.hpp>

#include "booster/ecs/component/position.hpp"
#include "booster/utility/json.hpp"

NLOHMANN_JSON_NAMESPACE_BEGIN
template <> struct adl_serializer<booster::component::Position>
{
    static auto to_json(json &j, const booster::component::Position &position) -> void
    {
        j = json::array({position.x, position.y});
    }

    static auto from_json(const json &j, booster::component::Position &position) -> void
    {
        position.x = j[0];
        position.y = j[1];
    }
};
NLOHMANN_JSON_NAMESPACE_END
