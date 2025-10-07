#include "booster/ecs/manager.hpp"
#include "booster/ecs/prefab/registry.hpp"
#include "booster/ecs/system/registry.hpp"

#include <nlohmann/json.hpp>

#include <chrono>
#include <fstream>

auto main(int argc, char **argv) -> int
{
    if (argc < 1)
    {
        return 1;
    }

    auto manager = booster::Manager();
    manager.initialize();

    auto input = std::ifstream{argv[1]};
    auto config = nlohmann::json::parse(input);

    for (auto &system : config["systems"])
    {
        auto fn = booster::system::Registry::instance()[system];
        manager.systems.push_back(fn);
    }

    for (auto &entity : config["entities"].items())
    {
        auto fn = booster::prefab::Registry::instance()[entity.key()];
        fn(manager.registry, static_cast<std::uint32_t>(entity.value()));
    }

    using namespace std::chrono_literals;
    for (auto i = 0; i < 10; ++i)
    {
        manager.update(1.0s);
    }

    manager.finalize();
}
