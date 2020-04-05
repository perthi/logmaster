// -*- mode: c++ -*-
#ifndef GGENERATEVERSIONINFO_H
#define GGENERATEVERSIONINFO_H

/****************************************************************************
*** Copyright(C) 2015  Per Thomas Hille, pth@embc.no                     ***
*** This file is part of logmaster. logmaster is free software : you can ***
*** redistribute it and / or modify it under the terms of the Lesser GNU ***
*** General Public License (LGPL) V3 or later. See .cpp file for details ***
****************************************************************************/


#define G_STANDALONE

#include <string>

using std::string;

/** @brief   auto generation of classes that contains GIT version information 
 *  @details Runs git-info in the current directory, extracts
 *  this information, and puts it dedicated container classes. This is in order to make it
 *  possible to ask the application about relevant version information such as the git tag
 *  compilation options that was used to generated the code etc.
 *  Typically this information via the -version commandline tag.  */
class  GGenerateVersionInfo
{
public:
    virtual  ~GGenerateVersionInfo();
    static  string GitInfo();
    static  string Branch();
    static  string Version();
    static  string CompileInfo(const string info_file);
    static  string LinkInfo( const string info_file );
  //  static string OriginalFilename();
    static  void GenerateClass( const string classname, const string exename, const string info_file, const string target_directory );

private:
     GGenerateVersionInfo();
    static  string ReadCompileInfo( const uint16_t idx, const string fname);
};



#endif
