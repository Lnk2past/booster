#pragma once

#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace booster
{
template <typename F> class FunctionRegistry
{
  public:
    using Fn = std::function<F>;

    static auto instance() -> FunctionRegistry &
    {
        static auto reg = FunctionRegistry{};
        return reg;
    }

    auto register_function(const std::string &name, Fn fn) -> void
    {
        functions[name] = std::move(fn);
    }

    auto operator[](const std::string &name) -> Fn
    {
        if (auto it = functions.find(name); it != functions.end())
        {
            return it->second;
        }
        throw std::runtime_error("Unknown function: " + name);
    }

    struct Registrar
    {
        Registrar(const std::string &name, FunctionRegistry::Fn fn)
        {
            FunctionRegistry::instance().register_function(name, std::move(fn));
        }
    };

  private:
    std::unordered_map<std::string, Fn> functions;
};
} // namespace booster
