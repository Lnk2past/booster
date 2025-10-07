#include "booster/ecs/manager.hpp"
#include "booster/ecs/prefab/entity.hpp"
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

    for (auto &system : config.at("systems"))
    {
        auto fn = booster::system::Registry::instance()[system];
        manager.systems.push_back(fn);
    }

    for (const auto &spec : config.at("entities"))
    {
        const auto count = spec.at("count").get<std::uint32_t>();
        const auto entities = booster::prefab::create_entities(manager.registry, count);
        for (const auto &prefab : spec.at("prefabs").items())
        {
            auto fn = booster::prefab::Registry::instance()[prefab.key()];
            fn(manager.registry, entities, prefab.value());
        }
    }

    using namespace std::chrono_literals;
    for (auto i = 0; i < 10; ++i)
    {
        manager.update(1.0s);
    }

    manager.finalize();
}
