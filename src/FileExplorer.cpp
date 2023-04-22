#include "FileExplorer.h"
#include <iostream>

FileExplorer::FileExplorer() 
{
  m_WorkingDirectory = std::filesystem::current_path().string();
}

void FileExplorer::FindFilesImpl(const std::string& searchPath, std::vector<std::string>& files) const
{
  RecursiveSearch(files, searchPath, ""); 
}

// instead of removing from string keep track of index?
// reducing nesting by a ton
// possibly reduce string concatenations
void FileExplorer::RecursiveSearch(std::vector<std::string>& vec, const std::string& remainingPath, const std::string& currentPath) const
{
  // makes last else kinda redundant
  if (std::filesystem::exists(currentPath + remainingPath))
  {
    vec.push_back(currentPath + remainingPath);
    return;
  }
  size_t sectionEnd = remainingPath.find('/');
  if (sectionEnd != std::string::npos)
  {
    std::string section = remainingPath.substr(0, sectionEnd);
    if (section == "**")
    {
      for (const auto& dir : std::filesystem::directory_iterator(currentPath))
      {
        if (dir.is_directory())
          RecursiveSearch(vec, remainingPath.substr(sectionEnd + 1), currentPath + dir.path().filename().string() + '/');
      }
    } else
    {
      RecursiveSearch(vec, remainingPath.substr(sectionEnd + 1), currentPath + section + '/');
    }
  } else 
  {
    size_t extIndex = remainingPath.find('.');
    if (extIndex != std::string::npos) { 
      if (remainingPath.find("**") != std::string::npos)
      {
        std::string extension = remainingPath.substr(extIndex); 
        for (const auto& file : std::filesystem::directory_iterator(currentPath))
        { 
          if (file.path().extension() == extension)
            vec.push_back(currentPath + file.path().filename().string());
        }
      }
      else
      {
        // 2 string concatenations
        if (std::filesystem::exists(currentPath + remainingPath))
          vec.push_back(currentPath + remainingPath);
        else
          // error
          return;
      }
    } else {
      // error
    }
    // check for file ending first
  }
  
  /*std::string section = remainingPath.substr(0, remainingPath.find('/'));
  

  std::cout << section << std::endl;
  if (sectionEnd != std::string::npos)
    RecursiveSearch(vec, remainingPath.substr(sectionEnd + 1), currentPath + section + '/');
  else 
    vec.push_back(currentPath + section);
    */
}

/*
std::vector<std::string> FileExplorer::FindFilesImpl(const std::string& dir, const std::string& searchExt) const 
{
  filesystem::path searchPath(m_WorkingDirectory + "/" + dir);
  std::vector<std::string> files;

  for (const auto& entry : filesystem::directory_iterator(searchPath))
  {
    if (!entry.is_regular_file()) continue;
    const std::string entryExt = entry.path().extension();
    if (entryExt == searchExt) files.push_back(dir + "/" + entry.path().filename().string());
  }

  return files;
}
*/
