#include "booster/ecs/prefab/entity.hpp"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <algorithm>

namespace booster::prefab
{
auto create_entities(entt::registry &registry, std::uint32_t count) -> std::vector<entt::entity>
{
    auto entities = std::vector<entt::entity>(count);
    std::ranges::generate(entities, [&]() {
        auto entity = registry.create();
        spdlog::basic_logger_mt(std::format("entity_{}", entt::to_integral(entity)),
                                std::format("logs/entity_{}/state.log", entt::to_integral(entity)));
        return entity;
    });
    return entities;
}
} // namespace booster::prefab
