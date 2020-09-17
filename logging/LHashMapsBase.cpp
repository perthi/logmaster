
/***** Auto generated file: DO NOT EDIT !!!!!! *****/
/*** Generated at: Fri 28 August-2020 19:58:18  ***/
/*** Generated from config/logging-kts.xml **/
/*** Validated by config/logging.xsd **/
/*** Copyright Per Thomas Hille pth@embc.no ***/


#include "LHashMapsBase.h"
#include <utilities/GNumbers.h>
#include <utilities/GUtilities.h>


map < string, std::tuple< LOGMASTER::eMSGSYSTEM, LOGMASTER::eMSGLEVEL > >  LOGMASTER::LHashMapsBase::fSubCmdHash;
map < string, LOGMASTER::eMSGTARGET>	LOGMASTER::LHashMapsBase::fTargetHash = map < string, LOGMASTER::eMSGTARGET>();
map < string, LOGMASTER::eMSGFORMAT>	LOGMASTER::LHashMapsBase::fFormatHash;
map < LOGMASTER::eMSGSYSTEM, string >	LOGMASTER::LHashMapsBase::fSystem2StringHash = map < LOGMASTER::eMSGSYSTEM, string >();
map < LOGMASTER::eMSGLEVEL, string  >	LOGMASTER::LHashMapsBase::fLevel2StringHash = map < LOGMASTER::eMSGLEVEL, string  >();



namespace LOGMASTER
{
LHashMapsBase::LHashMapsBase( ) : fLogLevelHash(), fDefaultLevel(eMSGLEVEL::LOG_WARNING){}
LHashMapsBase::LHashMapsBase( const eMSGLEVEL  level) : fLogLevelHash(), fDefaultLevel( level ) {}
LHashMapsBase::~LHashMapsBase(){ }



/** @brief initialization of the hash table for the logginglevel     *     *  This hash table holds the current logging level for a given sub-system. This table is checked every time the logging system is asked to log a message, and if logging is enabled for the given level     *  and sub-system then the message is created. Where the message is actuall written (if at all) is decided by the target configuration, wether or not logging is enabled to to file, to console, etc..     *  @param l  All system are initialized with logging for this level or higher.  */
   void
   LHashMapsBase::InitHashLogLevel(const eMSGLEVEL /*l*/)
   {
	fLogLevelHash.clear();
//	eMSGLEVEL level = (eMSGLEVEL)(PAD((int)l));
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_EX,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_ERROR)  );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_FSM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_MESSAGE, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_COM, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_XML, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_DATABASE, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_JSON, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_SHOTCAL, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_SHOTEXCEC, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_CONFIGURATION, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_SENSOR, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_CLI, (eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
	fLogLevelHash.emplace(eMSGSYSTEM::SYS_NONE,(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );
   }
   void
   LHashMapsBase::InitHashSystem2String()
   {
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_EX,       "Exeption");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_GENERAL,  "General");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_USER,     "User");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_ALARM,    "Alarm");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_NONE,     "System Unknown");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_FSM, 	"Fsm");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_MESSAGE, 	"Message");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_COM, 	"Com");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_XML, 	"Xml");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_DATABASE, 	"Database");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_JSON, 	"Json");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_SHOTCAL, 	"Shotcal");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_SHOTEXCEC, 	"Shotexcec");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_CONFIGURATION, 	"Configuration");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_SENSOR, 	"Sensor");
	fSystem2StringHash.emplace(eMSGSYSTEM::SYS_CLI, 	"Cli");
   }
   void
   LHashMapsBase::InitHashLevel2String()
   {
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_OFF, "OFF");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_FORCE_DEBUG, "Force_Debug");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_FATAL,	"Fatal");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_ERROR,	"Error");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_WARNING,	"Warning");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_INFO,	"Info");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_DEBUG,	"Debug");
	fLevel2StringHash.emplace(eMSGLEVEL::LOG_ALL, "ALL loglevels");
   }
   void
   LHashMapsBase::InitHashLogTags()
   {
	fSubCmdHash.emplace("--fsm-off",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--fsm-fatal",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--fsm-error",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--fsm-warning",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--fsm-info",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--fsm-debug",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--fsm-all",		std::make_pair(eMSGSYSTEM::SYS_FSM,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--message-off",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--message-fatal",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--message-error",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--message-warning",	std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--message-info",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--message-debug",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--message-all",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--msg-off",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--msg-fatal",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--msg-error",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--msg-warning",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--msg-info",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--msg-debug",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--msg-all",		std::make_pair(eMSGSYSTEM::SYS_MESSAGE,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--communication-off",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--communication-fatal",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--communication-error",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--communication-warning",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--communication-info",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--communication-debug",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--communication-all",	std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--com-off",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--com-fatal",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--com-error",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--com-warning",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--com-info",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--com-debug",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--com-all",		std::make_pair(eMSGSYSTEM::SYS_COM,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--xml-off",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--xml-fatal",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--xml-error",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--xml-warning",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--xml-info",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--xml-debug",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--xml-all",		std::make_pair(eMSGSYSTEM::SYS_XML,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--database-off",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--database-fatal",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--database-error",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--database-warning",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--database-info",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--database-debug",	std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--database-all",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--db-off",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--db-fatal",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--db-error",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--db-warning",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--db-info",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--db-debug",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--db-all",		std::make_pair(eMSGSYSTEM::SYS_DATABASE,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--json-off",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--json-fatal",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--json-error",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--json-warning",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--json-info",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--json-debug",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--json-all",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--j-off",			std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--j-fatal",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--j-error",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--j-warning",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--j-info",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--j-debug",		std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--j-all",			std::make_pair(eMSGSYSTEM::SYS_JSON,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--shotcal-off",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--shotcal-fatal",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--shotcal-error",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--shotcal-warning",	std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--shotcal-info",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--shotcal-debug",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--shotcal-all",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--sc-off",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--sc-fatal",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--sc-error",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--sc-warning",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--sc-info",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--sc-debug",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--sc-all",		std::make_pair(eMSGSYSTEM::SYS_SHOTCAL,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--shotexe-off",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--shotexe-fatal",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--shotexe-error",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--shotexe-warning",	std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--shotexe-info",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--shotexe-debug",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--shotexe-all",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--se-off",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--se-fatal",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--se-error",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--se-warning",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--se-info",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--se-debug",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--se-all",		std::make_pair(eMSGSYSTEM::SYS_SHOTEXCEC,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--configuration-off",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--configuration-fatal",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--configuration-error",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--configuration-warning",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--configuration-info",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--configuration-debug",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--configuration-all",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_ALL));
	fSubCmdHash.emplace("--config-off",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--config-fatal",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--config-error",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--config-warning",	std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--config-info",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--config-debug",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--config-all",		std::make_pair(eMSGSYSTEM::SYS_CONFIGURATION,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--sensor-off",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--sensor-fatal",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--sensor-error",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--sensor-warning",	std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--sensor-info",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--sensor-debug",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--sensor-all",		std::make_pair(eMSGSYSTEM::SYS_SENSOR,  eMSGLEVEL::LOG_ALL));


	fSubCmdHash.emplace("--cli-off",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_OFF));
	fSubCmdHash.emplace("--cli-fatal",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_FATAL));
	fSubCmdHash.emplace("--cli-error",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_ERROR));
	fSubCmdHash.emplace("--cli-warning",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_WARNING));
	fSubCmdHash.emplace("--cli-info",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_INFO));
	fSubCmdHash.emplace("--cli-debug",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_DEBUG));
	fSubCmdHash.emplace("--cli-all",		std::make_pair(eMSGSYSTEM::SYS_CLI,  eMSGLEVEL::LOG_ALL));


   }
}
