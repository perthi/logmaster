

#include "VScanArguments.h"

#include  <cmdline/GArgument.h>
#include  <cmdline/GCommandLineArgument.h>
#include  <cmdline/GLogApplication.h>
#include  <logging/GException.h>
#include  <utilities/GString.h>

VScanArguments::VScanArguments()
{
	InitArguements();
}


void
VScanArguments::InitArguements()
{
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-rcname", "-rcname [value]", "sets the name of the RC file (Windows)", &fParameters.fRCilename, fgkMANDATORY));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-dll", "-dll [value]", "sets the name of the DLL (Windows)", &fParameters.fDllname, fgkMANDATORY ));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-product", "-product [value]", "The product name", &fParameters.fProductname, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-desc", "-desc [value]", "The name of the product", &fParameters.fDescription, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-copyright", "-desc [value]", "Copyright notice", &fParameters.fCopyright, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-flagfile", "-flagfile [value]", "File containing flags use during compilation", &fParameters.fCompileflags_file, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-exename", "-exename [value]", "name of the executable", &fParameters.fExename, fgkOPTIONAL));

}


void 
VScanArguments::ApllyFlag(bool is_optional)
{
	if (is_optional == true)
	{
		for (auto arg : fArguments)
		{
			arg->SetOptional();
		}
	}

}

bool  
VScanArguments::CheckParameters(const VParameters p) const
{
#ifdef _WIN32
	if (p.fDllname != "")
	{
		G_ASSERT_ARGUMENT_EXCEPTION(g_string()->EndsWith(p.fDllname, ".dll"), "Invalid DLL name %s. Must end with .dll");
	}
	if (p.fExename != "")
	{
		G_ASSERT_ARGUMENT_EXCEPTION(g_string()->EndsWith(p.fExename, ".exe"), "Invalid exe name %s. Must end with .exe");
	}
#endif
	return true;
}


VParameters  &
VScanArguments::Scan(const string &cmdline)
{
	ApllyFlag(fForceOptional);
	GLogApplication().ScanArguments(cmdline, fArguments);
	CheckParameters( fParameters );

	return fParameters;
}


VParameters &
VScanArguments::Scan(int argc, const char** argv)
{
	ApllyFlag(fForceOptional);
	GLogApplication().ScanArguments(argc, argv, fArguments);
	CheckParameters(fParameters);
	return fParameters;
}

