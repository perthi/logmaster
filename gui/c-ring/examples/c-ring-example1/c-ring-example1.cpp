// c-ring.cpp
// karl eirik bang fossberg


#include <gui/c-ring/GUICringWidget.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <iostream>

#include <kf-commands/KFArgumentHostName.h>
#include <kf-commands/KFArgumentPort.h>
#include <cmdline/GLogApplication.h>

#include <intercom/KFInterCom.h>
#include <logging/LLogApi.h>

using namespace LOGMASTER;


#include <api/api-hmi/APIHmi.h>
#include <kf-main/KFGlobals.h>
#include <configuration/KFConfigurationHandler.h>



int
main(int argc, const char **argv)
{

    SET_LOGLEVEL("--target-stdout --all");

    string dev_s = "";
    string hmi_s = "";

    auto  devices = new  GCommandLineArgument < string >("-xml-devices", "-xml-devices [base filename (without suffix)]", "Sets the xml files for devices", &dev_s, fgkMANDATORY, 0 );
    auto  hmi = new  GCommandLineArgument < string >("-xml-hmi", "-xml-hmi [base filename (without suffix) ]", "Sets the xml files for hmi", &hmi_s, fgkMANDATORY, 0 );

    std::shared_ptr<GLogApplication>  g =  std::make_shared<GLogApplication>();
    g->InitLogArgs();
    g->AddArgument(devices);
    g->AddArgument(hmi);
    g->ScanArguments(argc, argv);

    XMLFile_t xml_dev  =   XMLFile_t(dev_s);
    XSDFile_t xsd_dev  =   KFGlobals::Instance()->GetXSDFilenameDevices();
    KFConfigurationHandler::Instance()->ParseConfigDevices(xml_dev, xsd_dev);

    XMLFile_t xml_hmi  =   XMLFile_t(hmi_s);
    XSDFile_t xsd_hmi  =   KFGlobals::Instance()->GetXSDFilenameHmi();
    KFConfigurationHandler::Instance()->ParseConfigHmi(xml_hmi, xsd_hmi);

    auto ic =  KFInterCom::Instance();

    // With the port_listen set to anything else than 45500 I get "Could not fine any device with ID M7" when polling for M7.
    std::thread th = std::thread( &KFInterCom::StartIntercom, ic,  eCOM_MODE::UDP, string("127.0.0.1"), 45500, 45500 );


    QApplication application(argc, (char **)argv);
    GUICringWidget widget;
    widget.show();
    int status = application.exec();

    return status;
}
