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

#include <stdio.h>
#include <string.h>

#include <utilities/GFileIOHandler.h>


#include <thread>
#include <chrono>

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
       // this->Start();
       // this->Detach();
    }

    LDatabase::~LDatabase()
    {

    }


//   double t = g_time()->GetEpochTime();
//     FORCE_DEBUG("Epoch time = %f", t );
//     time_t rawtime  = (long)t ;
//     struct tm *info;
//    // char buffer[80];
//     time( &rawtime );
//     info = localtime( &t );


    void
    LDatabase::AddLogEntry(const std::shared_ptr<LMessage> msg,  const string source  )
    {
        auto t =  msg->fEpochTime;
        time_t rawtime = (long)t;
        struct tm *info;
        time(&rawtime);
        info = localtime(&rawtime);

        int rc;
        static char sql[500];
        char *zErrMsg = 0;

      //  info->tm

        //std::shared_ptr<LogEntry> entry = std::static_pointer_cast<LogEntry>(data);

#ifndef WIN32
        snprintf(sql,  500, "INSERT INTO Logging (LoggingType, TimeStamp, Day, Month, Year, Source, Description) VALUES ('%s',%ju,%d,%d,%d,'%s','%s')",
#else
       sprintf_s(sql, "INSERT INTO Logging (LoggingType, TimeStamp, Day, Month, Year, Source, Description) VALUES ('%s',%I64d,%d,%d,%d,'%s','%s')",
#endif
                   msg->fMsgType,   (int64_t)msg->fEpochTime,  info->tm_wday, info->tm_mon,  info->tm_year + 1900,
                   source.c_str(), msg->fMsgBody );


        rc = sqlite3_exec(m_DataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            //printf("AddEntry SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }

        COUT << "Added Entry to DB" << endl;
    }

    bool
    LDatabase::DeleteEntries()
    {
        int rc;
        char sql[200];
        char *zErrMsg = 0;

       // sprintf_s(sql, "DELETE FROM Logging;");
        
        snprintf(sql, 200, "DELETE FROM Logging;");

        rc = sqlite3_exec(m_DataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            ///::LogError("Log", "DeleteEntries SQL error: %s", zErrMsg);
            CERR <<  "Log DeleteEntries SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
            return false;
        }
        return true;
    }


    bool
    LDatabase::OpenDatabase( const char *db_path  )
    {



        int rc;
        char *zErrMsg = 0;
        rc = sqlite3_open(db_path, &m_DataBase);

       // if( g_file()->DoExists( string( db_path ) );

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
        while (sqlite3_close( m_DataBase ) == SQLITE_BUSY)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }

        COUT << "Database was closed" << endl;
    }


} // namespace LOGMASTER
