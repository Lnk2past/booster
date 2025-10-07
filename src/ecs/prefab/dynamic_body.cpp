#include "booster/ecs/prefab/dynamic_body.hpp"
#include "booster/ecs/component/acceleration.hpp"
#include "booster/ecs/component/position.hpp"
#include "booster/ecs/component/velocity.hpp"
#include "booster/ecs/prefab/registry.hpp"

#include <mp-units/systems/si/unit_symbols.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include <format>

namespace booster::prefab
{
auto dynamic_body(entt::registry &registry, const std::uint32_t n) -> void
{
    using namespace mp_units::si::unit_symbols;
    for (auto i = std::uint32_t{}; i < n; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<booster::component::Position>(entity);
        registry.emplace<booster::component::Velocity>(entity);
        registry.emplace<booster::component::Acceleration>(entity, 1.0 * m / s / s, 1.0 * m / s / s);
        spdlog::basic_logger_mt(std::format("entity_{}", entt::to_integral(entity)),
                                std::format("logs/entity_{}/state.log", entt::to_integral(entity)));
    }
}

static auto reg_dynamic_body = Registry::Registrar("dynamic_body", dynamic_body);
} // namespace booster::prefab
