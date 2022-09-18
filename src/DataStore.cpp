#include "DataStore.h"
#include "PlatformDetection.h"

namespace fs = std::filesystem;

void UpdateStore()
{
    fs::path userpath;
    
    #ifdef ZR_PLATFORM_WINDOWS
      std::string user_string = getenv("USERPROFILE");
      if (user_string == "") {
        ZORO_ERROR("Could Not Find Userpath, Defaulting to Local Directory");
        user_string = "./";
      }
      userpath = user_string;
    #endif

    #ifdef ZR_PLATFORM_LINUX
        userpath = "~/";
    #endif

    std::cout << userpath.string() << std::endl;



    /*
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

    */
}