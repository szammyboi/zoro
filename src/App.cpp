#include <iostream>
#include "toml.hpp"
#include "Zoro.h"

enum class Command
{
    Add = 0,
    Run,
    Build,
    Config,
    Undefined
};

static const char *command_str[] =
  {"Add", "Run", "Build", "Any", "Undefined"};

void to_lower(std::string& data)
{
  std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
}


Command GetCommand(std::string str)
{
    to_lower(str);
    //std::string test = (Command)str;
    if (str == "add")
    {
        return Command::Add;
    }
    else if (str == "run")
    {
        return Command::Run;
    }
    else if (str == "build")
    {
      return Command::Build;
    }
    // check for config
    else
    {
        return Command::Undefined;
    }
}

int main(int argc, char *argv[])
{
    // default is build and run??
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

    std::string selectedCommand = command_str[(int)command];
    selectedCommand.append(" command selected");
    ZORO_INFO(selectedCommand);


    char * userpath = std::getenv("USERPROFILE");
    if (userpath != nullptr)
      std::cout << userpath << std::endl;
    else
      ZORO_ERROR("Could Not Find Userpath, Defaulting to Local Directory");

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
