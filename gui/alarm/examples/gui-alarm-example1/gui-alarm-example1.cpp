

#include <iostream>

using std::cout;
using std::endl;


#include  <QtWidgets/QApplication>
#include  <QtWidgets/qwidget.h>

#include  <QtCore/QResource>
#include  <QtCore/QFileInfo>
#include  <QtCore/QtDebug>

#include  <gui/alarm/GUIAlarmGui.h>
#include  <gui/logger/GUILoggerGui.h>
#include  <gui/logger/GUILogger.h>
#include  <gui/common/GUIExecWidget.h>
#include  <gui/common/GUIInitStyles.h>

#include  <logging/LLogging.h>
#include  <logging/LLogTest.h>

#include  <utilities/GException.h>
#include  <iostream>

using std::endl;
using std::cout;
using std::cerr;

//#include  <gui/common/GUIInitStyles.h>

//#include <logging/LLogApi.h>
//#include <logging/LLogTest.h>

using namespace LOGMASTER;

#include <thread>
#include <chrono>

void start_gui( int argc, char** argv );
void messages();

int main( int argc, char **argv )
{
	std::thread th1(start_gui, argc, argv);
	std::thread th2(messages);

	th1.join();
	th2.join();

}

void start_gui( int argc, char **argv)
{
	try
	{
		QApplication app(argc, argv);

		GUIInitStyles::Instance()->Init(&app);
		app.setApplicationName("AlarmGuiTest");
		app.setOrganizationName("Kongsberg Ferrotech");

		SET_LOGLEVEL("--all");
		SET_LOGTARGET("1111");
	//	LLogging::Instance()->Log(eMSGLEVEL::LOG_DEBUG, eMSGSYSTEM::SYS_FSM, GLOCATION, "hello world !!!!----------------------------------");
	//	LLogTest::WriteMessages();
		GUIAlarmGui widget;
		ExecWidget(qobject_cast<QWidget*>(&widget));
	}
	catch (GException& e)
	{
		cerr << e.what() << endl;
	}
	catch (std::exception& e)
	{
		cerr << e.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown exception caught" << endl;
	}

}


void messages()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		LLogTest::WriteMessages();
	}
}
