#include "booster/ecs/manager.hpp"
#include "booster/ecs/system/movement.hpp"

#include <chrono>

auto main(int, char **) -> int
{
    using namespace std::chrono_literals;

    auto manager = booster::Manager();
    manager.initialize();
    manager.systems.push_back(booster::system::movement);

    for (auto i = 0; i < 10; ++i)
    {
        manager.update(1.0s);
    }

    manager.finalize();
}
