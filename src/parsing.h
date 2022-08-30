#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <toml.hpp>
#include "structures.h"


namespace fs = std::filesystem;
namespace zoro {
    workspace parse(const toml::value);
}

std::string FindFile(std::string filename);
std::vector<std::string> FindFiles(std::string filename);