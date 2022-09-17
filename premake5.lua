--[[
    
    Todos:
        - startproject not required
        - adaptability on location and target dirs
        - filters for configs
        - POST BUILD COMMANDS IN ZORO
        - ^ that would be such a dub
        - & remove post build from ninja
        - giving no command lists the executable and config
        - generate vs code config
        - ~./zoro folder to store configs and hide related build files so there
        - can just be a bin folder from the user perspective
]]

require "ninja"

workspace "szammyboi"
    architecture "x64"
    location "build"
    language "C++"
    cppdialect "C++20"
    configurations {
        "debug",
        "release"
    }
    startproject "zoro"

project "zoro"
    kind "ConsoleApp"
    location "build"

    targetdir "build/%{prj.name}/bin/%{cfg.buildcfg}"
    objdir "build/%{prj.name}/obj/%{cfg.buildcfg}"

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "vendor/toml11",
        "vendor/spdlog/include"
    }

    filter "configurations:release"
        optimize "On"
        defines {
            "NDEBUG"
        }

    filter "configurations:debug"
        defines {
            "DEBUG"
        }

    libdirs {
        "build/spdlog/bin/%{cfg.buildcfg}"
    }

    links {
        "spdlog"
    }


project "spdlog"
    kind "StaticLib"
    location "build"
    language "C++"

    targetdir "build/%{prj.name}/bin/%{cfg.buildcfg}"
    objdir "build/%{prj.name}/obj/%{cfg.buildcfg}"

    files {
        "vendor/spdlog/src/**.cpp",
        "vendor/spdlog/include/**.h"
    }

    includedirs {
        "vendor/spdlog/include"
    }

    defines {
        "SPDLOG_COMPILED_LIB"
    }

