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
require 'zoro'

workspace "szammyboi"
    architecture "x64"
    location "build"
    configurations {
        "debug",
        "release"
    }
    startproject "zoro"

project "zoro"
    kind "ConsoleApp"
    location "build"
    files {
        "src/**.cxx",
        "src/**.h"
    }

    includedirs {
        "vendor/toml11"
    }

    filter "configurations:release"
        optimize "On"
