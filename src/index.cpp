#include "index.h"

std::vector<std::filesystem::path> FindFiles(const std::string &origin) {
  std::vector<std::filesystem::path> files;

  const std::filesystem::path base(origin);
  for (const auto &entry : std::filesystem::directory_iterator(base)) {
    const std::string ext = entry.path().extension();
    if (ext == ".cpp") {
      std::cout << entry.path() << std::endl;
    }
  }

  return files;
}
