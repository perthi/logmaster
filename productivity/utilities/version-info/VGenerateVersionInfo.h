// -*- mode: c++ -*-
#ifndef GGENERATEVERSIONINFO_H
#define GGENERATEVERSIONINFO_H

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
****************************************************************************/


#include <utilities/GDefinitions.h>


#include <string>

using std::string;

/** @brief   auto generation of classes that contains GIT version information 
 *  @details Runs git-info in the current directory, extracts
 *  this information, and puts it dedicated container classes. This is in order to make it
 *  possible to ask the application about relevant version information such as the git tag
 *  compilation options that was used to generated the code etc.
 *  Typically this information via the -version commandline tag.  */
class  VGenerateVersionInfo
{
public:
    static string  API GitInfo();
    static string  API Branch();
    static string  API Version();
    static string  API CompileInfo(const string info_file);
    static string  API LinkInfo( const string info_file );
    static void    API GenerateClass( const string classname, const string exename, const string info_file, const string target_directory );

private:
    static string API  ReadCompileInfo( const unsigned int idx, const string &fname);
};


#endif
