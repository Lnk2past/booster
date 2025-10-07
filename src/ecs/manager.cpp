#include "booster/ecs/manager.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/json.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/team.hpp"
#include "booster/ecs/component/velocity.hpp"

#include <print>

namespace booster
{
Manager::Manager()
{
}

auto Manager::initialize() -> void
{
}

auto Manager::update(const std::chrono::duration<double> t) -> void
{
    for (auto &system : systems)
    {
        system(registry, t);
    }
}

auto Manager::finalize() -> void
{
    auto view = registry.view<const booster::component::Position, const booster::component::Velocity,
                              const booster::component::Acceleration, const booster::component::Team>();
    auto json = nlohmann::json::array();
    view.each([&json](const auto &position, const auto &velocity, const auto &acceleration, const auto &team) {
        json.push_back({team, position, velocity, acceleration});
    });
    std::println("{}", json.dump());
}

} // namespace booster
