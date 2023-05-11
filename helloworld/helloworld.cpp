// -*- mode: c++ -*-

#ifdef _W_IN32
#include <Windows.h>
#endif
#include <stdio.h>

#include <logging/LLogApi.h>
#include <logging/LPublisher.h>
#include <utilities/version-info/GMenu.h>
#include <utilities/GFileIOHandler.h>

using namespace LOGMASTER;

#include <thread>
#include <chrono>

#include <optional>
#include <string>

std::optional<std::string> FindUserNick()
{
	bool nick = true;
	string nickname = "nickname";

    if (nick)
        return { nickname };

    return std::nullopt; // same as return { };
}




int main(int argc, const char **argv)
{
	GMenu::Instance()->ScanArguments(argc, argv);

	try
	{
		bool status = true;
		vector<string> all = g_file()->ReadAll("gxxxoogletest.log", &status);

		FORCE_DEBUG("size = %d\tstatus = %s", all.size(), (status == false ? "FALSE" : "TRUE") );

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

