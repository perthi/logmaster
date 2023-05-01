

#include  <gui/alarm/GUIAlarmGui.h>
// #include  <gui/alarm/GUIAlarm.h>
// #include  <gui/alarm/GUIAlarm_moc.h>
#include  <gui/common/GUIExecWidget.h>
#include  <gui/common/GUIInitStyles.h>
#include  <logging/LLogging.h>
#include  <logging/LLogTest.h>

using namespace LOGMASTER;

#include  <exception/GException.h>
#include  <QtWidgets/QApplication>
#include  <iostream>

using std::endl;
using std::cout;
using std::cerr;

#include <thread>
#include <chrono>

void start_gui( int argc, char** argv );
void messages();


//GUIAlarm* alarm = new GUIAlarm();

// QApplication* app = nullptr;
// GUIAlarmGui* widget = nullptr;

int dummy = 0;

QApplication* app =  new QApplication(dummy,0);
GUIAlarmGui* widget = new GUIAlarmGui();


void alarm_subscriber(const std::shared_ptr<LMessage>  m)
{
    static int cnt = 0;
    widget->NewMessage(cnt, *m);
    cnt++;
}


int main( int argc, char **argv )
{
   // app = new QApplication(argc, argv);

    GUIInitStyles::Init(app);
    app->setApplicationName("AlarmGuiTest");
    app->setOrganizationName("Embedded Cosnulting");

    //GUIAlarm* alarm = new GUIAlarm();
   
    GUIAlarmGui* widget = new GUIAlarmGui();

    QMainWindow* mainWindow = new QMainWindow;
    mainWindow->setCentralWidget(widget);
    mainWindow->show();
    //qApp->exec();


    LLogging::Instance()->RegisterGuiSubscriber(alarm_subscriber);
    //std::thread th1(start_gui, argc, argv);
    std::thread th2(messages);
    
    widget->StartTimer();
    //alarm->StartTimer();


    qApp->exec();

   // th1.join();
    th2.join();

}



void start_gui( int argc, char **argv)
{
    try
    {
       // GUIInitStyles::Init(app);
       // app->setApplicationName("AlarmGuiTest");
       // app->setOrganizationName("Embedded Cosnulting");

        SET_LOGLEVEL("--all");
        SET_LOGTARGET("1111");
        
       //  qApp->exec();

       // GUIAlarm* alarm = new GUIAlarm();
       // GUIAlarmGui *widget = new GUIAlarmGui(alarm);
       // ExecWidget(qobject_cast<QWidget*>(widget));
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
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        LLogTest::WriteMessages();
    }
}
