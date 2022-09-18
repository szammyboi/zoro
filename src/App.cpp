#include <iostream>
#include "toml.hpp"
#include "Zoro.h"

enum Command
{
    Add = 0,
    Run,
    Config,
    Undefined
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
    // check for config
    else
    {
        return Command::Undefined;
    }
}

int main(int argc, char *argv[])
{

    Zoro::Log::Init();

    #ifdef ZR_PLATFORM_WINDOWS
      ZORO_INFO("Windows Platform Detected!");
    #endif

    #ifdef ZR_PLATFORM_LINUX
      ZORO_INFO("Linux Platform Detected!");
    #endif

    Command command = Command::Run;
    if (argc > 1)
        command = GetCommand(argv[1]);
    if (command == Command::Undefined)
    {
      ZORO_FATAL("Invalid Command Given");
      return -1;
    }


    //UpdateStore();

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
