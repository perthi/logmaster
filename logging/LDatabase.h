// -*- mode: c++ -*-
#ifndef LDATABASE_H
#define LDATABASE_H
/**************************************************************************
 * This file is property of and copyright by Embedded Cosnulting  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/

#include <utilities/GDefinitions.h>
#include <logging/LEnums.h>

#include <memory>



struct  sqlite3;
struct  sqlite3_stmt;


namespace LOGMASTER
{
	struct LMessage;

	// class LogEntry
	// {
	// public:
	// 	std::uint32_t LoggingID = 0;
	// 	std::string LoggingType = "";
	// 	std::uint64_t TimeStamp = 0;
	// 	std::uint32_t Day = 0;
	// 	std::uint32_t Month = 0;
	// 	std::uint32_t Year = 0;
	// 	std::string Source = "";
	// 	std::string Description = "";
	// };


	class LogEntry
	{
	public:
		std::uint32_t m_id = 0;
		std::uint32_t  m_level = 0;
		std::uint32_t  m_category = 0;
		double        m_time = 0;
		std::string   m_json = "";
	};


	class LDatabase
	{
		public:
			static  LDatabase API * Instance( const string db_path = "" );
 			void API AddLogEntry (  const std::shared_ptr< LMessage > msg, const string source  = "unkown");
			void API CloseDatabase();
			bool API OpenDatabase( const char *db_path );
 			bool API DeleteEntries();
   //			bool API ReadEntriesPrepare(std::string LoggingTypes, std::uint32_t Count);
 			
			bool API  InitSQLQuery( const  eMSGLEVEL level, const int cnt = 0 );
			bool API  InitSQLQuery( const  eMSGSYSTEM  system, int cnt = 0 );
			bool API  InitSQLQuery( const  eMSGLEVEL level, const eMSGSYSTEM  system, int cnt  = 0);
			bool API  InitSQLQuery( const int cnt  = 0 );

			bool API ReadEntriesGetEntry( std::shared_ptr<LogEntry>  entry  );

		private:
			LDatabase( const string db_path );
			virtual ~LDatabase();
			
			LDatabase( const LDatabase & );
			LDatabase operator = ( const LDatabase & );
			
			bool InitQuery( string query, const int limit  );
			string LimitString( const int cnt );
			///void SetDatabasePath();
		
			sqlite3       *m_DataBase  =  nullptr; 
        	sqlite3_stmt  *m_stmt     =   nullptr;  // SQLite statmement 

			string  fDBPath = "logmaster.db";


	};

} // namespace LOGMASTER

#endif
