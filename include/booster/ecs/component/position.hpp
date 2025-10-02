#pragma once

#include <mp-units/systems/si/units.h>

namespace booster::component
{
struct Position
{
    mp_units::quantity<mp_units::si::metre, double> x{};
    mp_units::quantity<mp_units::si::metre, double> y{};
};
} // namespace booster::component
