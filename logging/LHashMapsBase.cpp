
/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 03 September-2021 20:56:58  ***/
/*** Generated from config/logging-ucw.xml **/
/*** Validated by config/logging.xsd **/
/*** Copyright Per Thomas Hille pth@embc.no ***/


#include "LHashMapsBase.h"
#include <utilities/GNumbers.h>
#include <utilities/GUtilities.h>



namespace LOGMASTER
{
LHashMapsBase::LHashMapsBase( ) : fLogLevelHash() {}
LHashMapsBase::~LHashMapsBase(){ }






/** @brief initialization of the hash table for the logginglevel     *     *  This hash table holds the current logging level for a given sub-system.     *  This table is checked every time the logging system is asked to log a message, and if logging     *  is enabled for the given level and sub-system then the message is created.     *  Where the message is actuall written (if at all) is decided by the target configuration,    *  wether or not logging is enabled to to file, to console, etc.. */
   void
   LHashMapsBase::InitHashLogLevel( )
   {
    fLogLevelHash.clear();
//    eMSGLEVEL level = (eMSGLEVEL)(PAD((int)l));
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_EX,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_ERROR)  );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_DATABASE, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_FSM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_COM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_XML, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_CLI, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_MEASUREMENT, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_HMI, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_FOC, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_MCUREPLY, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
    fLogLevelHash.emplace(eMSGSYSTEM::SYS_NONE,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
   }



   void
   LHashMapsBase::InitHashSystem2String( map<eMSGSYSTEM, string>  *System2StringHash )
   {
    System2StringHash->emplace(eMSGSYSTEM::SYS_EX,       "Exception");
    System2StringHash->emplace(eMSGSYSTEM::SYS_GENERAL,  "General");
    System2StringHash->emplace(eMSGSYSTEM::SYS_USER,     "User");
    System2StringHash->emplace(eMSGSYSTEM::SYS_ALARM,    "Alarm");
    System2StringHash->emplace(eMSGSYSTEM::SYS_NONE,     "System Unknown");
    System2StringHash->emplace(eMSGSYSTEM::SYS_DATABASE,     "Database");
    System2StringHash->emplace(eMSGSYSTEM::SYS_FSM,     "Fsm");
    System2StringHash->emplace(eMSGSYSTEM::SYS_COM,     "Com");
    System2StringHash->emplace(eMSGSYSTEM::SYS_XML,     "Xml");
    System2StringHash->emplace(eMSGSYSTEM::SYS_CLI,     "Cli");
    System2StringHash->emplace(eMSGSYSTEM::SYS_MEASUREMENT,     "Measurement");
    System2StringHash->emplace(eMSGSYSTEM::SYS_HMI,     "Hmi");
    System2StringHash->emplace(eMSGSYSTEM::SYS_FOC,     "Foc");
    System2StringHash->emplace(eMSGSYSTEM::SYS_MCUREPLY,     "Mcureply");
   }



   void
   LHashMapsBase::InitHashLevel2String(  map<eMSGLEVEL, string> *Level2StringHash  )
   {
    Level2StringHash->emplace(eMSGLEVEL::LOG_OFF, "OFF");
    Level2StringHash->emplace(eMSGLEVEL::LOG_FORCE_DEBUG, "Force_Debug");
    Level2StringHash->emplace(eMSGLEVEL::LOG_FATAL,    "Fatal");
    Level2StringHash->emplace(eMSGLEVEL::LOG_ERROR,    "Error");
    Level2StringHash->emplace(eMSGLEVEL::LOG_WARNING,    "Warning");
    Level2StringHash->emplace(eMSGLEVEL::LOG_INFO,    "Info");
    Level2StringHash->emplace(eMSGLEVEL::LOG_DEBUG,    "Debug");
    Level2StringHash->emplace(eMSGLEVEL::LOG_ALL, "ALL loglevels");
   }



   void
   LHashMapsBase::InitHashLogTags(  map<string, std::tuple<eMSGSYSTEM, eMSGLEVEL>>  *SubCmdHash   )
   {
    SubCmdHash->emplace("--database-off",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--database-fatal",    std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--database-error",    std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--database-warning",    std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--database-info",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--database-debug",    std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--database-all",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ALL));
    SubCmdHash->emplace("--db-off",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--db-fatal",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--db-error",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--db-warning",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--db-info",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--db-debug",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--db-all",        std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--fsm-off",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--fsm-fatal",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--fsm-error",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--fsm-warning",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--fsm-info",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--fsm-debug",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--fsm-all",        std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--communication-off",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--communication-fatal",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--communication-error",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--communication-warning",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--communication-info",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--communication-debug",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--communication-all",    std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ALL));
    SubCmdHash->emplace("--com-off",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--com-fatal",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--com-error",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--com-warning",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--com-info",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--com-debug",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--com-all",        std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--xml-off",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--xml-fatal",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--xml-error",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--xml-warning",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--xml-info",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--xml-debug",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--xml-all",        std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--cli-off",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--cli-fatal",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--cli-error",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--cli-warning",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--cli-info",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--cli-debug",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--cli-all",        std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--measurement-off",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--measurement-fatal",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--measurement-error",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--measurement-warning",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--measurement-info",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--measurement-debug",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--measurement-all",    std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_ALL));
    SubCmdHash->emplace("--meas-off",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--meas-fatal",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--meas-error",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--meas-warning",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--meas-info",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--meas-debug",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--meas-all",        std::make_pair(eMSGSYSTEM::SYS_MEASUREMENT,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--hmi-off",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--hmi-fatal",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--hmi-error",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--hmi-warning",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--hmi-info",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--hmi-debug",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--hmi-all",        std::make_pair(eMSGSYSTEM::SYS_HMI,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--foc-off",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--foc-fatal",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--foc-error",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--foc-warning",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--foc-info",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--foc-debug",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--foc-all",        std::make_pair(eMSGSYSTEM::SYS_FOC,  eMSGLEVEL::LOG_ALL));


    SubCmdHash->emplace("--mcu-off",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_OFF));
    SubCmdHash->emplace("--mcu-fatal",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_FATAL));
    SubCmdHash->emplace("--mcu-error",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_ERROR));
    SubCmdHash->emplace("--mcu-warning",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_WARNING));
    SubCmdHash->emplace("--mcu-info",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_INFO));
    SubCmdHash->emplace("--mcu-debug",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_DEBUG));
    SubCmdHash->emplace("--mcu-all",        std::make_pair(eMSGSYSTEM::SYS_MCUREPLY,  eMSGLEVEL::LOG_ALL));


   }
}
