#include "booster/ecs/system/movement.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"

#include <mp-units/format.h>
#include <mp-units/ostream.h>
#include <mp-units/systems/si/chrono.h>
#include <mp-units/systems/si/units.h>
#include <spdlog/spdlog.h>

#include <random>

namespace booster::system
{
auto movement(entt::registry &registry, const std::chrono::duration<double> t) -> void
{
    auto view =
        registry
            .view<booster::component::Position, booster::component::Velocity, const booster::component::Acceleration>();
    view.each([t](const auto entity, auto &position, auto &velocity, const auto &acceleration) {
        mp_units::quantity<mp_units::si::second, double> qdt{t.count() * 1.0 * mp_units::si::second};
        velocity.x += qdt * acceleration.x;
        velocity.y += qdt * acceleration.y;
        position.x += qdt * velocity.x;
        position.y += qdt * velocity.y;
        auto logger = spdlog::get(std::format("entity_{}", entt::to_integral(entity)));
        logger->info("<{::N[.2f]},{::N[.2f]}>", position.x, position.y);
    });
}
} // namespace booster::system