// gui-c-ring-operations.cpp
// karl eirik bang fossberg


#include <gui/operations/GUICringOperationsShowAll.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <iostream>



#include <kf-commands/KFArgumentHostName.h>
#include <kf-commands/KFArgumentPort.h>
#include <cmdline/GLogApplication.h>
#include <intercom/KFInterCom.h>
#include <logging/LLogApi.h>
#include <api/api-hmi/APIHmi.h>
using namespace LOGMASTER;

#include <kf-main/KFGlobals.h>
#include <configuration/KFConfigurationHandler.h>


void scan_arguments( std::shared_ptr< GLogApplication> g,  int argc,  const char **argv )
{
    g->ScanArguments(argc, argv);
}

int
main(int argc, const char **argv)
{

    // SET_LOGFORMAT("--target-stdout 11000001");
    // SET_LOGFORMAT("--target-file 11111111");
    // SET_LOGLEVEL("--all");

    int status;


    std::thread activeThread;
    try
    {

        string dev_s = "";
        string hmi_s = "";

        auto  devices = new  GCommandLineArgument < string >("-xml-devices", "-xml-devices [base filename (without suffix)]", "Sets the xml files for devices", &dev_s, fgkMANDATORY, 0 );
        auto  hmi = new  GCommandLineArgument < string >("-xml-hmi", "-xml-hmi [base filename (without suffix) ]", "Sets the xml files for hmi", &hmi_s, fgkMANDATORY, 0 );

        std::shared_ptr<GLogApplication>  g =  std::make_shared<GLogApplication>();
        g->InitLogArgs();
        g->AddArgument(devices);
        g->AddArgument(hmi);

        scan_arguments(g, argc, argv);

        HMI_ASSERT_EXCEPTION(  dev_s !=  "",  "filename dev_s cannot be empty" );
        HMI_ASSERT_EXCEPTION(  hmi_s  !=  "",  "filename hmi_s cannot be empty" );

        XMLFile_t xml_dev  =   XMLFile_t(dev_s);
        XSDFile_t xsd_dev  =   KFGlobals::Instance()->GetXSDFilenameDevices();
        KFConfigurationHandler::Instance()->ParseConfigDevices(xml_dev, xsd_dev);

        XMLFile_t xml_hmi  =   XMLFile_t(hmi_s);
        XSDFile_t xsd_hmi  =   KFGlobals::Instance()->GetXSDFilenameHmi();
        KFConfigurationHandler::Instance()->ParseConfigHmi(xml_hmi, xsd_hmi);


        APIHmi api;

        auto ic =  KFInterCom::Instance();
        activeThread = std::thread( &KFInterCom::StartIntercom, ic,  eCOM_MODE::UDP, string("127.0.0.1"), 45500, 45500 );
        {

            QApplication application(argc, (char**)argv);
            GUICringOperationsShowAll widget;
            widget.show();
            int status = application.exec();

        }
        // The exception below is to avoid the following error message:
        // terminate called without an active exception
        // Aborted (core dumped)
        EXCEPTION("STOPPING APPLICATION");


        // if (th.joinable() == true)
        // {
        //     FORCE_DEBUG("Joining thread ...");

        //     th.join();
        //     FORCE_DEBUG("Done .....");
        // }
        // else
        // {
        //     G_FATAL("Thread is not joinable");
        // }
    }
    catch(const GException& e)
    {
        activeThread.join();
        FORCE_DEBUG("THREAD JOINED");
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception& e)
    {
        activeThread.join();
        FORCE_DEBUG("THREAD JOINED");
        std::cerr << e.what() << '\n';
    }
    catch(const std::string& str)
    {
        activeThread.join();
        FORCE_DEBUG("THREAD JOINED");
        std::cerr << str << '\n';
    }
    catch(...)
    {
        activeThread.join();
        FORCE_DEBUG("THREAD JOINED");
        CERR << "unknown exception caught" << endl;
    }


    return status;
}