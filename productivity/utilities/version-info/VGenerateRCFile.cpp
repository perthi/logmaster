// -*- mode: c++ -*-
/*****************************************************************************
***          Author: Per Thomas Hille <pth@embc.no>                       ****
******************************************************************************/

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


#include <utilities/GDefinitions.h>


void
VGenerateRCFile::Generate(const string &outdir, const string &rc_filename, const string &company, const string &desc, 
    const string &dllname, const string &copyright, const string &prod_name)
{
    FILE* fp = 0;

#ifdef _WIN32
    fopen_s(&fp, rc_filename.c_str(), "w"); /// @todo check on return value 
#else
    fp = fopen(rc_filename.c_str(), "w");
#endif

    if (fp == 0)
    {
        throw(std::runtime_error("could not open file" + rc_filename));
    }

    fprintf(fp, "\n\n//DO NOT EDIT !!. KNS_TS auto generated resource file. Any changes will be overwritten during next compilation\n\n");

    if (outdir == "")
    {
        fprintf(fp, "#include \"Version.h\"\n");
    }
    else
    {
        fprintf(fp, "#include <%s\\Version.h>\n", outdir.c_str());
    }

    fprintf(fp, "#define  APSTUDIO_READONLY_SYMBOLS\n");
    fprintf(fp, "#include \"winres.h\"\n");
    fprintf(fp, "#undef APSTUDIO_READONLY_SYMBOLS\n");
    fprintf(fp, "\n\n");
    fprintf(fp, "#ifdef APSTUDIO_INVOKED\n");

    fprintf(fp, "1 TEXTINCLUDE\n");
    fprintf(fp, "BEGIN\n");
    fprintf(fp, "\t\"resource.h\\0\"\n");
    fprintf(fp, "END\n\n");

    fprintf(fp, "2 TEXTINCLUDE\n");
    fprintf(fp, "BEGIN\n");
    fprintf(fp, "\t\"#include \"\"winres.h\"\"\\r\\n\"\n");
    fprintf(fp, "END\n\n");

    fprintf(fp, "3 TEXTINCLUDE\n");
    fprintf(fp, "BEGIN\n");
    fprintf(fp, "\t\"\\r\\n  \\0\"");
    fprintf(fp, "END\n\n");
    fprintf(fp, "#endif\t//APSTUDIO_INVOKED\n\n");

    fprintf(fp, "VS_VERSION_INFO VERSIONINFO\n\n");
    fprintf(fp, "#ifdef   GIT_FILEVERSION\n");
    fprintf(fp, "FILEVERSION  GIT_FILEVERSION\n");
    fprintf(fp, "#else\n");
    fprintf(fp, "FILEVERSION 999, 999, 999, 999\n");
    fprintf(fp, "#endif\n\n");

    fprintf(fp, "#ifdef GIT_PRODUCTVERSION\n");
    fprintf(fp, "PRODUCTVERSION GIT_PRODUCTVERSION\n");

    fprintf(fp, "#else\n");
    fprintf(fp, "PRODUCTVERSION 7, 8, 9, 10\n");
    fprintf(fp, "#endif\n\n");

    fprintf(fp, "FILEFLAGSMASK 0x3fL\n");

    fprintf(fp, "#ifdef _DEBUG\n");
    fprintf(fp, "FILEFLAGS 0x1L\n");

    fprintf(fp, "#else\n");

    fprintf(fp, "FILEFLAGS 0x0L\n");
    fprintf(fp, "#endif\n\n");

    fprintf(fp, "FILEOS 0x40004L\n");
    fprintf(fp, "FILETYPE 0x2L\n");

    fprintf(fp, "FILESUBTYPE 0x0L\n");

    /////////
    fprintf(fp, "BEGIN\n");
    fprintf(fp, "\tBLOCK \"StringFileInfo\"\n");
    fprintf(fp, "\tBEGIN\n");
    fprintf(fp, "\t\tBLOCK \"040904b0\"\n");
    fprintf(fp, "\t\tBEGIN\n");
    fprintf(fp, "\t\t\tVALUE \"CompanyName\", \"%s\"\n", company.c_str());
    fprintf(fp, "\t\t\tVALUE \"FileDescription\", \"%s\"\n", desc.c_str());
    fprintf(fp, "\t\t\tVALUE \"InternalName\", \"%s\"\n", dllname.c_str());
    fprintf(fp, "\t\t\tVALUE \"LegalCopyright\", \"%s\"\n", copyright.c_str());
    fprintf(fp, "\t\t\tVALUE \"OriginalFilename\", \"%s\"\n", dllname.c_str());
    fprintf(fp, "\t\t\tVALUE \"ProductName\", \"%s\"\n", prod_name.c_str());
    fprintf(fp, "#ifdef GIT_PRODUCTVERSION_STRING\n");
    fprintf(fp, "\t\t\tVALUE  \"ProductVersion\", GIT_PRODUCTVERSION_STRING\n");
    fprintf(fp, "#else\n");
    fprintf(fp, "\t\t\tVALUE \"ProductVersion\", \" - 1. - 1. - 1\"\n");
    fprintf(fp, "#endif\n");
    fprintf(fp, "\t\tEND\n");
    fprintf(fp, "\tEND\n");

    fprintf(fp, "BLOCK \"VarFileInfo\"\n");
    fprintf(fp, "BEGIN\n");
    fprintf(fp, "VALUE \"Translation\", 0x409, 1200\n");

    fprintf(fp, "END\n");
    fprintf(fp, "END\n\n\n");
    fclose(fp);
}

