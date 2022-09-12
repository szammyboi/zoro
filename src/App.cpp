#include <iostream>
#include "toml.hpp"
#include "Zoro.h"

enum Command
{
    Add = 0,
    Run,
    Config
};

Command GetCommand(std::string str)
{
    if (str == "add")
    {
        return Command::Add;
    }
    else if (str == "run")
    {
        return Command::Run;
    }
    else
    {
        return Command::Config;
    }
}

int main(int argc, char *argv[])
{

    Zoro::Log::Init();

#ifdef ZR_PLATFORM_WINDOWS
    ZORO_INFO("Windows Platform Detected!");
#endif

    if (argc > 0)
        ZORO_INFO(GetCommand(argv[1]));

    UpdateStore();

    /*
    std::string projectFile = FindFile("project.toml");
    //std::cout << projectFiles[0] << std::endl;
    const auto projectData = toml::parse(projectFile);

    auto wks = zoro::parse(projectData);
    std::cout << wks.name << std::endl;
    std::cout << (int)wks.architecture << std::endl;
    */

    ZORO_DEBUG("DEBUG MODE ACTIVE");

    // spdlog::debug("DEBUG MODE ACTIVATED");
    return 0;
}