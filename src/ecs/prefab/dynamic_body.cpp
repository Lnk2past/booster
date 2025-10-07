#include "booster/ecs/prefab/dynamic_body.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/json.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"
#include "booster/ecs/prefab/registry.hpp"

#include <mp-units/systems/si/unit_symbols.h>

#include <format>

namespace booster::prefab
{
auto dynamic_body(entt::registry &registry, const std::vector<entt::entity> &entities, const nlohmann::json &config)
    -> void
{
    using namespace mp_units::si::unit_symbols;
    for (const auto entity : entities)
    {
        registry.emplace<booster::component::Position>(entity,
                                                       config.at("position").get<booster::component::Position>());
        registry.emplace<booster::component::Velocity>(entity,
                                                       config.at("velocity").get<booster::component::Velocity>());
        registry.emplace<booster::component::Acceleration>(
            entity, config.at("acceleration").get<booster::component::Acceleration>());
    }
}

static auto reg_dynamic_body = Registry::Registrar("dynamic_body", dynamic_body);
} // namespace booster::prefab
