from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake

class booster(ConanFile):
    name = "booster"
    version = "0.0.1"
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'CMakeToolchain', 'CMakeDeps'

    def requirements(self):
        self.requires("fmt/12.0.0")
        self.requires("nlohmann_json/3.12.0")
        self.requires("entt/3.15.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)
