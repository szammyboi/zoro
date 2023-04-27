#include <Zoro/Ninja.h>
#include <iostream>

int main() 
{
  YAML::Node config = YAML::LoadFile("project.yaml");
  Project proj = config["project"].as<Project>();  
  WriteToNinja(proj);
  return 0;
}
