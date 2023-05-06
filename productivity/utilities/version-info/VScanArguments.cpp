

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

#ifdef _WIN32
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-rcname", "-rcname [value]", "sets the name of the RC file (Windows)", &fParameters.fRCFilename, fgkMANDATORY));
#endif
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-appname", "-appname [value]", "sets the name of the exe/binary file", &fParameters.fAppName, fgkMANDATORY ));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-producname", "-product [value]", "The product name", &fParameters.fProductname, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-desc", "-desc [value]", "The name of the product", &fParameters.fDescription, fgkOPTIONAL));
//	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-copyright", "-desc [value]", "Copyright notice", &fParameters.fCopyright, fgkOPTIONAL));
	
#ifdef  __linux__ 
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-flagfile", "-flagfile [value]", "File containing flags use during compilation", &fParameters.fCompileflags_file, fgkOPTIONAL));
#endif

	//	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-exename", "-exename [value]", "name of the executable", &fParameters.fExename, fgkOPTIONAL));

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
#ifdef _WIN32
VScanArguments::CheckParameters(const VParameters p) const
#else
VScanArguments::CheckParameters(const VParameters) const
#endif
{
#ifdef _WIN32
	if (p.fAppName != "")
	{
		G_ASSERT_ARGUMENT_EXCEPTION(g_string()->EndsWith(p.fAppName, vector<string>{ ".dll", ".exe"}), "Invalid DLL/exe name %s. Must end with either .dll or .exe", p.fAppName.c_str() );
		G_ASSERT_ARGUMENT_EXCEPTION(g_string()->EndsWith(p.fRCFilename,".rc" ), "Invalid RC filename name %s. Must end with .rc", p.fRCFilename.c_str());
		return false; /// Just in case exeptiona are disabled
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

