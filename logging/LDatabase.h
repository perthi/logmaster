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
#include "LLogEntrySQL.h"

#include <memory>

#include <vector>
using std::vector;

struct  sqlite3;
struct  sqlite3_stmt;




namespace LOGMASTER
{
	struct LMessage;

	#define ALL_ENTRIES 0

	enum class eTIME_SEARCH_OPTION
	{
		EXACTLY = 1,
		INCLUDING_AND_ABOVE = 2,
		INCLUDING_AND_BELOW = 3,
	};

	class LDatabase
	{
		public:
			static  LDatabase API * Instance( const string db_path = "" );
 			void API AddLogEntry (  const std::shared_ptr< LMessage > msg, const string source  = "unkown");
			void API CloseDatabase();
			bool API OpenDatabase( const char *db_path );
 			bool API DeleteEntries();
			
			vector< LLogEntrySQL>  GetEntries( const string sql );
			vector< LLogEntrySQL>  GetEntries( const int max_cnt);
			vector< LLogEntrySQL>  GetEntries( const uint64_t time,  const eTIME_SEARCH_OPTION  opt, const int max_cnt);
			vector< LLogEntrySQL>  GetEntries( const  int time_min,        const int time_max,  const int max_cnt );
			vector< LLogEntrySQL>  GetEntries( const  eMSGSYSTEM sys,  const int max_cnt) ;
			vector< LLogEntrySQL>  GetEntries( const  eMSGLEVEL lvl,  const int max_cnt) ;
			vector< LLogEntrySQL>  GetEntries( const  eMSGLEVEL lvl,  const  eMSGSYSTEM sys,  const int max_cnt) ;



			bool API  InitSQLQuery(  const  int time,            const eTIME_SEARCH_OPTION opt,  const int max_cnt );
			bool API  InitSQLQuery(  const  int time_min,        const int time_max,  const int max_cnt );
			bool API  InitSQLQuery(  const  eMSGLEVEL level,     const int max_cnt );
			bool API  InitSQLQuery(  const  eMSGSYSTEM  system,  const int max_cnt  );
			bool API  InitSQLQuery(  const  eMSGLEVEL level,     const eMSGSYSTEM  system,  const int max_cnt  );
			bool API  InitSQLQuery(  const  int cnt  );
			bool API  InitSQLQuery(  const  string sql );
			bool API  ReadEntriesGetEntry(  LLogEntrySQL  &entry, const string sql = "", const int cnt = 0 );

		private:
			LDatabase( const string db_path );
			virtual ~LDatabase();
			
			vector< LLogEntrySQL> FetchAll(   ); 

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
