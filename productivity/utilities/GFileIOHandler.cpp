// -*- mode: c++ -*-


/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no>  http:///www.embc.no ***
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

#ifdef _WIN32
#pragma once
#endif

#include "GFileIOHandler.h"
#include "GUtilities.h"
#include "GSystem.h"
#include "GTokenizer.h"
#include "GCommon.h"
#include <fstream>
#include <sys/stat.h>
#include <stdio.h>



#ifdef _WIN32
#include <Shlwapi.h>
#include <Windows.h>
#pragma comment(lib, "shlwapi.lib")
#undef CreateFile
#endif

using std::ifstream;
#include <cstdarg>
#include <algorithm>
#include <fmt/format.h>

GFileIOHandler* g_file()
{
    static GFileIOHandler* instance = new GFileIOHandler();
    return instance;
}



/** Append an input to the file if it exists, otherwise create it first, then writhe the append to the file
 * @param  fname The file to write to
 * @param  fmt Format string for the input
 * @param ...  Variable GArgument list
 * The input is on the same format as when using printf/sprintf/fprintf
 * @return true if the input string was successfully written to the file, false otherwise */
bool
GFileIOHandler::Append(const string fname, const char* fmt, ...)
{
    if (fname == "")
    {
        CERR << "filename is empty, aborting" << endl;
        return false;
    }

    try
    {
        if (CheckFile(fname, "a"))
        {
            FILE* fp = OpenFile(fname, "a", GLOCATION);

            if (fp == nullptr)
            {
                throw(std::runtime_error(fmt::format("failed to open file {}", fname)));
            }

            va_list ap;
            va_start(ap, fmt);
            static char txt[65536];
            vsnprintf(txt, sizeof(txt) - 1, fmt, ap);
            fprintf(fp, "%s", txt);
            fclose(fp);
            va_end(ap);
            //FORCE_DEBUG("returning true");
            return true;
        }
        else
        {
            CERR << "filename = " << fname << endl;
            //EXCEPTION("fopen(%s, %c) failed, please check that the file exists, and that you have write permissions to it", fname.c_str(), 'a');
            throw(std::runtime_error(fmt::format("fopen({}, {}) failed, please check that the file exists, and that you have write permissions to it", fname, 'a')));
        }
    }
    catch (std::exception& e)
    {
        CERR << "Exception caught appending to file, message:" << e.what() << ENDL;
        return false;
    }
}



bool
GFileIOHandler::DoExists(const string fname, const char* opt)
{
    return CheckFile(fname, opt);
}

/** Read the last line of the file.
 *  @param[in] fname The file to read from
 *  @param[in] offset The line number, counting from the end, of the line to return. For example offset = 1 return the second last line, offset = 2 the third last etc.
 *  The default is zero which means that the last line is returned.
 *  @return The last line if offset is zero, or the line at "offset" lines from the end. If offset is larger than the number of lines in the file, then the first line is returned.
 *  Also an error message is written to the logging system in this case. If the file does not exist then an empty string is returned, and a message written to the logging system
 *  @exception GException offset must be between zero and the array size. If the offset value is negative, then an exception is thrown  */
string
GFileIOHandler::ReadLastLine(const string fname, const unsigned int offset)
{
    string lastline;

    if (CheckFile(fname) == false)
    {
        GCommon().HandleError(fmt::format("Cannot open file: {}", fname), GLOCATION, DISABLE_EXCEPTION);
        return "";
    }

    vector<string> content = ReadAll(fname);

    if (CheckFile(fname) == false)
    {
        GCommon().HandleError(fmt::format("Cannot open file: {}", fname), GLOCATION, DISABLE_EXCEPTION);
        return "";
    }
    if (content.size() == 0)
    {
        GCommon().HandleError(fmt::format("The file \"{}\" is empty", fname), GLOCATION, DISABLE_EXCEPTION);
        return "";
    }
    else
    {
#ifdef _WIN32
#pragma warning(suppress: 4018) // in this instance we need to allow comparison between signed and unsigned
#endif
        if (offset > content.size())
        {
            GCommon().HandleError(fmt::format("Invalid array subscript, offset = {} lines from the end of the file, \
                                                but there are only {} lines in the file", offset, content.size()), GLOCATION, DISABLE_EXCEPTION);


            return content.at(0);
        }
        else
        {
            return  content.at(content.size() - 1 - offset);
        }
    }
}



/** Convert the filename to absolute file path. Can also be used to clean up messy file path containing ..
 *  @param[in] fname The filename to convert to absolute file path
 *  @return The absolute file path of fname. */
#ifdef _WIN32
string
GFileIOHandler::GetAbsolutePath(const string fname)
{
    string absolutePath;
    char path[PATH_MAXLENGTH];
    absolutePath = _fullpath(path, fname.c_str(), PATH_MAXLENGTH);
    return(absolutePath);
}

#else

string
GFileIOHandler::GetAbsolutePath(const string)
{
    return "error_not_implement_om_linux_yet";
}
#endif




/** Get the extension of a filename
*  @param[in] fname The filename
*  @return The extension part of fname, excluding the dot, in lowercase. */
string
#ifdef _WIN32 
GFileIOHandler::GetExtention(const string fname)
#else
GFileIOHandler::GetExtention(const string)
#endif
{
#ifdef _WIN32  
    char path[PATH_MAXLENGTH];
    ::strcpy_s(path, PATH_MAXLENGTH, fname.c_str());
    const char* extentionSz = PathFindExtensionA(path);
    int offset = *extentionSz == '.' ? 1 : 0;
    string extention = extentionSz + offset;
    std::transform(extention.begin(), extention.end(), extention.begin(), ::tolower);
    return(extention);
#else
    return ""; // on Linux there are no extensions for exefile as the exe permission is set as a file attribute
#endif
}




FILE*
GFileIOHandler::OpenFile(const string fname, const string opt, const GLocation l, const bool print_error)
{

    FILE* fp = nullptr;

#ifdef _WIN32
    fopen_s(&fp, fname.c_str(), opt.c_str());
#else
    fp = fopen(fname.c_str(), opt.c_str());
#endif

    if (fp == nullptr)
    {
        if (print_error == true)
        {
            string errmsg = g_system()->Errno2String(errno, fname, opt);
            GCommon().HandleError(fmt::format("fopen({}, {}) failed: {}", fname, opt, errmsg), l, DISABLE_EXCEPTION);
        }
    }

    return fp;
}



/**  Checks if a file can be safely written, read, or appended to
 *   @param fname The full path + filename to the file to be written
 *   @param opt The access option which must be either w, w+, r, r+, a, a+
 *   @return false: if
 *   1) an existing file is attempted opened with the w or w+ option
 *   2) The file does not exist and cannot be
 *   opened with the w, w+ option.
 *   3) The file exists and cannot be opened with the a, a+, r, r+ option.
 *   4) if the option parameter is invalid
 *
 *   @return true: If 1) the file does not exists and can be successfully opened with the w or w+ option.
 *                    2) the file exists and can be successfully opened with the a, a+, r, r+ options */
bool
GFileIOHandler::CheckFile(const string fname, const string opt)
{
    if (opt.size() > 2)
    {
        GCommon().HandleError( fmt::format("Too many option flags {}, expected at most 2. opt = {}", fname, opt), GLOCATION, DISABLE_EXCEPTION);
    }

    if (!(opt == "w" || opt == "w+" || opt == "a" || opt == "a+" || opt == "r" || opt == "r+"))
    {
        GCommon().HandleError( fmt::format("Invalid option {}", opt), GLOCATION, DISABLE_EXCEPTION);
        return false;
    }
    else
    {
        FILE* fp = OpenFile(fname, "r", GLOCATION);

        if (fp != nullptr)
        {
            //     bool ret = false;
            if (opt == "w" || opt == "w+")
            {
                GCommon().HandleError( fmt::format("The file {} exists, opening it with the {} option will discard existing content",fname, opt), GLOCATION, DISABLE_EXCEPTION);
                fclose(fp);
                return  false;
            }
            else if (opt == "a" || opt == "a+" || opt == "r" || opt == "r+")
            {
                fclose(fp);
                fp = OpenFile(fname, opt, GLOCATION);

                if (fp == nullptr)
                {

                    return false;
                }
                else
                {
                    fclose(fp);
                    return true;
                }
            }

            fclose(fp);
        }
        else
        {
            GCommon().HandleError( fmt::format("Opening file: {}  opt = {}", fname, opt), GLOCATION, DISABLE_EXCEPTION);
            fp = OpenFile(fname, opt, GLOCATION);
            if (fp == nullptr)
            {
                return false;
            }
            else
            {
                fclose(fp);
                remove(fname.c_str());
                return true;
            }
        }
    }
    return false;
}



#ifdef _WIN32
inline void
GFileIOHandler::SetAttribute(const string fname, unsigned long attr)
{
    DWORD old_attr = GetFileAttributesA(fname.c_str());
    // If error, The file does not exists - Can't change attribute
    if (old_attr == ((DWORD)-1))
    {
        return;
    }
    DWORD new_attr = old_attr | attr;
    int ret = SetFileAttributesA(fname.c_str(), new_attr);

    if (ret != 1)
    {
        CERR << "could not set attribute !!" << ENDL;
    }
}
#endif


string
GFileIOHandler::ReadFirstLine(const string fname)
{
    string firstline;
    vector<string> content = ReadAll(fname);
    if (content.size() == 0)
    {
        return "";
    }
    else
    {
        return  content.at(0);
    }
}


bool
GFileIOHandler::Recreate(const string fname)
{
    g_system()->rm(fname);
    return g_system()->mkfile(fname);
}



#ifdef _WIN32
void
GFileIOHandler::ClearAttribute(const string fname, unsigned long attr)
{
    DWORD old_attr = GetFileAttributesA(fname.c_str());
    // If error, The file does not exists - Can't change attribute
    if (old_attr == ((DWORD)-1))
    {
        return;
    }
    DWORD new_attr = old_attr & ~attr;
    int ret = SetFileAttributesA(fname.c_str(), new_attr);

    if (ret != 1)
    {
        CERR << "could not set attribute !!" << ENDL;
    }
}
#endif

bool
GFileIOHandler::CreateFileLocal(const string fname, const bool print_error)
{

    return g_system()->mkfile(fname, print_error );
}


/** Read the content of a file into a vector
*  @param fname  The file to read
*  @param[in,out] status: whether or not the file was successfully read. ZERO = OK, ONE = NOT_OK
*  @return A vector of data, with on element for each line in the file */
vector<string>
GFileIOHandler::ReadAll(const string fname, bool* status)
{
    static std::mutex tmp_mutex;
    std::lock_guard<std::mutex> guard(tmp_mutex);
    static int cnt = 0;
    cnt++;

    vector<string> ret;
    std::ifstream fin;
    string line;

    bool l_status = true;

    fin.open(fname);
    if (!fin.good())
    {
        //CERR << fname << "  IS NOT GOOD" << ENDL;
        l_status = false;
        GCommon().HandleError(fname + ": " + string(strerror(errno)), GLOCATION, true);

    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, line);
            ret.push_back(line);
        }
    }

    if (status != nullptr)
    {
        *status = l_status;
    }

    return  ret;
}



bool 
GFileIOHandler::Delete(const string fname)
{
    FILE* fp = OpenFile(fname, "r", GLOCATION);

    if (fp == nullptr)
    {
//        GCommon().HandleError(GText("could not remove file: \"%s\"", fname.c_str()).str(), GLOCATION, true);
        return false;
    }
    else
    {
        fclose(fp);
        int ret = std::remove(fname.c_str());

        if (ret != 0)
        {
  //          string errmsg = Errno2String(errno, fname, "r");
    //        GCommon().HandleError(GText("could not remove file: \"%s\"", errmsg.c_str()).str(), GLOCATION, true);
            return false;
        }

    }

    return true;
}


/** @todo move somewhere else */
string
GFileIOHandler::ReadConfigFile(int argc, const char** argv, const string path)
{

    vector<string> tokens = GTokenizer().Tokenize(string(argv[0]), ".");
    string fname = "";
    string dir = "";

    GTokenizer().StripPath(tokens.at(0), dir, fname, false);

    if (tokens.size() > 0)
    {
        fname = path + "/" + fname + ".cfg";
    }

    if (  DoExists( fname ) == false )
    {
        GCommon().HandleError(fmt::format("The file \"%s\" does not exist", fname.c_str()), GLOCATION, THROW_EXCEPTION);
        return "";
    }

    COUT << "fname = " << fname << endl;

    if (argc != 1 && argc != 3)
    {
        GCommon().HandleError( fmt::format("When reading command line arguments from file you must specify either no arguments,\
            or exactly two arguments.\ncase1: If no arguments are given, the command line arguments are read from\
             %s\ncase: the arguments must be on the form -file [filename] in which case the command line is read from [filename]"), GLOCATION, THROW_EXCEPTION);

    }

    if (argc == 3)
    {
        if (string(argv[1]) != "-file")
        {
            GCommon().HandleError(fmt::format("Expected the first argument to be  \"-file\""), GLOCATION, THROW_EXCEPTION);
            return "";
        }
        else
        {
            fname = string(argv[2]);
        }
    }

    if (DoExists(fname) == false)
    {
        GCommon().HandleError(fmt::format("The file \"%s\" does not exist", fname.c_str()), GLOCATION, THROW_EXCEPTION);
        return "";
    }
    else
    {
        return ReadFirstLine(fname);
    }
}


bool
GFileIOHandler::CreateFolder(const string fname,  const bool print_error)
{
    return g_system()->mkdir(fname, print_error);
}
