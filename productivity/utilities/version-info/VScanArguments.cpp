

#include "VScanArguments.h"

#include  <cmdline/GArgument.h>
#include  <cmdline/GCommandLineArgument.h>
#include  <cmdline/GLogApplication.h>
#include  <logging/GException.h>
#include  <utilities/GString.h>

#include <functional>


VParameters  VScanArguments::fParameters = VParameters();


VScanArguments::VScanArguments()
{
	InitArguments();
}


void
VScanArguments::InitArguments()
{

#ifdef _WIN32
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-rcname", "-rcname [value]", "sets the name of the RC file (Windows)", &fParameters.fRCFilename, fgkMANDATORY));
#endif
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-appname", "-appname [value]", "sets the name of the exe/binary file", &fParameters.fAppName, fgkMANDATORY ));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-productname", "-product [value]", "The product name", &fParameters.fProductname, fgkOPTIONAL));
	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-desc", "-desc [value]", "The name of the product", &fParameters.fDescription, fgkOPTIONAL));
//	fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-copyright", "-desc [value]", "Copyright notice", &fParameters.fCopyright, fgkOPTIONAL));
	
//#ifdef  __linux__ 
	//fArguments.push_back(std::make_shared <GCommandLineArgument<string> >("-flagfile", "-flagfile [value]", "File containing flags use during compilation", 
//		                                                                  &fParameters.fCompileflags_file, fgkOPTIONAL));


	auto bla = std::make_shared <GCommandLineArgument<string> >("-flagfile", "-flagfile [value]", "File containing flags use during compilation",
		&fParameters.fCompileflags_file, fgkOPTIONAL);



		std::function<bool(const string  cmd, const string args_s, const vector<string>  sub, const vector<string>  par)>
		funct(std::bind(&VScanArguments::FlagFileCallBack, this, std::placeholders::_1,
			std::placeholders::_2,
			std::placeholders::_3,
			std::placeholders::_4));

		bla->SetValidationFunction(funct);

		fArguments.push_back(bla);
}


void 
VScanArguments::ApplyFlag(bool is_optional)
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
		return false; /// Just in case exceptions are disabled
	}
#endif
	return true;
}


VParameters  &
VScanArguments::Scan(const string &cmdline)
{
	ApplyFlag(fForceOptional);
	GLogApplication().AddArguments(fArguments).ScanArguments(cmdline);
	CheckParameters( fParameters );

	return fParameters;
}


VParameters &
VScanArguments::Scan(int argc, const char** argv)
{
	ApplyFlag(fForceOptional);
	GLogApplication().AddArguments(fArguments).ScanArguments(argc, argv);
	CheckParameters(fParameters);
	return  fParameters;
}


bool 
VScanArguments::FlagFileCallBack(const string /*cmnd*/, const string  args_s, const vector<string> sub, const vector<string> par)
{
	G_ASSERT_ARGUMENT_EXCEPTION(sub.size() == 0, "%s does not take any sub commands; (args = %s)", args_s.c_str() );
	G_ASSERT_ARGUMENT_EXCEPTION(par.size() == 2, "%s takes exactly two parameters: 1) The name of the flag file, 2) the output directory");

	if (par.size() == 2)
	{
		fParameters.fCompileinfo = par[1];
		fParameters.fCompileflags_file = par[0];

	//	FORCE_DEBUG("compile info = %s",  par[1].c_str() );
	//	FORCE_DEBUG("compile flags file = %s",  par[0].c_str() );
	}

	return false;
}

