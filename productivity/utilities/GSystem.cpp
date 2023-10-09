// -*- mode: c++ -*-


/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> HTTP:///www.embc.no  ***
*** all rights reserved                                                    ***
***                                                                        ***
*** logmaster is free software: you can redistribute it and/or modify      ***
*** it under the terms of the Lesser GNU General Public License (LGPL)     ***
*** as published by the Free Software Foundation, either version 3 of the  ***
*** License, or (at your option) any later version.                        ***
***                                                                        ***
*** logmaster is distributed in the hope that it will be useful,           ***
*** but WITHOUT ANY WARRANTY; without even the implied warranty of         ***
*** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          ***
*** GNU General Public License for more details.                           ***
***                                                                        ***
*** You should have received a copy of the Lesser GNU General Public       ***
*** License along with logmaster in the README file in the source code     ***
*** directory. If not, see <http://www.gnu.org/licenses/>.                 ***
******************************************************************************
******************************************************************************/

#include "GSystem.h"
#include <sys/stat.h>
#include "GFileIOHandler.h"
#include "GTokenizer.h"
#include "GString.h"
#include "GCommon.h"
#include "GLocation.h"
//#include <logging/GException.h> 


#ifndef _WIN32
#include <dirent.h>
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#include <Shlwapi.h>
#include <windows.h>
#include <shellapi.h>
#pragma comment(lib, "shlwapi.lib")
#endif

#include <stdio.h>
#include <memory>

#include <cstdlib>
#include <filesystem>
#include <format>

#ifndef _WIN32
#include <libgen.h>
#endif // !_WIN32

//#include <ftw.h>
 #include <errno.h>



GSystem * g_system()
{
    static GSystem *instance = new GSystem();
    return instance;
}






/** @todo return std::optional here*/
string
GSystem::getenv(const string  var  )
{
#ifdef _WIN32
    size_t sz = 0;
    char  *tmp = nullptr;
    _dupenv_s(&tmp, &sz,  (char*)var.c_str());
#else
    char *tmp = std::getenv((char*)var.c_str());
#endif // _WIN32
    string ret = "";

    if( tmp != nullptr )
    {
        ret = string(tmp);
#ifdef _WIN32
        free(tmp);
#endif
        return ret;
    }
    else
    {
        return var + ": no such environment variable found";
    }

}



#ifdef _WIN32
string
GSystem::Errno2String(const  errno_t code, const string fname, const string  opt)
{
    static const size_t sz = 2048;
    char errmsg[sz] = {0};
    strerror_s(errmsg, sz, code);
    strcat_s(errmsg, 2048, fname.c_str());

    return string(errmsg);
}
#else
string
GSystem::Errno2String(const int code, const string fname, const string  opt)
{
    char* errmsg = strerror(code);;
    if (errmsg != nullptr)
    {
        return string(errmsg);
    }
    else
    {
        return "<no strerror message( fopen(fp, " + fname + "," + opt + ") >";
    }

}
#endif



/** mkdir =   Make Directory (that is a folder in Windows terms), Unix/bash style
*   @param    dirname The directory to create
*   @return   true if the directory exists, or if it doesn't already exists, but was
*   successfully created
*   @return false if the directory doesn't exist, and it also cannot be created (for instance if
*   the program is running under a user that doesn't have write access to the current directory)
*   @throw Exception if the directory doesn't exist and it cannot be created.*/
bool
GSystem::mkdir(const string dirname, const bool print_error)
{
#ifdef _WIN32
    int status = ::_mkdir(dirname.c_str() );
#else
    int status = ::mkdir(dirname.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH );
#endif // _WIN32

    if( status == 0)
    {
        return true;
    }
    else
    {
        string errmsg = Errno2String(errno, dirname, "");
       if( print_error == true)
       {
            GCommon().HandleError(  std::format(  "The directory \"{}\" could not be created ({}),.. please check that you have write + exec permissions to the directory", \
                                           dirname.c_str( ), errmsg.c_str() ), GLOCATION,  DISABLE_EXCEPTION  );  
       }

             return false;
    }
}

#include <string.h>


/**@{*/ 
/** mkdir =   Make Directory (that is a folder in Windows terms), Unix/bash style
*   @param    dirname The directory to create
*   @param    l The location  where this function was called from
*   @param    opt Access settings (typically 755)
*   @param    overwrite whether or not tor overwrite/replace existing directory of it already exists 
*   @return   true if the directory exists, or if it doesn't already exists, but was
*   successfully created
*   @return false if the directory doesn't exist, and it also cannot be created (for instance if
*   the program is running under a user that doesn't have write access to the currant directory)
*   @throw Exception if the directory doesn't exist and it cannot be created.*/
bool
#ifndef _WIN32
GSystem::mkdir(const string dirname, GLocation l, const int  opt, bool overwrite)
#else
GSystem::mkdir(const string dirname, GLocation l, const int opt, bool overwrite)
#endif // !_WIN32
{
    char err[1024]; /// @todo check for buffer size

#ifdef _WIN32
    int status = ::_mkdir(dirname.c_str() );
    strerror_s(err, 1024, errno);
#else
     int status = ::mkdir(dirname.c_str(),  opt );
      strerror_r(errno, err,  1024);

#endif // _WIN32

    switch (status)
    {
    /// abort if any of the below non recoverable errors are encountered
    case EACCES:       // Search permission denied
    case ELOOP:        // Loop in symbolic link
    case EMLINK:       // Link count too high
    case ENAMETOOLONG: // Filename too long
    case ENOENT:       // Not a path / empty string
    case ENOSPC:       // No space left on device
    case ENOTDIR:      // Path is not (or cannot be) a directory
    case EROFS:        // The parent directory is read only
          GCommon().HandleError(std::format("non recoverable error encountered creating directory {} ( errno {}; {} )",
                                         dirname,errno,err ),l);
        return false;
        break;
    case EEXIST:
        if (overwrite == true)
        {
            return true;
        }
        else
        {
            GCommon().HandleError(std::format("directory {} already exists and you are not allowed to overwrite it ( errno {}; {})",
                                             dirname,errno,err ),l);
            return false;
        }
        break;
    }
    return true;
}
/**@}*/


bool
GSystem::exists(const string filepath, struct  stat *sb_in)
{
    struct  stat sb;
    int ret = stat( filepath.c_str(), &sb );
    
    if ( ret != 0 )
    {
        //string err = Errno2String(errno, filepath, "");
        //GCommon( ).HandleError(err, GLOCATION, DISABLE_EXCEPTION);
    }
    else
    {
        if ( sb_in != nullptr )
        { 
            *sb_in = sb;
        }
    }

    return ret == 0 ? true :false;
}

/**@{
/*
 * Whether or not a path is a regular file or directory.
 * 
 * @param filepath
 * @param sb An optional stat struct if the user code wants to know more details
 * about the file. I could be that the file exists, but is a special file like
 * a socket or similar.
 * @return true if the path exists and is a regular file/directory.
 * false otherwise */
bool     
GSystem::isdirectory(const string filepath, struct  stat* sb_in)
{
    struct  stat sb;
    if ( exists(filepath, &sb) == true )
    {
        S_ISREG(sb)
    }
    

    return false;
    
}


// bool      
// GSystem::isfile(const string filepath, struct  stat* sb)
//{
//
//}


/**@} */


string
GSystem::GetDirectory(const string filepath)
{
    const char* filepathCp = filepath.c_str();
    const char* charPtr = filepathCp + filepath.length() - 1;
    if ((*charPtr == '/') || (*charPtr == '\\'))
    {
        --charPtr;
    }
    while ((charPtr > filepathCp) && (*charPtr != '/') && (*charPtr != '\\'))
    {
        --charPtr;
    }
    if (charPtr > filepathCp)
    {
        size_t returnLen = charPtr - filepathCp;
        return filepath.substr(0, returnLen);
    }
    return "";
}


string
GSystem::GetProcessID()
{
    std::stringstream buffer;
#ifdef _WIN32
    buffer << GetCurrentProcessId();
#else
    buffer << getpid();
#endif
    return buffer.str();
}



/** Executes a system command.
*   @param cmd The command to execute
*   @return  The output of the command, i.e what would have been written on the command line if the
*   the command was executed in a console. */
string
GSystem::exec(const char* cmd)
{

#ifdef _WIN32
    std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
#else
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
#endif

    if (!pipe)
    {
        return "ERROR";
    }

    char buffer[256];
    std::string result = "";

    while (!feof(pipe.get()))
    {
        if (fgets(buffer, 256, pipe.get()) != NULL)
        {
            result += buffer;
        }
    }

    return result;
}



#ifdef _WIN32
/** @return all the command line arguments as a single string*/
string
GSystem::GetCommandLineAll()
{
    return string(GetCommandLineA());
}
#endif


/** @return all the command line arguments, except the firs one (which is the name of the executable), as a single string*/
#ifdef _WIN32
string
GSystem::GetCommandLineArguments()
{
    string ret = "";
    string ret2 = "";

#ifdef _WIN32
#include "Windows.h"
    int argc;

    LPWSTR cmdline = GetCommandLineW();
    LPWSTR* argv = ::CommandLineToArgvW(cmdline, &argc);

    for (int n = 1; n < argc; n++)
    {
        ret += n > 1 ? " \"" : "\"";
        WideCharToMultiByte(CP_UTF8, 0, argv[n], (int)wcslen(argv[n]), &ret2[0], (int)ret2.size(), 0, 0);
        ret += ret2;
        ret += "\"";
    }

    return ret;
#else
    int pid = getpid();
    char fname[PATH_MAX];
    char cmdline[ARG_MAX];
    snprintf(fname, sizeof fname, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(fname, "r");
    fgets(cmdline, sizeof cmdline, fp);
    vector<string> tokens = g_tokenizer()->Tokenize(cmdline);

    for (size_t i = 1; i < tokens.size(); i++)
    {
        ret += tokens[i];
    }

    return ret;
#endif    
}
#endif


/** @return the current path, i.e the path of the current location */
char *
GSystem::GetExePath()
{
    const static size_t buflen = 2048;

#ifdef _WIN32 
    static char dir[buflen];
    GetModuleFileNameA(NULL, dir, buflen);
    return dir;
#else
    static char buff[buflen] = { 0 };

    for (size_t i = 0; i < buflen; i++)
    {
        buff[i] = 0;
    }

    if (readlink("/proc/self/exe", buff, buflen) > 0)
    {
        //just shutting up the compiler
    }

    return buff;
#endif

}


/**   @return The path relative to the current location for the current executable excluding  the name of the exec file  */
char *
GSystem::GetExeDir()
{
    #ifdef _WIN32
    //static char *buf;
    LPSTR buf;
    buf = GetExePath();
    PathRemoveFileSpecA(buf);
    return buf;
    #else

    static  char buf[ PATH_MAX ] = {0};
    
    auto ret = readlink("/proc/self/exe", buf, PATH_MAX);
    if(ret < 0 )
    {
        GCommon().HandleError( GText("Error retriveing exe path (%s)", strerror(errno) ).str(), GLOCATION, DISABLE_EXCEPTION );
    }
    else
    {
        dirname(buf);
    }
  
    return buf;
    #endif
}




/** @return the name of the current executable */
char *
GSystem::GetExeName()
{
    static string dir;
    static string name;
    string path = string(GetExePath());
    GTokenizer().StripPath(path, dir, name);
    return (char *)name.c_str();
    return 0;
}


string
GSystem::GetHostName()
{
#ifdef _WIN32
    static char hostname[1024];
    static unsigned long w = 1024;
    GetComputerNameA(hostname, &w);
    return string(hostname);
#else
    char hostname[1024];
    gethostname(hostname, 1024);
    return string(hostname);
#endif
}


/** pwd = Print Working Directory after the similar Unix/Linux command
*   @param print whether or not to print the name of the current directory to stdout
*   @return a string containing the absolute path to the current directory */
string
GSystem::pwd(const bool print)
{
    char current_path[FILENAME_MAX];

    if (!GetCurrentDir(current_path, sizeof(current_path)))
    {
        return "ERROR !!!! could not get directory";
    }
    if (print == true)
    {
        COUT << ": " << current_path << "\n";
    }

    return string(current_path);
}



/** ls  = list content of current directory (Unix/bash)
*  @param dir  The directory to list (default is current directory)
*  @return A vector of files matching the search pattern (default is that all files in "dir" are listed ). */
vector<string>
GSystem::ls(const string dir)
{
    vector<string> tmp;
#ifndef _WIN32
    DIR *dp;

    struct dirent *dirp;
    if ((dp = opendir(dir.c_str())) == 0)
    {
        return tmp;
    }
    while ((dirp = readdir(dp)) != 0)
    {
        tmp.push_back(string(dirp->d_name));
    }
    closedir(dp);
#endif
    return tmp;
}


void
GSystem::cp(string source, string dest)
{
    mkfile(dest);
    vector<string> content = g_file()->ReadAll(source);
    for (uint16_t i = 0; i < content.size(); i++)
    {
        g_file()->Append(dest, content[i].c_str());
        if (i < content.size() - 1)
        {
            g_file()->Append(dest, "\n");
        }
    }
}


bool
GSystem::mkfile(const string filepath,const bool print_error )
{
    string dir, file;
    GTokenizer().StripPath(filepath, dir, file, false);

    if (dir != "")
    {
        mkdir(dir, print_error );
    }
    
    FILE *fp = g_file()->OpenFile( filepath, "r", GLOCATION, false );

    if (fp !=  nullptr)
    {
        if(print_error == true )
        {
          GCommon().HandleError( std::format("File \"{}\" already exists, will not be recreated", filepath), GLOCATION, DISABLE_EXCEPTION ) ;
        }
        fclose(fp);
       // return false;
        return  true;
    }
    else
    {
        fp = g_file()->OpenFile(filepath, "w", GLOCATION);

        if (fp !=  nullptr)
        {
            fclose(fp);
            return true;
        }
        else
        {
            if(print_error == true )
            {
              GCommon().HandleError(  std::format(  "Could not create file \"{}\" Please check your write permissions for this directory", \
                                               filepath), GLOCATION,  DISABLE_EXCEPTION  );
            }
            
            return false;      
        }
    }
    return true;
}


bool
GSystem::rmdir(const string filename)
{
    return rm(filename, true);
}


bool
GSystem::rm(const string filename, bool recursive)
{

    auto errorhandling = [=](GLocation l, errno_t err, const char *exception_msg) 
    {
        GCommon().HandleError( std::format("could not remove file:{}:  {}", filename, exception_msg), l, DISABLE_EXCEPTION);

        if(err !=0)
        {
           GCommon().HandleError(Errno2String(errno, filename, ""),l, DISABLE_EXCEPTION);
        }
        return false;
    };
 
    try
    {
        if (recursive == false)
        {
            auto ret = std::filesystem::remove(filename.c_str());
            if (ret == false)
            {
                errorhandling(GLOCATION, errno,
                    std::format("removal of file {} resulted in an error", filename ).c_str() ); /// "todo simplify
            }

            return ret;
        }
        else
        {
            std::filesystem::remove_all(filename.c_str());
        }
    }
    catch (std::exception& e)
    {   
        errorhandling(GLOCATION, errno, e.what());
        return false;
    }
    catch (...)
    {
        errorhandling(GLOCATION, errno, "unknown exception");
        return false;
    }


    return true;

}



void
GSystem::mv(const string src, const string dest)
{
    cp(src, dest);
    rm(src);
}


/** @return Returns the name of rootdir */
#ifdef _WIN32
char*
GSystem::GetHomeDir()
{
    static char* buf;
    buf = GetExePath();
    PathRemoveFileSpecA(buf);
    string path = string(buf);
    static string dir;
    static string fout;
    GTokenizer().StripPath(path, dir, fout);
    static string homedir = fout + "\\..\\..\\";
    return  (char*)homedir.c_str();
    // inline  void API StripPath(const string fin, string &dir, string &fout, const bool keep_trailing_slash = KEEP_TRAILING_SEPARATOR );     
    SPRINTF(buf, 1024, "%s\\..\\..\\", buf); // CRAP PTH
    return buf;
}
#endif
