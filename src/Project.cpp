#include <Zoro/Project.h>
#include <Zoro/FileExplorer.h>
#include <yaml-cpp/yaml.h>

namespace YAML {
Node convert<Project>::encode(const Project& rhs) {
    Node node;
    node.push_back(rhs.name);
    node.push_back(rhs.type);
    node.push_back(rhs.outputdir);
    node.push_back(rhs.cppversion);
    node.push_back(rhs.files);
    node.push_back(rhs.include);
    node.push_back(rhs.define);
    return node;
}

bool convert<Project>::decode(const Node& node, Project& rhs) {
    if(!node.IsDefined())
      return false;

    rhs.name = node["name"].as<std::string>(); 
    rhs.type = node["type"].as<std::string>();
    rhs.outputdir = node["outputdir"].as<std::string>();
    rhs.cppversion = node["cppversion"].as<int>(); 
    if (YAML::Node files = node["files"])
      rhs.files = FileExplorer::FindFiles(files.as<std::vector<std::string>>()); 
    if (YAML::Node include = node["include"]) 
      rhs.include = FileExplorer::FindFiles(include.as<std::vector<std::string>>());
    if (YAML::Node define = node["define"])
      rhs.define = define.as<std::vector<std::string>>();
    return true;
  }
}
