#pragma once

#include <utilities/GDefinitions.h>
#include <string>
using std::string;

namespace CONFIGURATOR
{
    class LFileInfo
    {
    public:
        LFileInfo(const string filepath, const string classname, bool with_suffix = true);

        string  API GetPath( ) const { return fFilePath; };
        string  API GetClassName( ) const { return fClassName; };
        string  API GetSourceName( ) const { return fSourceFileName; };
        string  API GetHeaderName( ) const { return fHeaderFileName; };
        
        void  API SetPath( const string path);
        void  API SetClassName( const string classname );
        
        void    API EnableSuffixes( );
        void    API DisableSuffixes( );

    private:
        void   ValidateClassName( const string classname);
        string fFilePath = "";              //!< Full path to the location of .cpp or .h source files to be generated
        string fClassName = "";              //!< Name of the class
        string fSourceFileName = "";      //!< Name of the .cpp source file if applicable
        string fHeaderFileName = "";      //!< Name of the .h header file if applicable

    };

}

