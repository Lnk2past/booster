#include "booster/ecs/manager.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/json.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"

#include <mp-units/systems/si/unit_symbols.h>
#include <mp-units/systems/si/units.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <format>
#include <iostream>
#include <print>

namespace booster
{
Manager::Manager()
{
    using namespace mp_units::si::unit_symbols;
    for (auto i = 0u; i < 10u; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<booster::component::Position>(entity);
        registry.emplace<booster::component::Velocity>(entity);
        registry.emplace<booster::component::Acceleration>(entity, 1.0 * m / s / s, 1.0 * m / s / s);
        spdlog::basic_logger_mt(std::format("entity_{}", entt::to_integral(entity)),
                                std::format("logs/entity_{}/state.log", entt::to_integral(entity)));
    }
}

auto Manager::initialize() -> void
{
}

auto Manager::update(const std::chrono::duration<double> t) -> void
{
    using namespace std::chrono_literals;
    for (auto &system : systems)
    {
        system(registry, t);
    }
}

auto Manager::finalize() -> void
{
    auto view = registry.view<const booster::component::Position, const booster::component::Velocity,
                              const booster::component::Acceleration>();
    auto json = nlohmann::json::array();
    view.each([&json](const auto &position, const auto &velocity, const auto &acceleration) {
        json.push_back({position, velocity, acceleration});
    });
    std::cout << json << std::endl;
}

} // namespace booster
