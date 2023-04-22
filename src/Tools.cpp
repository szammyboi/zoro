#include "Tools.h"

// possibly have the file searcher be recursive with the wildcards
std::vector<std::string> ParseList(const std::vector<std::string>& list)
{
  std::vector<std::string> result;
  for (const std::string& item : list)
  {
    std::string folder, filename;
    std::cout << item << std::endl;
  }
  return result;
}
