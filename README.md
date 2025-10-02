# Booster

This is an educational endeavor into learning a bit more about ECS using C++23. Some goals, which will absolutely change as I experiement and mess around with it all:

* Implement the n-body problem via both the direct sum solution as well as via the Barnes-Hut Approximation
    * I am pretty familiar with this simulation and figured this would be a good one to work on
* Incorporate events/signals for entity creation/deletion, component creation/deletion, etc.
* Incorporate concurrency?
* Who knows? I don't know anything about this stuff yet, so I don't know what I don't know yet.

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

Currently the `apps` directory contains a sample executable that just instantiates some entities and components and performance simple update. It will eventually include a complete loop and integrate with events and other signalling/dispatching.
