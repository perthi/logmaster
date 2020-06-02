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
    }


    LDatabase::~LDatabase()
    {

    }


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
     LDatabase::ReadEntriesPrepare(std::string LoggingTypes, uint32_t Count)
    {
        int rc;
        std::string Delimiter = ",", SqlString, WhereString;
        size_t Last = 0, Next = 0;
        bool FirstTime = true;
        std::stringstream  IntStr;

        SqlString = "SELECT * FROM Logging ";
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
                    WhereString += " OR ";
                WhereString += " LoggingType='";
                WhereString += LoggingTypes.substr(Last, Next - Last);
                WhereString += "'";
                Last = Next + 1;
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


	bool 
    LDatabase::ReadEntriesGetEntry( std::shared_ptr<LogEntry>  entry )
    {
        int rc;
       do
       {
            rc = sqlite3_step( m_stmt );

       } while ((rc != SQLITE_DONE) && (rc != SQLITE_ROW) && (rc != SQLITE_ERROR));

        if (rc == SQLITE_ROW)
        {
            int ColumnCount = sqlite3_column_count( m_stmt);
            for (int i = 0; i < ColumnCount; i++)
            {
                if (strcasecmp(sqlite3_column_name( m_stmt, i), "LoggingID") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_INTEGER)
                        entry->LoggingID = sqlite3_column_int( m_stmt, i);
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type LoggingID\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "LoggingType") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_TEXT )
                        entry->LoggingType = std::string(reinterpret_cast<const char*>(sqlite3_column_text( m_stmt, i)));
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type LoggingType\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "TimeStamp") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_INTEGER)
                        entry->TimeStamp = sqlite3_column_int( m_stmt, i);
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type TimeStamp\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "Day") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_INTEGER)
                        entry->Day = sqlite3_column_int( m_stmt, i);
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type Day\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "Month") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_INTEGER)
                        entry->Month = sqlite3_column_int( m_stmt, i);
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type Month\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "Year") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_INTEGER)
                        entry->Year = sqlite3_column_int( m_stmt, i);
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type Year\n");
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "Source") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_TEXT)
                        entry->Source = std::string(reinterpret_cast<const char*>(sqlite3_column_text( m_stmt, i)));
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type Source\n");
                }
                else if (strcasecmp(sqlite3_column_name( m_stmt, i), "Description") == 0)
                {
                    if (sqlite3_column_type( m_stmt, i) == SQLITE_TEXT)
                        entry->Description = std::string(reinterpret_cast<const char*>(sqlite3_column_text( m_stmt, i)));
                    else
                        printf("Log: ReadEntriesGetEntry Incorrect Type Description\n");
                }
            }
            return true;
        }
        else
        {
            sqlite3_finalize( m_stmt );
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
