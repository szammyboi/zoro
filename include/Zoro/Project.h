#pragma once
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

struct Project
{
  std::string name;
  std::string type;
  std::string outputdir;
  int cppversion = 17; 
  std::vector<std::string> files;
  std::vector<std::string> include;
  std::vector<std::string> define; 
};

namespace YAML {
  template<>
  struct convert<Project> {
    static Node encode(const Project& rhs); 
    static bool decode(const Node& node, Project& rhs);
  };
}

