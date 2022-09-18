#include "DataStore.h"
#include "PlatformDetection.h"

namespace fs = std::filesystem;

#if defined(ZR_PLATFORM_WINDOWS)
    #define HOME_DIR "USERPROFILE"
#elif defined(ZR_PLATFORM_LINUX)
    #define HOME_DIR "HOME"
#else
    #define HOME_DIR ""
#endif

void UpdateStore()
{
    fs::path userpath;
    std::string user_string = getenv(HOME_DIR);
    if (user_string == "") {
        ZORO_ERROR("Could Not Find Userpath, Defaulting to Local Directory");
        user_string = "./";
      }
    
    userpath = user_string;
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