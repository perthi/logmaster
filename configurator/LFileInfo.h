#pragma once

#include <string>
using std::string;

namespace CONFIGURATOR
{
	class LFileInfo
	{
		LFileInfo(const string filepath, const string classname);

		string  GetSourceFileName() const;
		string  GetHeaderFileName() const;
		string  GetPath() const;
		string  GetClassName() const;

	private:
		string fPath = "";
		string fClassName = "";

	};

}

