#include "DataStore.h"

namespace fs = std::filesystem;

void UpdateStore()
{
    std::string userpath = getenv("USERPROFILE");
    std::cout << userpath << std::endl;
    fs::path store(userpath + "\\.zoro");
    if (fs::exists(store) && fs::is_directory(store))
    {
        std::cout << "FOUND FILE" << std::endl;
    } else {
        ZORO_INFO("No Previous Zoro Installation Found");
        ZORO_INFO("Beginning Initial Setup...");
        std::cout << "CREATING FOLDER" << std::endl;
        fs::create_directory(store);
    }
    
    std::cout << fs::absolute(store) << std::endl;
}