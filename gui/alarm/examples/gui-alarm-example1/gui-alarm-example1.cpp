

#include  <gui/alarm/GUIAlarmGui.h>
#include  <gui/common/GUIExecWidget.h>
#include  <gui/common/GUIInitStyles.h>

#include  <logging/LLogTest.h>
#include  <logging/LPublisher.h>
using namespace LOGMASTER;

#include  <QtWidgets/QApplication>

#include <thread>
#include <chrono>


void generate_messages();
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
    LPublisher::Instance()->SetMode(ePUBLISH_MODE::SYNCHRONOUS);
    LLogging::Instance()->RegisterGuiSubscriber(alarm_subscriber);
    SET_LOGLEVEL("--all-debug");
    std::thread th2(generate_messages);

    GUIInitStyles().Init(app);
    app->setApplicationName("AlarmGuiTest");
    app->setOrganizationName("Embedded Cosnulting");
    ExecWidget(new GUIAlarmGui());
    th2.join();
}


void generate_messages()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        LLogTest::WriteMessages();
    }
}
