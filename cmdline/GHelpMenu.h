#pragma once



#include "GArgumentDefinitions.h"

#include <utilities/GDefinitions.h>

#include <string>
using std::string;



class GHelpMenu
{
public:
    //static string    API   Help(const string cmd = "");
    static string    API   Help(const arg_deque args, const string cmd = "");
    static string    API   Help(const arg_deque args, const char* exename, const string heading, const string cmd = "");
    
};

