#include "booster/ecs/system/movement.hpp"
#include "booster/ecs/component/position.hpp"

#include <random>

namespace booster::system
{
auto movement(entt::registry &registry) -> void
{
    auto view = registry.view<booster::component::Position>();
    view.each([](auto &position) {
        position.x += 1.0;
        position.y += 1.0;
    });
}
} // namespace booster::system