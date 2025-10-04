from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake

class booster(ConanFile):
    name = "booster"
    version = "0.0.1"
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'CMakeToolchain', 'CMakeDeps'

    def configure(self):
        self.options["spdlog"].use_std_fmt = True

    def requirements(self):
        self.requires("entt/3.15.0")
        self.requires("mp-units/2.4.0")
        self.requires("nlohmann_json/3.12.0")
        self.requires("spdlog/1.15.3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)
