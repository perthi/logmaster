
#include "LFileInfo.h"
#include <filesystem>
#include <exception>
#include <format>

namespace fs = std::filesystem;
using  std::format;

namespace CONFIGURATOR
{
    LFileInfo::LFileInfo(const string filepath, const string classname, bool with_suffix)
    {
        SetPath(filepath);
        fClassName = classname;
    }


    void
        LFileInfo::SetPath( const string path)
    {
        if ( fs::is_directory(path) == false )
        {
            throw(std::invalid_argument(format("Error accessing {}. Not a valid directory", path)));
        }
        else
        {
            fFilePath = path;
        }

    }

    void
        LFileInfo::SetClassName(const string classname )
    {
       
    }

    void   
        LFileInfo::EnableSuffixes( )
    {
    
    }
    

    void  LFileInfo::DisableSuffixes( )
    {
    
    }

}
