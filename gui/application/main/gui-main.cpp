// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <ctime>
#include <csignal>
#include <memory>
#include <thread>

#include "GUIMainWindow.h"
#include <QtWidgets/QApplication>
#include <kf-main/KFMain.h>
#include <logging/LLogging.h>
#include <cmdline/GCmdScan.h>
#include <cmdline/GLogApplication.h>
#include <cmdline/GCommandLineArgument.h>
#include <common/GlobalRegistry.h>
#include <gui/common/GUICommonGui.h>
#include <gui/common/GUIInitStyles.h>
#include <utilities/GConstants.h>
#include <api/api-fsm/APIFSMController.h>
#include <kf-main/KFGlobals.h>
#include <configuration/KFConfigurationHandler.h>
#include <intercom/KFInterCom.h>

// #ifdef _WIN32
// #include <gui/fsm/GUIFsmGui_moc.h>
// #endif

void exiting()
{
    USER_INFO("Exiting normally");
    exit(0);
}

void signalHandler(int signum)
{
    USER_INFO("Interrupt signal (%d) received", signum);
    exit(signum);
}


int main(int argc, char **argv)
{
    // SET_LOGFILENAME("ferrotech.log");
    // SET_LOGLEVEL("--target-stdout --all");

    std::string cmd_dev_str = "";
    std::string cmd_hmi_str = "";

    GCommandLineArgument<string> cmd_dev_arg("-xml-devices", "-xml-devices [base filename (without suffix)]", "Sets the xml files for devices", &cmd_dev_str, true, 0);
    GCommandLineArgument<string> cmd_hmi_arg("-xml-hmi", "-xml-hmi [base filename (without suffix) ]", "Sets the xml files for hmi", &cmd_hmi_str, true, 0);

    std::shared_ptr<GLogApplication> cmdline = std::make_shared<GLogApplication>();
    cmdline->InitLogArgs();
    cmdline->AddArgument(&cmd_dev_arg);
    cmdline->AddArgument(&cmd_hmi_arg);
    cmdline->ScanArguments(argc, (const char **)argv);

    XMLFile_t xml_dev = XMLFile_t(cmd_dev_str);
    XMLFile_t xml_hmi = XMLFile_t(cmd_hmi_str);
    XSDFile_t xsd_dev = KFGlobals::Instance()->GetXSDFilenameDevices();
    XSDFile_t xsd_hmi = KFGlobals::Instance()->GetXSDFilenameHmi();
    KFConfigurationHandler::Instance()->ParseConfigDevices(xml_dev, xsd_dev);
    KFConfigurationHandler::Instance()->ParseConfigHmi(xml_hmi, xsd_hmi);

    KFInterCom* pIntercom = KFInterCom::Instance();
    std::thread intercomThread = std::thread( &KFInterCom::StartIntercom, pIntercom,  eCOM_MODE::UDP, string("127.0.0.1"), 45500, 45500 );

    APIFSMController::Instance()->InitFSM();
    QApplication application(argc, argv);
    GUIInitStyles::Instance()->Init(&application);

    signal(SIGINT, signalHandler);
    std::atexit(exiting);

    try
    {
        USER_INFO("Initializing GUI, this will take ~2 seconds, please wait ....");
        application.setApplicationName("KF Horizontal robot");
        application.setOrganizationName("Kongsberg Ferrotech");

        GUIMainWindow window;
        window.show();

        int execResult = application.exec();
		exit(execResult);
    }
    catch (GException &e)
    {
        USER_ERROR("GException caught: %s", e.what() );
        exit(1);
    }
    catch (std::exception &e)
    {
        USER_ERROR("std::exception caught: %s", e.what() );
        exit(1);
    }
    catch (...)
    {
        USER_ERROR("unknown exception caught");
		exit(1);
    }

    exit(0);
}


