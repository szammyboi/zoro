#include "parsing.h"

/*
const auto projectData = toml::parse(project);
        const auto projectDetails = toml::find<toml::value>(projectData, "project");
*/

namespace zoro {
    workspace parse(const toml::value projectData)
    {
        workspace wks;
        auto workspaceData = toml::find<toml::value>(projectData, "workspace");
        wks.name = toml::find<std::string>(workspaceData, "name");
        return wks;
    }
};


bool contains(std::string s1, std::string s2)
{
    return s1.find(s2) != std::string::npos; 
}

std::string FindFile(std::string filename)
{
    size_t position = filename.find("**.");
    std::string prefix = "./" + filename.substr(0, position);
    std::string extension = filename.substr(position+2);

    if (position == std::string::npos)
        prefix = "./";
    fs::path startpath(prefix);

    if (fs::exists(startpath) && fs::is_directory(startpath))
    {
        for (const auto& entry : fs::recursive_directory_iterator(startpath))
        {

            std::string entryname = entry.path().filename().string();
           
            if (position != std::string::npos)
            {
                if (contains(entryname, extension))
                {
                    return fs::absolute(entry.path()).string();
                }
            } else
            {
                if (filename == entryname)
                {
                    
                    return fs::absolute(entry.path()).string();
                }
            }
            
        }
    }
    
    return "";
}

std::vector<std::string> FindFiles(std::string filename)
{
    std::vector<std::string> matches;

    size_t position = filename.find("**.");
    std::string prefix = "./" + filename.substr(0, position);
    std::string extension = filename.substr(position+2);

    if (position == std::string::npos)
        prefix = "./";
    fs::path startpath(prefix);

    if (fs::exists(startpath) && fs::is_directory(startpath))
    {
        for (const auto& entry : fs::recursive_directory_iterator(startpath))
        {
            std::string entryname = entry.path().filename().string();
            if (position != std::string::npos)
            {
                if (contains(entryname, extension))
                {
                    matches.push_back(fs::absolute(entry.path()).string());
                }
            } else
            {
                if (filename == entryname)
                {
                    matches.push_back(fs::absolute(entry.path()).string());
                }
            }
            
        }
    }

    return matches;
}

/*
 fs::path startpath("./");
    if (fs::exists(startpath) && fs::is_directory(startpath))
    {
        for (const auto& entry : fs::recursive_directory_iterator(startpath))
        {
            std::string filename = entry.path().filename().string();
            if (filename == filematch)
            {
                return fs::absolute(entry.path()).string();
            }
        }
    }
    return "";

    */