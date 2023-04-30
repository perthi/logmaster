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


int main()
{

   double test = 1.2345;
   printf("test = %f\n", test);
   LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);

    LPublisher::Instance()->RegisterGuiSubscriber(logger_callback);
   //auto subscribers = LLogging::Instance()->GetGuiSubscribers();
   //COUT << "size = " << subscribers.size() << endl;
   FORCE_DEBUG("Hello world");


}

