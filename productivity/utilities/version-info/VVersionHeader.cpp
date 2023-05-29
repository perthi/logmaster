
#include "VVersionHeader.h"
#include "VHelpers.h"
#include <utilities/GUtilities.h>

void 
VVersionHeader::GenerateFile(const string version, const string /*branch*/, const string  configuration)
{
    FILE* fp_h = VHELPERS::file("include", "Version.h");
    string v = VHELPERS::versionString(version);

    fprintf(fp_h, "#pragma once\n\n");
    g_utilities()->AutoClause("", fp_h);
    fprintf(fp_h, "#define GIT_PRODUCTVERSION %s\n", v.c_str());

    fprintf(fp_h, "#define GIT_PRODUCTVERSION_STRING \"%s, %s_%s\"\n", version.c_str(), VHELPERS::platform().c_str(), configuration.c_str());
    fprintf(fp_h, "#define GIT_FILEVERSION %s\n", v.c_str());
    fprintf(fp_h, "#define GIT_FILEVERSION_STRING \"%s\"\n", v.c_str());
    fclose(fp_h);
}