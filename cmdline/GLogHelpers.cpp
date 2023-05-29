#include "GLogHelpers.h"

#include <logging/LLogApi.h>
#include <logging/GException.h>

using namespace LOGMASTER;

#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>




string cmdlineFromFile(const string filename)
{

    G_DEBUG("Attempting to read configuration from file \"%s\"", filename.c_str( ));
    string fname_local_content = g_file( )->ReadFirstLine(filename);

    string content;

    if ( fname_local_content != "" )
    {
        G_INFO("The file \"%s\" was found. The content of first line is: %s", filename.c_str( ), fname_local_content.c_str( ));
    }

    string fname_full = g_system( )->GetExeDir( ) + filename;

    G_DEBUG("Attempting to read configuration from file: \"%s\"", fname_full.c_str( ));
    string fname_full_content = g_file( )->ReadFirstLine(fname_full);


    if ( fname_full_content != "" )
    {
        G_INFO("The file \"%s\" was found. The content of first line is: %s", fname_full.c_str( ), fname_full_content.c_str( ));
    }


    if ( fname_local_content == "" && fname_full_content == "" )
    {
        G_ERROR("failed to find file with name \"%s\" \n searched the following directories\n %s \n %s", filename.c_str( ), g_system( )->pwd( ).c_str( ), g_system( )->GetExeDir( ));
    }


    if ( (fname_local_content != "" && fname_full_content != "") && (fname_local_content != fname_full_content) )
    {
        INVALID_ARGUMENT_EXCEPTION("conflicting config files. You have two config files in both the current directory \
        and the exe directory with the same name, but different content ( \"%s\"  vs  \"%s\" ), please delete one of them",
                                   filename.c_str( ), fname_full.c_str( ));
    }
    else
    {
        if ( fname_local_content == "" && fname_full_content == "" )
        {
            INVALID_ARGUMENT_EXCEPTION("Unable to scan arguments from either  \"%s\"   or \"%s\": Either the file does not exist, or it is empty",
                                       filename.c_str( ), fname_full.c_str( ));
        }
        else
        {

#ifdef _WIN32
            string cmd = g_system( )->GetCommandLineArguments( );
#endif

            string f_content;
            string f_name;

            if ( fname_local_content != "" )
            {
                f_content = fname_local_content;
                f_name = filename;
            }
            else
            {
                f_content = fname_full_content;
                f_name = fname_full;
            }

#ifdef _WIN32
            content = f_content + " " + cmd;
#else
            content = f_content;
#endif
            G_INFO("Init done...");
        }

    }
    return content;

}

