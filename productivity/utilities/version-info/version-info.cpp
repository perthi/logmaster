
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


#include "VGenerateRCFile.h"
#include "VGenerateVersionInfo.h"
#include "VScanArguments.h"
#include "VHelpers.h"
#include "VVersionHeader.h"
#include "external_includes.h"


int main(int argc, const char** argv)
{
	return 0;
	if (g_cmdscan()->HasArgument(argc, argv, "-help"))
	{
		VHELPERS::helpMenu();
		exit(0);
	}

	try
	{
		LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
		string year = VHELPERS::year();
		string compileinfo = "not_set";
		string configuration = VHELPERS::configuration();
		string path = VHELPERS::path(argc, argv);
		string version = VGenerateVersionInfo::Version();
		string branch = VGenerateVersionInfo::Branch();
		VScanArguments scanner;
		VParameters p = scanner.Scan(argc, argv);

#ifdef _WIN32
		VVersionHeader::GenerateFile(version, branch, configuration);
		VGenerateRCFile::Generate("", p.fRCFilename, p.fCompany, p.fDescription, p.fAppName, p.fCopyright, p.fProductname);
#endif
		VGenerateVersionInfo::GenerateClass("GVersion", p.fAppName, p.fCompileflags_file, ".");
	}

	catch (std::exception& e)
	{
		CERR << "Exception caught: " << e.what() << endl;
	}
	catch (...)
	{
		CERR << "Unknown exception caught" << endl;
	}
	return 0;
}

