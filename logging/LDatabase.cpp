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
#include "LMessage2Json.h"

#include "sqlite/sqlite3.h"

#include  <json/json.hpp>

#include <stdio.h>
#include <string.h>

#include <utilities/GFileIOHandler.h>
#include "LMessage2Json.h"

#include <thread>
#include <chrono>

#include <sstream>

#if defined(_WIN32) || defined(_WIN64)
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#endif


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
    LDatabase::AddLogEntry(const std::shared_ptr<LMessage> msg,  const string /*source*/  )
    {
        // auto t =  msg->fEpochTime;
        // time_t rawtime = (long)t;
        // struct tm *info;
        // time(&rawtime);
        // info = localtime(&rawtime);

        int rc;
        static char sql[1000];
        char *zErrMsg = 0;

 // const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS t_logging ( "
    //                                  "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
    //                                  "time FLOAT(53), "
    //                                  "level INTEGER, "
    //                                  "category INTEGER,"
    //                                  "json TEXT );";



// #ifndef WIN32
//         snprintf(sql,  500, "INSERT INTO Logging (LoggingType, TimeStamp, Day, Month, Year, Source, Description) VALUES ('%s',%ju,%d,%d,%d,'%s','%s')",
// #else
//        sprintf_s(sql, "INSERT INTO Logging (LoggingType, TimeStamp, Day, Month, Year, Source, Description) VALUES ('%s',%I64d,%d,%d,%d,'%s','%s')",
// #endif
//                    msg->fMsgType,   (int64_t)msg->fEpochTime,  info->tm_wday, info->tm_mon,  info->tm_year + 1900,
//                    source.c_str(), msg->fMsgBody );

    //#include "LMessage2Json.h"



        nlohmann::json j;
        LMessage2Json::Message2Json( msg, j );
     //      CERR << "TP0" << endl;
       // std::string j_s = ""; 
       // j >> j_s ;


        std::stringstream buffer;
        buffer << j;

       // string j_s = buffer.str();


    //     CERR << "TP1" << endl;
    //     CERR << "JSON = " << buffer.str() << endl;
    //  CERR << "TP2" << endl;

#ifndef WIN32
        snprintf(sql, 1000, "INSERT INTO t_logging (time, level, category, json ) VALUES ('%f',%d, %d,'%s')",
#else
    ///   sprintf_s(sql, "INSERT INTO Logging (LoggingType, TimeStamp, Day, Month, Year, Source, Description) VALUES ('%s',%I64d,%d,%d,%d,'%s','%s')",
       snprintf_s(sql, "INSERT INTO  t_logging (time, level, category, json ) VALUES ('%f',%d, %d,'%s')",
#endif
                   msg->fEpochTime, (int)msg->fLevel,  (int)msg->fSystem, 
                   buffer.str().c_str() );


        rc = sqlite3_exec(m_DataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            printf("AddEntry SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }

    }

    bool
    LDatabase::DeleteEntries()
    {
        int rc;
        char sql[200];
        char *zErrMsg = 0;
       // sprintf_s(sql, "DELETE FROM Logging;");
        snprintf(sql, 200, "DELETE FROM t_logging;");

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

    bool API 
    LDatabase::ReadEntriesPrepare( const eMSGLEVEL level, int cnt )
    {
        std::stringstream buffer;
        buffer <<  "SELECT * FROM t_logging WHERE level = " << (int)level << " ORDER BY id DESC  LIMIT " << cnt ;
        string SqlString = buffer.str();

        int rc = sqlite3_prepare(m_DataBase, SqlString.c_str(), SqlString.length(), &m_stmt, nullptr);
        
        if (rc != SQLITE_OK)
        {
          //  ::LogError("Log", "ReadEntriesPrepare SQL error: %s", sqlite3_errmsg( m_DataBase ));
            COUT << "Log ReadEntriesPrepare SQL error: " << sqlite3_errmsg( m_DataBase ) << endl;
            return false;
        }
        else
        {
            return true;
        }
        

    }


/*
    bool  
    LDatabase::ReadEntriesPrepare(std::string LoggingTypes, uint32_t Count)
    {
        int rc;
        std::string Delimiter = ",", SqlString, WhereString;
        size_t Last = 0, Next = 0;
        bool FirstTime = true;
        std::stringstream  IntStr;

        SqlString = "SELECT * FROM t_logging ";
        WhereString = "";
        if (LoggingTypes.length() > 0)
        {
            while ((Next = LoggingTypes.find(Delimiter, Last)) != std::string::npos)
            {
                if (FirstTime)
                {
                    WhereString += "WHERE ";
                    FirstTime = false;
                }
                else
                {
                    WhereString += " OR ";
                    WhereString += " LoggingType='";
                    WhereString += LoggingTypes.substr(Last, Next - Last);
                    WhereString += "'";
                    Last = Next + 1;
                }
            }
            if (FirstTime)
            {
                WhereString = "WHERE LoggingType='";
                WhereString += LoggingTypes.substr(Last);
                WhereString += "'";
            }
            else
            {
                WhereString += " OR LoggingType='";
                WhereString += LoggingTypes.substr(Last, Next - Last);
                WhereString += "'";
            }
        }

        SqlString += WhereString;
        SqlString += " ORDER BY LoggingID DESC ";
        
        if (Count > 0)
        {
            SqlString += " LIMIT ";
            IntStr << Count;
            SqlString += IntStr.str();
        }

        rc = sqlite3_prepare(m_DataBase, SqlString.c_str(), SqlString.length(), &m_stmt, nullptr);
        
        if (rc != SQLITE_OK)
        {
          //  ::LogError("Log", "ReadEntriesPrepare SQL error: %s", sqlite3_errmsg( m_DataBase ));
            COUT << "Log ReadEntriesPrepare SQL error: " << sqlite3_errmsg( m_DataBase ) << endl;
            return false;
        }
        return true;
    }
*/




    // const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS t_logging ( "
    //                                  "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
    //                                  "time FLOAT(53), "
    //                                  "level INTEGER, "
    //                                  "category INTEGER,"
    //                                  "json TEXT );";

    bool
    LDatabase::ReadEntriesGetEntry(std::shared_ptr<LogEntry> entry)
    {
        int rc;
        do
        {
            rc = sqlite3_step(m_stmt);

        } while ((rc != SQLITE_DONE) && (rc != SQLITE_ROW) && (rc != SQLITE_ERROR));

        if (rc == SQLITE_ROW)
        {
            int ColumnCount = sqlite3_column_count(m_stmt);
            for (int i = 0; i < ColumnCount; i++)
            {
                if (strcasecmp(sqlite3_column_name(m_stmt, i), "id") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER)
                    {
                        entry->m_id = sqlite3_column_int(m_stmt, i);
                    }

                    else
                     {
                        printf("Log: ReadEntriesGetEntry Incorrect Type \"id\"\n");
                     }   
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "time") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_FLOAT)
                    {
                        entry->m_time = (sqlite3_column_double( m_stmt, i));
                    }
                    else
                    {
                        printf("Log: ReadEntriesGetEntry Incorrect Type \"time\"\n");
                    }
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "level") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER)
                    {
                        entry->m_level = sqlite3_column_int( m_stmt, i);
                    }
                    else
                    {
                        printf("Log: ReadEntriesGetEntry Incorrect Type \"level\"\n");
                    }
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "category") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER)
                    {
                        entry->m_category = sqlite3_column_int( m_stmt, i);
                    }
                    else
                    {
                        printf("Log: ReadEntriesGetEntry Incorrect Type \"category\"\n");
                    }
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "json") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_TEXT)
                    {
                        entry->m_json = std::string(reinterpret_cast<const char *>(sqlite3_column_text(m_stmt, i)));
                    }
                    else
                    {
                        printf("Log: ReadEntriesGetEntry Incorrect Type \"json\"\n");
                    }
                }
            }
            return true;
        }
        else
        {
            sqlite3_finalize(m_stmt);
            return false;
        }
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
            // const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS Logging ( "
            //                          "LoggingID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
            //                          "LoggingType TEXT, "
            //                          "TimeStamp INTEGER, "
            //                          "Day INTEGER, "
            //                          "Month INTEGER, "
            //                          "Year INTEGER, "
            //                          "Source TEXT, "
            //                          "Description TEXT );";

              const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS t_logging ( "
                                     "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                     "time FLOAT(53), "
                                     "level INTEGER, "
                                     "category INTEGER,"
                                     "json TEXT );";

            
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
        int cnt = 0;
        while (sqlite3_close( m_DataBase ) == SQLITE_BUSY)
        {
            COUT << "database is busy, cnt = " << cnt << endl;
            cnt ++;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        COUT << "Database was closed" << endl;
    }


} // namespace LOGMASTER
