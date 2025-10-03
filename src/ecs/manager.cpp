#include "booster/ecs/manager.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/json.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"
#include "booster/ecs/system/movement.hpp"

#include <mp-units/format.h>
#include <mp-units/systems/si/unit_symbols.h>
#include <mp-units/systems/si/units.h>

#include <print>

namespace booster
{
Manager::Manager()
{
    using namespace mp_units::si::unit_symbols;
    for (auto i = 0u; i < 10u; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<booster::component::Position>(entity, 0.0 * m, 0.0 * m);
        registry.emplace<booster::component::Velocity>(entity, 0.0 * m / s, 0.0 * m / s);
        registry.emplace<booster::component::Acceleration>(entity, 1.0 * m / s / s, 1.0 * m / s / s);
    }
}

auto Manager::initialize() -> void
{
}

auto Manager::update(const std::chrono::duration<double> t) -> void
{
    using namespace std::chrono_literals;
    booster::system::movement(registry, t);
}

auto Manager::finalize() -> void
{
    auto view = registry.view<const booster::component::Position, const booster::component::Velocity,
                              const booster::component::Acceleration>();
    auto json = nlohmann::json::array();
    view.each([&json](const auto &position, const auto &velocity, const auto &acceleration) {
        json.push_back({position, velocity, acceleration});
    });
    std::println("{}", json.dump());
}

} // namespace booster
