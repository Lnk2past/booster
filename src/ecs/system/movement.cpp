#include "booster/ecs/system/movement.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"

#include <mp-units/systems/si/chrono.h>
#include <mp-units/systems/si/unit_symbols.h>
#include <mp-units/systems/si/units.h>

#include <random>

namespace booster::system
{
auto movement(entt::registry &registry, const std::chrono::duration<double> t) -> void
{
    using namespace mp_units::si::unit_symbols;

    auto view = registry.view<booster::component::Position, const booster::component::Velocity>();
    view.each([t](auto &position, const auto &velocity) {
        mp_units::quantity<mp_units::si::second, double> qdt{t.count() * 1.0 * s};
        position.x += qdt * velocity.x;
        position.y += qdt * velocity.y;
    });
}
} // namespace booster::system