// -*- mode: c++ -*-


#include <logging/LLogApi.h>
#include <logging/LPublisher.h>
#include <utilities/version-info/GMenu.h>
#include <utilities/GFileIOHandler.h>
#include <cmdline/GCommandLineArgument.h>
#include <cmdline/GArgument.h>
#include <utilities/GFileIOHandler.h>
#include <utilities/GSystem.h>
#include <logging/GException.h>


using namespace LOGMASTER;


#ifdef _W_IN32
#include <Windows.h>
#endif


#include <stdio.h>
#include <thread>
#include <chrono>
#include <optional>
#include <string>
#include <filesystem>


#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

using namespace LOGMASTER;


bool rm(const string fname);

int main(int /*argc*/, const char ** /*argv*/ )
{
	for (int i = 0; i < 5; i++)
	{
		try
		{
			EXCEPTION("This is an exception message");
		}
		catch (GException &e)
		{
			FORCE_DEBUG("The message is: %s", e.what());
			cerr << "exception caught:" << e.what() << endl;
			cerr << g_system()->Errno2String(errno, "", "") << endl;
		}
		catch (...)
		{
			cerr << "unknown exception caught:" << endl;
		}
	}

	return 0;
}



/*
class Test
{
	public:
		bool CallBack (const string  cmnd, const string args_s, const vector<string> sub, const vector<string> par)
		{
			FORCE_DEBUG( "args_s = %s", args_s.c_str() );
			return true;
		}
};


int main(int argc, const char **argv)
{
	GMenu::Instance()->ScanArguments(argc, argv);

	auto t1 = std::make_shared <GCommandLineArgument<string> >("-test", "-test [value]", "Testing calback", nullptr, fgkOPTIONAL);
	auto t2 = std::make_shared <GCommandLineArgument<string> >("-test2", "-test2 [value]", "Testing calback", nullptr, fgkOPTIONAL);
    std::deque< std::shared_ptr<GArgument> > args = 	std::deque< std::shared_ptr<GArgument> >();

	Test test;

	args.push_back(t1);
	args.push_back(t2);

	std::function<bool(const string  cmd, const string args_s, const vector<string>  sub, const vector<string>  par)>
		funct(std::bind(&Test::CallBack, &test, std::placeholders::_1,
			std::placeholders::_2,
			std::placeholders::_3,
			std::placeholders::_4));

		t1->SetValidationFunction(funct);
		t2->SetValidationFunction(funct);

	try
	{
		GLogApplication().AddArguments(args).ScanArguments("-test xxxxblahh1 blhaah2 fooo bar --exstra --extra2  -test2 3  4 55  --bar");

//		bool status = true;
	}
	catch( GException &e)
	{
		cout << e.what() << endl;
	}	
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "Unknown exception caught" << endl;
	}
	FORCE_DEBUG("DONE");
}
*/



