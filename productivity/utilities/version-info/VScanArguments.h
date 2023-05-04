#pragma once

#include "VParameters.h"

#define FORCE_OPTIONAL false;

class VScanArguments
{
public:
	VParameters Scan(const string &cmdline, bool force_optional = false );
	VParameters Scan(int argc, const char** argv, bool force_optional = false);

	void EnableForceOptional(string ar = "") { fForceOptional = true; };

private:
	bool fForceOptional = false;

};



/*
time_t  the_time = time(NULL);

#ifdef _WIN32
#pragma warning(suppress: 4996) 
struct tm* a_time = localtime(&the_time);
#else
struct tm* a_time = localtime(&the_time);
#endif

string configuration;
string platform;

string year = g_string()->ToString<int>(a_time->tm_year + 1900);
string rc_filename = "unknown_resource_file.rc";
string compileflags_file = "unknown_compileflags_file";
string company = "Embedded Consulting, " + year;
string dllname = "unknown_dll";
string exename = "unknowne_exefile";
string productname = "unknown_product";
string description = "no_description";
string copyright = "unknown_copyright";
string compileinfo = "not_set";

*/