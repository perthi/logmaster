#pragma once

#include <utilities/GDefinitions.h>

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace VHELPERS
{
	string year();

	string platform();
	string versionString(string s);
	string path(int argc, const char** argv);
	FILE* file(const string directory, const string fname);
	string configuration();
	void    helpMenu();
}