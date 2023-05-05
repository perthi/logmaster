#pragma once

#include <string>

using std::string;

/** @brief Helper struct to hold parameters either parsed from the command line
*  or set in the code. This struct is passed to the functions generating cpp/h source files
* which is again used to embedd application information into the code or in the details
* section of a DLL (Windows only) */
struct VParameters
{
	string fConfiguration = "";//!< Debug vsRelease
	string fPlatform = ""; //!< 64 vs 32 bit
	string fYear = "";
	string fRCFilename = ""; //! (Windows only): Name of the file containing resource information that will be embedded int eh details secgion of the <DLL/exe file
	string fCompileflags_file = ""; //!< Name of file containing information about what compilation flags was used during code generation
	string fCompileinfo = "";  //!< Compilation info read from fCompileinfo
	string fCompany = ""; //!< Organization name
	string fAppName = ""; //!< Original name of the binary file
	string fProductname = "";
	string fDescription = "";
	string fCopyright = "Embedded Consulting";
	
	};

