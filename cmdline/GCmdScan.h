// -*- mode: c++ -*-

#ifndef GCMDSCAN_HPP
#define GCMDSCAN_HPP


/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/


#include "GArgumentParsed.h"
#include "GCommandLineArgument.h"
#include "GArgument.h"
#include <utilities/GDefinitions.h>
#include <utilities/GNumbers.h>
#include <logging/GException.h>

#include <typeinfo>

#include <vector>
#include <deque>
#include <string>
using std::vector;
using std::string;

#include <mutex>

#include <memory>

class GCmdScan;

GCmdScan   API* g_cmdscan();

/** @brief scanning of command line arguments */
class  GCmdScan
{
    friend GCmdScan* g_cmdscan();

public:
    static GCmdScan   API* Instance();
    API GCmdScan();
    virtual API ~GCmdScan() {};
    inline bool   HasArgument(int argc, const char** argv, const string cmd) const;
    inline bool   HasArgument(int argc, const char** argv, vector <string> commands) const;
    inline bool   HasArgument(const vector<string> tokens, const string com) const;

 
    void   API SetIgnoreStrayArgument(const bool ignore = true);
    bool   API GetIgnoreStrayArgument() const;

    vector < GArgumentParsed > API ScanArguments(const  int  argc, const char** argv, std::shared_ptr<GArgument> arg) const;
    vector < GArgumentParsed > API ScanArguments(const  int  argc, const char** argv, deque<  std::shared_ptr<GArgument> >* arg) const;
    
    template<typename T> 
    vector < GArgumentParsed > API ScanArgument(const  uint64_t  argc, const char** argv, std::shared_ptr<GCommandLineArgument<T> > arg) const;
    
    vector < GArgumentParsed >  API SplitCommands(const  int argc, const char** argv, const bool skipfirst = true) const;
    void  SetExecName(deque<  std::shared_ptr<GArgument>  >* arg, const char* name) const;
    virtual bool API  Verify(std::shared_ptr<GArgument>  a, GArgumentParsed v) const;


    template<typename T> void  SetParametersF(std::shared_ptr <GArgument> a, GArgumentParsed v) const;
    template<typename T> void   SetParametersV(std::shared_ptr <GArgument> a, vector<string> vs) const;
    template<typename T, typename U = vector<T> > void  SetParametersVI(std::shared_ptr <GArgument> a, vector<string> vs) const;
    template<typename T> void    SetParameterVal_t(std::shared_ptr<GArgument>  a, GArgumentParsed v) const;


private:
    bool fDoIgnoreStrayArguments;
    bool  IsCommand(const string arg) const;
    bool  IsSubCommand(const string arg) const;
    bool  CheckMandatory(const vector<GArgumentParsed> v, const deque < std::shared_ptr<GArgument>  >* args) const;
    bool  CheckValid(const vector<GArgumentParsed> v, const deque  <  std::shared_ptr < GArgument>  >* args) const;
    void  CheckDuplicates(deque <  std::shared_ptr<GArgument>  >* args) const;
};


inline bool
GCmdScan::HasArgument(int argc, const char** argv, vector<string> commands) const
{
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (HasArgument(argc, argv, commands[i]) == true)
        {
            return true;
        }
    }
    return false;
}


inline bool
GCmdScan::HasArgument(int argc, const char** argv, const string cmd) const
{
    string s1;

    for (int i = 1; i < argc; i++)
    {
        s1.assign(argv[i]);

        if (s1 == cmd)
        {
            return true;
        }
    }
    return false;
}



inline bool
GCmdScan::HasArgument(const vector<string> tokens, const string command) const
{
    for (uint16_t i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] == command)
        {
            return true;
        }
    }
    return false;
}




#endif