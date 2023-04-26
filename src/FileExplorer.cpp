#include "FileExplorer.h"
#include <filesystem>

FileExplorer::FileExplorer()
  : m_WorkingDirectory(std::filesystem::current_path().string()) {}

std::vector<std::string> FileExplorer::FindFiles(const std::string& dir)
{
  const FileExplorer& instance = Get();
  std::vector<std::string> files;
  instance.FindFilesImpl(files, dir, "");
  return files;
}

std::vector<std::string> FileExplorer::FindFiles(const std::vector<std::string>& dirs)
{
  const FileExplorer& instance = Get();
  std::vector<std::string> files;
  for (const std::string& dir : dirs)
    instance.FindFilesImpl(files, dir, "");
  return files;
}

void FileExplorer::FindFilesImpl(std::vector<std::string>& vec, const std::string& remainingPath, const std::string& currentPath) const
{ 
  if (std::filesystem::exists(currentPath + remainingPath))
    return vec.push_back(currentPath + remainingPath);

  size_t sectionEnd = remainingPath.find('/');
  size_t extensionStart = remainingPath.find('.');
  bool folder = sectionEnd != std::string::npos;
  bool file = extensionStart != std::string::npos; 
  std::string section;
  
  if (!folder) 
    goto file;

  section = remainingPath.substr(0, sectionEnd);
  if (section != "**")
    return FindFilesImpl(vec, remainingPath.substr(sectionEnd + 1), currentPath + section + '/');
  for (const auto& dir : std::filesystem::directory_iterator(currentPath))
    if (dir.is_directory())
      return FindFilesImpl(vec, remainingPath.substr(sectionEnd + 1), currentPath + dir.path().filename().string() + '/');
  
file:
  if (!file || remainingPath.find("**") == std::string::npos) return;
  section = remainingPath.substr(extensionStart); 
  for (const auto& file : std::filesystem::directory_iterator(currentPath)) 
    if (file.path().extension() == section)
      vec.push_back(currentPath + file.path().filename().string());
}
