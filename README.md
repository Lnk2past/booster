# Booster

This is an educational endeavor into learning a bit more about ECS using C++20/23. Some goals, which will absolutely change as I experiement and mess around with it all:

TODO

<center><img src="booster.png" width="120"></center>

## Development

Devcontainer provided; just launch a Codespace or local devcontainer!

### Build

This project uses Conan + CMake for dependency management and builds. You will need to install dependencies via Conan and then build via CMake (there are VSCode build tasks for these!):

```shell
# install dependencies
conan install . --build=missing

# load preset
cmake --preset conan-release

# build code
cmake --build --preset conan-release
```

## Examples
