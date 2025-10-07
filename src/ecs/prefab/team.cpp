#include "booster/ecs/component/team.hpp"
#include "booster/ecs/component/json/team.hpp"
#include "booster/ecs/prefab/registry.hpp"
#include "booster/ecs/prefab/team.hpp"

namespace booster::prefab
{
auto team(entt::registry &registry, const std::vector<entt::entity> &entities, const nlohmann::json &config) -> void
{
    for (const auto entity : entities)
    {
        registry.emplace<booster::component::Team>(entity, config.get<booster::component::Team>());
    }
}

static auto reg_team = Registry::Registrar("team", team);
} // namespace booster::prefab
