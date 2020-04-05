
// -*- mode: c++ -*-

/*****************************************************************************
******************************************************************************
*** This file is part of logmaster.                                        ***
*** Copyright (C) 2018 Per Thomas Hille <pth@embc.no> http:///www.embc.no  ***
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


#include   "GGenerateVersionInfo.h"
#include   <utilities/GSystem.h>
#include   <utilities/GTokenizer.h>
#include   <utilities/GFileIOHandler.h>
#include   <utilities/GString.h>

#include <logging/LLogApi.h>

using  namespace LOGMASTER;


GGenerateVersionInfo::GGenerateVersionInfo()
{

}


GGenerateVersionInfo::~GGenerateVersionInfo()
{

}


string
GGenerateVersionInfo::GitInfo()
{
#ifdef _WIN32
    return "git info is not avilable for Windows yet";
#else
    return g_system()->exec("git-info");
#endif
}


string
GGenerateVersionInfo::Branch()
{
    string tmp;
#ifdef _WIN32
    tmp = g_system()->exec("git branch |  \"C:\\Program Files\\Git\\usr\\bin\\grep.exe\" \"*\" ");
//	tmp = "not implemented on windows";
#else
    tmp = g_system()->exec("git branch | grep \"*\"");
#endif

    vector<string> tokens = g_tokenizer()->Tokenize(tmp, " ");

    if (tokens.size() == 2)
    {
        g_string()->Trim(tokens[1], '\n');
        return tokens[1];
    }
    else
    {
        return  "Error parsing branch !!";
    }
}


string
GGenerateVersionInfo::Version()
{
#ifndef _WIN32
    string tmp = g_system()->exec("git describe --tags");
#else
	  string tmp = g_system()->exec("git describe --tags");
	//string tmp  = "git describe --tags takes forever on windows, ignored !!";
#endif

	g_string()->Trim(tmp, '\n');
	return tmp;
}

string
GGenerateVersionInfo::CompileInfo(const string fname)
{
#ifndef  _WIN32
    return ReadCompileInfo(1, fname);
#else
	return "not implemented for windows";
#endif
}

string
GGenerateVersionInfo::LinkInfo(const string fname)
{
	#ifndef  _WIN32
    return ReadCompileInfo(0, fname);
#else
	return "not implemented for windows";
#endif
}


string
GGenerateVersionInfo::ReadCompileInfo(const uint16_t idx, const string fname)
{   
//    CERR << "reading file = " << fname << endl;
    vector<string> cont = g_file()->ReadAll(fname.c_str());

    string ret;

    if (cont.size() > idx)
    {
        ret = cont[idx];
    }
    else
    {

      //  printf("FATAL Error reading compil info from file: %s", fname.c_str());
        //   G_FATAL("Error reading compil info from file: %s", fname.c_str() );
        //  COUT << "Error reading compil info from file : " << fname << endl;
    }

    return ret;

}


void
GGenerateVersionInfo::GenerateClass(const string class_name, const string exename, const string info_file, const string target_directory)
{
    string filename_cpp;
    string filename_h;

    if (target_directory == ".")
    {
        filename_cpp = class_name + ".cpp";
        filename_h = class_name + ".h";
    }
    else
    {
        filename_cpp = target_directory + "/" + class_name + ".cpp";
        filename_h = target_directory + "/" + class_name + ".h";
    }


    string str = class_name;
    // string guard =std::transform( str.begin(), str.end(), str.begin(), ::toupper);
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) -> unsigned char { return std::toupper(c); });

#ifdef _WIN32
    FILE *fp = 0;
    fopen_s(&fp, filename_cpp.c_str(), "w");
#else
    FILE *fp = fopen(filename_cpp.c_str(), "w");
#endif

    if (fp == 0)
    {

#ifndef _WIN32
        G_FATAL("Could not open file: %s", filename_cpp.c_str());
#endif

		//      printf("Could not open file: %s", filename_cpp.c_str());

    }
    else
    {
        fprintf(fp, "// -*- mode: c++ -*-\n\n");
        fprintf(fp, "/******\t\tTHIS FILE IS AUTOGENERATED, DO NOT EDIT !!\t******/\n");
     ///   fprintf(fp, "/******\t\tDate: %s\t\t*****/\n\n\n", g_time()->TimeStamp().c_str());
        fprintf(fp, "\n\n");
        fprintf(fp, "#include <string>\n");
        fprintf(fp, "using std::string; \n\n");
        fprintf(fp, "#include <version-info/%s>\n\n", filename_h.c_str());
        fprintf(fp, "const string %s::fGitBranch = \"%s\";\n", class_name.c_str(), Branch().c_str());
        fprintf(fp, "const string %s::fGitTag = \"%s\";\n", class_name.c_str(), Version().c_str());
        fprintf(fp, "const string %s::fCompileFlags = \"%s\";\n", class_name.c_str(), CompileInfo(info_file).c_str());
        fprintf(fp, "const string %s::fLinkFlags = \"%s\";\n", class_name.c_str(), LinkInfo(info_file).c_str());
        fprintf(fp, "string %s::fOriginalExeName = \"%s\";\n", class_name.c_str(), exename.c_str());


#ifdef _WIN32
        fprintf(fp, "const string %s::fGitInfo = \"%s\";\n", class_name.c_str(), "Not yest implemented for Windows");
#else

        string tmp = GitInfo();
        g_string()->Trim(tmp, { ' ', '\n', '\t' });
        g_string()->ReplaceBadChar(tmp, '_', "#*@");
        tmp = g_string()->Replace(tmp, "\"", "");
        vector<string> tokens = g_tokenizer()->Tokenize(tmp, "\n");

        fprintf(fp, "const string %s::fGitInfo = \"", class_name.c_str() );
        for(size_t i=0; i < tokens.size(); i++ )
        {
            fprintf(fp,  "%s\\n\\\n", tokens[i].c_str() );
        }

        fprintf(fp, "\";\n\n\n");
        
        fclose(fp);
#endif

    }
}






/// #define G_STANDALONE
