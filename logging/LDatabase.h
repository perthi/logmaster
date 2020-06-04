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



/** @class  LOGMASTER::LDatabase 
 *  @brief   sqlite wrapper for writing and retrieving log messages from a SQL database
 *  @details The data base is very simple and contains just a single table holding the log message
 *  The message is written on a slightly different format than the original message. The table contain the following fields
 *
 *  field:        id           |  time            |   level              |  category   |  json
 *                ------------------------------------------------------------------------------- 
 *  type:         int64        |  int64           |   int                |  int        |  text	           
 *                -------------------------------------------------------------------------------  
 *  explanation   primary key  |  Unix epoch time |   The log level      |  Sub system |  The original message on json format 
 *                                                    debug, error etc..  |             |
 *                ------------------------------------------------------------------------------------------------------------ 
 *
 * The class contain a simple interface AddLogEntry() for writing a log message to the database, and several interfaces for retrieving them. 
 * The high level interfaces is  GetEntries(...) which return a vector of log entries matching the function argument(s)
 * 
 * As an alternative to calling GetEntries() one can use the low level interfaces InitSQLQuery(...) followed by subsequent calls to  
 * ReadEntriesGetEntry() until the  rows matching the SQL query is exhausted (that is, until ReadEntriesGetEntry() return false ). 
 * 
 * For the most part one should use the high level interfaces. The low level interfaces is useful however if the number
 * of log entries is large. It will reduce memory consumption since the messages are read one by one whereas the
 * high level interface returns all matching log entries in a single vector.
 * 
 * Furthermore, all that the high level interface does is to call the two low level interfaces  subsequently so that the high and
 * low level interfaces should yield  identical results. 
 * By default the database is called "logmaster.db" and is located in the same directory as where the executable invoking the database
 * was started. This location/name can be overridden by specifying another path the first time  LDatabase::Instance(const string db_path ) is called.
 * If the input argument is non empty then  "db_path" will be the new name of the DB. Please note that calling  LDatabase::Instance(const string db_path )
 * with an argument only have an effect the first time  LDatabase::Instance()  is called (and the database created), Subsequent calls with another argument
 * will not have any effect */

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
 			void API AddLogEntry (  const std::shared_ptr< LMessage > msg  );
			void API CloseDatabase();
			bool API OpenDatabase( const char *db_path );
 			bool API DeleteEntries();
			
			vector< LLogEntrySQL>  Query( const string sql );
			vector< LLogEntrySQL>  Query( const int max_cnt);
			vector< LLogEntrySQL>  Query( const uint64_t time,  const eTIME_SEARCH_OPTION  opt, const int max_cnt);
			vector< LLogEntrySQL>  Query( const  int time_min,        const int time_max,  const int max_cnt );
			vector< LLogEntrySQL>  Query( const  eMSGSYSTEM sys,  const int max_cnt) ;
			vector< LLogEntrySQL>  Query( const  eMSGLEVEL lvl,  const int max_cnt) ;
			vector< LLogEntrySQL>  Query( const  eMSGLEVEL lvl,  const  eMSGSYSTEM sys,  const int max_cnt) ;



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
