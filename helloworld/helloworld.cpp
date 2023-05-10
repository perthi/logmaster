// -*- mode: c++ -*-

#ifdef _W_IN32
#include <Windows.h>
#endif
#include <stdio.h>


#include <logging/LLogApi.h>
#include <logging/LPublisher.h>
#include <utilities/version-info/GMenu.h>

using namespace LOGMASTER;



void  logger_callback(const std::shared_ptr<LMessage>  m)
{
	static int cnt = 0;
	COUT << "GOT NEW MESSAGE, cnt = " << cnt << endl;
	//GUILogger::GetInstance()->newMessage(cnt, *m);
	cnt++;
};

class TEST_CALLBACK
{
public:
	static void  logger_callback(const std::shared_ptr<LMessage>  m)
	{
		static int cnt = 0;
		COUT << "GOT NEW MESSAGE, cnt = " << cnt << endl;
		//GUILogger::GetInstance()->newMessage(cnt, *m);
		cnt++;
	};


};

int main(int argc, const char **argv)
{
	GMenu::Instance()->ScanArguments(argc, argv);

	try
	{
		LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
		COM_ERROR("s1 = %d, s2 = %d, s3 = %d", 10, 11);
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

  
   
   //LLogging::Instance()->RegisterGuiSubscriber(logger_callback);
  // LLogging::Instance()->RegisterGuiSubscriber(TEST_CALLBACK::logger_callback);
  // FORCE_DEBUG("Hello world");
}

