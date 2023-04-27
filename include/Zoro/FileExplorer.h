#pragma once
#include <string>
#include <vector>

class FileExplorer {
public:
  FileExplorer(const FileExplorer&) = delete;
  static FileExplorer& Get() 
  { 
    static FileExplorer instance;
    return instance; 
  }

  static std::vector<std::string> FindFiles(const std::string& dir);
  static std::vector<std::string> FindFiles(const std::vector<std::string>& dirs);
 
  void FindFilesImpl(std::vector<std::string>& vec, const std::string& relPath, const std::string& absPath) const;
private:
  FileExplorer();
  std::string m_WorkingDirectory;
};
