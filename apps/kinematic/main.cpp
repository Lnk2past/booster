#include "booster/ecs/manager.hpp"
#include "booster/ecs/prefab/dynamic_body.hpp"
#include "booster/ecs/system/movement.hpp"

#include <chrono>

auto main(int, char **) -> int
{
    using namespace std::chrono_literals;

    auto manager = booster::Manager();
    manager.initialize();

    // TODO: drive via JSON
    manager.systems.push_back(booster::system::movement);
    booster::prefab::dynamic_body(manager.registry, 10);

    for (auto i = 0; i < 10; ++i)
    {
        manager.update(1.0s);
    }

    manager.finalize();
}
