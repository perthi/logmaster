// -*- mode: c++ -*-
#pragma once

/***************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                     ****
****************************************************************************/

/****************************************************************************
*** Copyright(C) 2018  Per Thomas Hille, pth@embc.no                      ***
*** This file is part of logmaster.logmaster is free software : you can   ***
*** redistribute it and / or modify it under the terms of the Lesser GNU  ***
*** General Public License(LGPL) V3 or later.See.cpp file for details     ***
*****************************************************************************/

#include "GDefinitions.h"
#include <cstring>
#include <string>


using std::string;
#include <vector>
using std::vector;

#include <stdio.h>
#include <algorithm>
#include <codecvt>
#include <sstream>
#include <iomanip>
#include <locale>



#define __STDC_WANT_LIB_EXT1__ 1
class GString;

 GString   API *  g_string();


/** @brief various string manipulation functions */
class GString
{
 friend  GString   * g_string();  

 public:
     char     API *  ReplaceBadChar(char *inputstring, const char delimeter = '_', const char *suspicious = 0);
     string    API ReplaceBadChar(string &inputstring, const char delimeter = '_', const char *suspicious = 0);
     string    API Replace(const string original, const string toreplace, const string replacement);
     
     string    API ToPascalCase( const string  in ) const;
     string    API ToUpperCase(  const string  in ) const;  
     string    API ToLowerCase(  const string  in ) const;

     string    API Path2ClassName(const string & path);   

     template <typename T>
     string    API Vec2String(const vector<T> in, const string sep = "\n");
     
     template <typename T>
     string    API ToString(const T in, const int w = -1, const char pad = '0');
     
     int         API  CountOccurrences(const string input, const char c, const bool ignore_case);
     bool         API Contains(const vector<string> &str, const string &substring, const bool ignore_case = true, long long int *pos = 0);
     bool         API Contains(const string &str, const string &substring, const bool ignore_case = true, long long int *pos = 0);
     bool         API BeginsWith(const string &str, const string &substring, const bool ignore_case = true);
     bool         API BeginsWith(const vector<string> * const arr, const string token, const bool ignore_case = true);
     
     bool         API EndsWith(const string &str, const string &substring, const bool ignore_case = true);
     bool         API EndsWith(const string& str, const vector <string>   substrings, const bool ignore_case = true);

     bool         API CompareNoCase(string lhs, string rhs) { return (ToUpper(lhs) == ToUpper(rhs)); }
 
     string       API & Ltrim(string &s, const char c = ' ');
     string       API & Rtrim(string &s, const char c = ' ');
     string       API & Trim(string &s, const char c = ' ');
     string       API & Trim(string &s, const vector<char> tokens);
     vector<string> API Trim(vector<string> &s, const char c = ' ');
     vector<string> API Trim(vector<string> &s, const vector<char> tokens);



     string       API &Utf8ToAnsi(string &s);
     char         API *Utf8ToAnsi(char *s);
     bool         API  IsAnsi(string &s);
     std::string   API AnsiToUtf8(const std::string &ansiStr);
     string       API &ToLower(string &s);
     string       API &ToUpper(string &s);
     bool API      IsMatch(const string pattern, const string val, bool require_exact_match = false);

 private:
     GString(){};
     virtual ~GString(){};
};




template<typename T>
string
GString::Vec2String(const vector<T> in, const string sep)
{
    std::stringstream buffer;
    buffer.str("");

    for (uint16_t i = 0; i< in.size(); i++)
    {
        buffer << in[i] ;
        if (i < (in.size() - 1))
        {
            buffer << sep;
        }

    }
    return buffer.str();
}


template<typename T>
string
GString::ToString(const T in, const int w, const char pad) 
{
    std::stringstream buffer;
    buffer.str(std::string());

    if (w > 0)
    {
        buffer.width(w);
        buffer.fill(pad);
    }

    buffer << std::setprecision(std::numeric_limits<T>::max_digits10 ) << in;
    return buffer.str();
}