#pragma once

#include <mp-units/systems/si/units.h>

namespace booster::component
{
struct Velocity
{
    mp_units::quantity<mp_units::si::metre / mp_units::si::second, double> x{};
    mp_units::quantity<mp_units::si::metre / mp_units::si::second, double> y{};
};
} // namespace booster::component
