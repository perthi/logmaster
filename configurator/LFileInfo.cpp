#include "LFileInfo.h"
#include <utilities/GString.h>
#include <utilities/GNumberTypes.h>
#include <filesystem>
#include <exception>
#include <format.h>
#include <regex>


namespace fs = std::filesystem;


namespace CONFIGURATOR
{
    LFileInfo::LFileInfo(const string filepath, const string classname)
    {
        SetPath(filepath);
        SetClassName(classname);
    }


    void
        LFileInfo::SetPath(const string path)
    {
        if ( fs::is_directory(path) == false )
        {
            throw(std::invalid_argument(fmt::format("Error accessing \"{}\". Not a valid directory", path)));
        }
        else
        {
            fFilePath = path;
        }

    }


    void
        LFileInfo::ValidateClassName(const string classname)
    {

        if ( fs::is_directory(classname) == true )
        {
            throw(std::invalid_argument( fmt::format("\"{}\". Is a directory", classname)));

        }

        vector<string> seps = { ",", ".", ":", ";", "\\", "/"};
        for ( auto& s : seps )
        {
            if ( g_string( )->Contains(classname, s) == true )
            {

                throw(std::invalid_argument( fmt::format("Invalid classname \"{}\". Must not contain suffix, or any special characters ", classname)));

            }
        }


        vector<string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
        if ( g_string( )->BeginsWith(classname, digits) == true )
        {
            throw(std::invalid_argument(fmt::format("Invalid classname \"{}\". Cannot start with a digit", classname)));
        }

        if ( g_number_types( )->IsAlphaNumber(classname) == false )
        {
            throw(std::invalid_argument(fmt::format("Invalid classname \"{}\". Must be a sequence of alphanumeric numbers (A-z, 0-9)", classname)));
        }
        /// If we got here without an exception then everything should be OK, (unless the user is really clever)
    }


    void
        LFileInfo::SetClassName(const string classname)
    {
        try {

            ValidateClassName(classname);
        }
        catch ( std::invalid_argument& e )
        {
           // CERR << e.what( ) << ENDL;
            throw(e);
        }
        catch ( ... )
        {
            CERR << "Unknown exception caught validating " << ENDL;
            throw(std::exception( ));
        }


        fClassName = classname;
        fHeaderFileName = fClassName + ".h";
        fSourceFileName = fClassName + ".cpp";
    }

    void
        LFileInfo::EnableSuffixes( )
    {

    }


    void  LFileInfo::DisableSuffixes( )
    {
        fHeaderFileName = fClassName;
        fSourceFileName = fClassName;
    }

}
