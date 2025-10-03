#pragma once

#include <mp-units/systems/si/units.h>
#include <nlohmann/json.hpp>

NLOHMANN_JSON_NAMESPACE_BEGIN
template <mp_units::Unit auto R, typename Rep> struct adl_serializer<mp_units::quantity<R, Rep>>
{
    static auto to_json(json &j, const mp_units::quantity<R, Rep> &quantity) -> void
    {
        j = quantity.numerical_value_in(decltype(R){});
    }

    static auto from_json(const json &j, mp_units::quantity<R, Rep> &quantity) -> void
    {
        quantity = j.get<Rep>() * decltype(R){};
    }
};
NLOHMANN_JSON_NAMESPACE_END