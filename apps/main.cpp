#include "booster/booster.hpp"

#include <fmt/format.h>
#include <fmt/ranges.h>

auto main(int, char **) -> int
{
    auto registry = entt::registry{};

    for (auto i = 0u; i < 10u; ++i)
    {
        const auto entity = registry.create();
        registry.emplace<booster::component::Position>(entity, i * 1.f, i * 1.f);
    }

    auto view = registry.view<const booster::component::Position>();
    view.each([](const auto &position) { fmt::println("{},{}", position.x, position.y); });

    booster::system::movement(registry);

    view.each([](const auto &position) { fmt::println("{},{}", position.x, position.y); });
}
