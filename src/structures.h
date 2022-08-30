#pragma once
#include <string>
#include <vector>

namespace attr {
    enum class architecture {
        x86 = 0
    };

    enum class language {
        CPP,
        C
    };
}

class workspace {
public:
    std::string name;
    attr::architecture architecture;
    std::vector<std::string> configurations;
};

class project {
public:
    std::string name;
    attr::language language;
    std::vector<std::string> files;
    std::vector<std::string> includes;
    std::vector<std::string> prebuild;
    std::vector<std::string> postbuild;
};

class filter {
public:
    std::string name;
    bool optimize;
    std::vector<std::string> defines;
};