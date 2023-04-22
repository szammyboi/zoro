#include "FileExplorer.h"
#include <iostream>

#include <yaml-cpp/yaml.h>

std::ostream& PrintVector(std::ostream& os, const std::vector<std::string>& vec)
{
  for (const std::string& str : vec)
    os << str << std::endl;
  return os;
}

// override print
struct Project
{
  std::string name;
  std::string language;
  int cppdialect;
  std::vector<std::string> files;
  std::vector<std::string> include;
  std::vector<std::string> define;

  friend std::ostream& operator<<(std::ostream&, const Project&);
};

std::ostream& operator<<(std::ostream& os, const Project& project)
{
  os << project.name << std::endl;
  os << project.language << std::endl;
  os << project.cppdialect << std::endl;
  PrintVector(os, project.files);
  PrintVector(os, project.include);
  PrintVector(os, project.define);
  return os;
}

// need to implement defaults and optionality
namespace YAML {
  template<>
  struct convert<Project> {
    static Node encode(const Project& rhs) {
      Node node;
      node.push_back(rhs.name);
      node.push_back(rhs.language);
      node.push_back(rhs.cppdialect);
      node.push_back(rhs.files);
      node.push_back(rhs.include);
      node.push_back(rhs.define);
      return node;
    }

    // struct size instead of 1
    static bool decode(const Node& node, Project& rhs) {
      if(!node.IsDefined() || node.size() > sizeof(Project))
        return false;

      rhs.name = node["name"].as<std::string>();
      rhs.language = node["language"].as<std::string>();
      rhs.cppdialect = node["cppdialect"].as<int>();
      rhs.files = FileExplorer::FindFiles(node["files"].as<std::vector<std::string>>());
      rhs.include = FileExplorer::FindFiles(node["include"].as<std::vector<std::string>>());
      rhs.define = node["define"].as<std::vector<std::string>>();
      return true;
    }
  };
}

int main() 
{
  YAML::Node config = YAML::LoadFile("project.yaml");
  Project proj = config["project"].as<Project>();
  std::cout << proj << std::endl; 
  return 0;
}
