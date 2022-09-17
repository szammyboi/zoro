# Zoro: Killer C++ (WIP)


Zoro is an all-around tool for making, managing, and building C++ projects.

## Features

- Package Management
- Build System
- Code Execution




## Usage/Examples

Basic Zoro Config (Uses TOML)
```toml
## workspace.toml ##

[workspace]
name = "GraphicsTest"
architecture = "x86"
language = "C++"
configs = [
    "debug",
    "release"
]
```
```toml
## project.toml ##

[project]
name = "GraphicsApp"
type = "executable"

[build]
files = [
    "src/**.cpp",
    "src/**.h"
]
includes = [
    "vendor/GLFW/include"
]
links = [
    "GLFW"
]


[debug]
defines = ["DEBUG"]

[release]
defines = ["NDEBUG"]
optimize = true
```

Adding a Package:
```shell
zoro add GLFW GLAD
```

Building a Project:
```shell
zoro debug (or any defined config)
zoro build
```

Running a Project:
```shell
zoro run (selected config)
```


## Roadmap

- Everything lol



[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
