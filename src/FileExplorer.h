#include <filesystem>
#include <vector>

namespace filesystem = std::filesystem;

// Add support for absolute paths
class FileExplorer {
public:
  FileExplorer(const FileExplorer&) = delete;
  static FileExplorer& Get() 
  { 
    static FileExplorer instance;
    return instance; 
  }

  static std::vector<std::string> FindFiles(const std::string& dir)
  {
    const FileExplorer& instance = Get();
    std::vector<std::string> files;
    instance.FindFilesImpl(dir, files);
    return files;
  }

  static std::vector<std::string> FindFiles(const std::vector<std::string>& dirs)
  {
    const FileExplorer& instance = Get();
    std::vector<std::string> files;
    for (const std::string& dir : dirs)
      instance.FindFilesImpl(dir, files);
    return files;
  }

  void FindFilesImpl(const std::string& dir, std::vector<std::string>& files) const;
  void RecursiveSearch(std::vector<std::string>& vec, const std::string& relPath, const std::string& absPath) const;
private:
  FileExplorer();
  std::string m_WorkingDirectory;
};
