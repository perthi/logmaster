// -*- mode: c++ -*-
/**************************************************************************
 * This file is property of and copyright by Embedded Cosnulting  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/

#include "LDatabase.h"
#include "LMessage.h"

#include "sqlite/sqlite3.h"

namespace LOGMASTER
{

    LDatabase  * 
    LDatabase::Instance( const string path )
    {

        static LDatabase *instance = new LDatabase( path );
        return instance;
    }
    
    
    LDatabase::LDatabase( const string path )
    {
        if(  path != "" )
        {
            fDBPath = path;
        }

        OpenDatabase( fDBPath.c_str()  );
    }

    LDatabase::~LDatabase()
    {

    }

    void 
    LDatabase::Log(  const  std::shared_ptr< LMessage > /*msg*/ )
    {
        CERR << "Logging to DB is not implemented" << endl;
    }

    bool
    LDatabase::OpenDatabase( const char *db_path  )
    {
        int rc;
        char *zErrMsg = 0;
        rc = sqlite3_open(db_path, &m_DataBase);

        if (rc)
        {
            printf("%s line %d, Can't open database: %s\n", __FILE__, __LINE__, sqlite3_errmsg(m_DataBase));
            return false;
        }
        else
        {
            // Define logging table
            const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS Logging ( "
                                     "LoggingID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                     "LoggingType TEXT, "
                                     "TimeStamp INTEGER, "
                                     "Day INTEGER, "
                                     "Month INTEGER, "
                                     "Year INTEGER, "
                                     "Source TEXT, "
                                     "Description TEXT );";

            // Create logging table
            rc = sqlite3_exec(m_DataBase, LoggingSQL, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK)
            {
                printf("OpenDatabase SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return false;
            }
            return true;
        }
    }

    void 
    LDatabase::CloseDatabase()
    {

    }


} // namespace LOGMASTER
