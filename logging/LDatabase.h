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

#include <memory>



struct  sqlite3;
struct  sqlite3_stmt;


namespace LOGMASTER
{
	class LMessage;

	class LDatabase
	{
		public:
			static  LDatabase API * Instance( const string db_path = "" );
 			void AddLogEntry (  const std::shared_ptr< LMessage > msg, const string source  = "unkown");
			///void SetDatabasePath( const string path );
			void CloseDatabase();
			bool OpenDatabase( const char *db_path );
 			bool DeleteEntries();

		private:
			LDatabase( const string db_path );
			virtual ~LDatabase();
			
			LDatabase( const LDatabase & );
			LDatabase operator = ( const LDatabase & );
			
			///void SetDatabasePath();
		
			sqlite3       *m_DataBase  =  nullptr; 
        	sqlite3_stmt  *m_stmt     =   nullptr;  // SQLite statmement 

			string  fDBPath = "logmaster.db";

	};

} // namespace LOGMASTER

#endif
