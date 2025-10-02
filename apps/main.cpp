#include "booster/booster.hpp"

#include <mp-units/format.h>
#include <mp-units/systems/si/unit_symbols.h>
#include <mp-units/systems/si/units.h>

#include <chrono>
#include <print>

auto main(int, char **) -> int
{
    using namespace std::chrono_literals;
    using namespace mp_units::si::unit_symbols;

    auto registry = entt::registry{};

    for (auto i = 0u; i < 10u; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<booster::component::Position>(entity, 0.0 * m, 0.0 * m);
        registry.emplace<booster::component::Velocity>(entity, 1.0 * m / s, 1.0 * m / s);
    }

    auto view = registry.view<const booster::component::Position>();
    view.each([](const auto &position) { std::println("{},{}", position.x, position.y); });

    booster::system::movement(registry, 1.0s);

    view.each([](const auto &position) { std::println("{},{}", position.x, position.y); });
}
