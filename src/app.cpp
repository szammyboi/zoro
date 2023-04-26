#include "Project.h"
#include <iostream>

int main() 
{
  YAML::Node config = YAML::LoadFile("project.yaml");
  Project proj = config["project"].as<Project>();  
  for (const auto& file : proj.files)
    std::cout << file << std::endl;
  return 0;
}
