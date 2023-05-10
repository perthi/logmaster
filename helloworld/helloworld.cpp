// -*- mode: c++ -*-

#ifdef _W_IN32
#include <Windows.h>
#endif
#include <stdio.h>


#include <logging/LLogApi.h>
#include <logging/LPublisher.h>
#include <utilities/version-info/GMenu.h>

using namespace LOGMASTER;

#include <thread>
#include <chrono>

void  logger_callback(const std::shared_ptr<LMessage>  m)
{
	static int cnt = 0;
	COUT << "GOT NEW MESSAGE, cnt = " << cnt << "m = "<< m->fMsgBody << endl;
	cnt++;
}

class TEST_CALLBACK
{
public:
	static void  logger_callback(const std::shared_ptr<LMessage>  m)
	{
		static int cnt = 0;
		COUT << "GOT NEW MESSAGE, cnt = " << cnt << "m = " << m->fMsgBody << endl;
		cnt++;
	};
};


class TestClass
{
	public:
		void TestGLocation(int timetowait, string name );
};



void
TestClass::TestGLocation(int /*timetowait*/, string /*name*/ )
{
	static int cnt = 0;
	
	const char *ptr = nullptr;

	for(int i=0; i < 100000; i++ )
	{
		ptr = GLocation( __FILE__,  __LINE__, __FUNCTION__).c_str() ;
		cout << "*ptr =" << ptr  << "\tstrlen = " << strlen(ptr) << "\tcnt =" << cnt << endl;
		
	//	auto ptr2 = GLocation( __FILE__,  __LINE__, __FUNCTION__).str() ;
	//	cout << "*ptr2 =" << ptr2  << "\tstrlen = " <<  ptr2.size() << "\tcnt =" << cnt << endl;


		//std::this_thread::sleep_for(std::chrono::milliseconds(timetowait) );
		cnt ++;
	}


}



int main(int argc, const char **argv)
{
	auto c1 = TestClass();
	auto c2 = TestClass();

	std::thread  t1(&TestClass::TestGLocation, &c1, 130, "thread1" ); 
	std::thread  t2(&TestClass::TestGLocation, &c2, 245,  "thread2"); 

	t1.join();
	t2.join();

	return 0;

	GMenu::Instance()->ScanArguments(argc, argv);

	try
	{
	//	LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
		COM_ERROR("s1 = %d, s2 = %d, s3 = %d", 10, 11);
	}
	catch (std::exception& e)
	{
		cout << e.what() << endl;
	}

    LLogging::Instance()->RegisterGuiSubscriber(logger_callback);
    LLogging::Instance()->RegisterGuiSubscriber(TEST_CALLBACK::logger_callback);
    FORCE_DEBUG("Hello world");
}

