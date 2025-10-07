#pragma once

#include <nlohmann/json.hpp>

#include "booster/ecs/component/team.hpp"

namespace booster::component
{
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Team, name);
}
