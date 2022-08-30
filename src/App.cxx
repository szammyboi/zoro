#include <iostream>
#include <toml.hpp>
#include "parsing.h"

int main()
{
    std::string projectFile = FindFile("project.toml");
    //std::cout << projectFiles[0] << std::endl;
    const auto projectData = toml::parse(projectFile);
    
    auto wks = zoro::parse(projectData);
    std::cout << wks.name << std::endl;

    return 0;
}