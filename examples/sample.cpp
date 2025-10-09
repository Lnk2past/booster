#include "booster/ecs/system/registry.hpp"

#include <entt/entt.hpp>

#include <chrono>
#include <print>

auto greeting(entt::registry &, const std::chrono::duration<double> t) -> void
{
    std::println("YO {}", t.count());
}

extern template booster::system::Registry &booster::system::Registry::instance();
static auto reg_greeting = booster::system::Registry::Registrar("greeting", greeting);
