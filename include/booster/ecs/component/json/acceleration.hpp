#pragma once

#include <nlohmann/json.hpp>

#include "booster/ecs/component/acceleration.hpp"
#include "booster/utility/json.hpp"

NLOHMANN_JSON_NAMESPACE_BEGIN
template <> struct adl_serializer<booster::component::Acceleration>
{
    static auto to_json(json &j, const booster::component::Acceleration &acceleration) -> void
    {
        j = json::array({acceleration.x, acceleration.y});
    }

    static auto from_json(const json &j, booster::component::Acceleration &acceleration) -> void
    {
        acceleration.x = j[0];
        acceleration.y = j[1];
    }
};
NLOHMANN_JSON_NAMESPACE_END
