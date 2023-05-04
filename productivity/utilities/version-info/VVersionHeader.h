#pragma once

#include <string>

using std::string;

class VVersionHeader
{
public:
	static void GenerateFile(const string version, const string branch, const string  configuration);
};

