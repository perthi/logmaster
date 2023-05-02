// -*- mode: c++ -*-

#ifdef _WIN32
#include <Windows.h>
#endif
#include <stdio.h>


#include <logging/LLogApi.h>
#include <logging/LPublisher.h>

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

int main()
{
   double test = 1.2345;
   printf("test = %f\n", test);
   LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
   
   //LLogging::Instance()->RegisterGuiSubscriber(logger_callback);
   LLogging::Instance()->RegisterGuiSubscriber(TEST_CALLBACK::logger_callback);


   FORCE_DEBUG("Hello world");
}

