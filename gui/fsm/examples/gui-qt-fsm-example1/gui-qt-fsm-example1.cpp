

#include <QtWidgets/QApplication>
#include <QtCore/QResource>
#include <QtCore/QFileInfo>
#include <QtCore/QtDebug>
#include <gui/common/GUIExecWidget.h>

#include <api/api-fsm/APIFSMControllerDebug.h>
#include <gui/fsm/GUIFsmGui.h>

#include <logging/LLogApi.h>

using namespace LOGMASTER;


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
   
    app.setApplicationName("fsmGuiTest");
    app.setOrganizationName("Kongsberg Ferrotech");
    
    APIFSMControllerDebug * c = APIFSMControllerDebug::Instance();
    c->GenerateMockFSM();
    
    QResource::registerResource("gui-qt.rcc");
    QFileInfo style(":/styles/norspace.qmm");
    if (style.exists())
    {
        QFile f(style.filePath());
        if (f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QString styleContent = f.readAll();
            qApp->setStyleSheet(styleContent);
            qDebug() << "Setting style :/styles/ferrotech.qmm";
            FORCE_DEBUG("Setting style :/styles/ferrotech.qmm");
        }
    }
    
    GUIFsmGui widget;
    ExecWidget(qobject_cast<QWidget*>(&widget));
    return 0;
}
