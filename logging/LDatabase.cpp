// -*- mode: c++ -*-
/**************************************************************************
 * This file is property of and copyright by Embedded Consulting'  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/


#include  "LDatabase.h"
#include  "LMessage.h"
#include  "LMessage2Json.h"
#include  "LEnums.h"
#include  "LLogEntrySQL.h"


#include  "GException.h"
#include  <utilities/GDefinitions.h>
#include "sqlite/sqlite3.h"
#include "../json/LJson.hpp"
#include  <utilities/GCommon.h>
#include  <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <string.h>

namespace LOGMASTER
{
    LDatabase *LDatabase::fgInstance = nullptr;
    string    LDatabase::fDBPath = "logmaster.db";


    /** Singleton instance of the database
     *  @param[in] path The full path to the base, if empty then
     *  The default path is used  ( "logmaster.db" ) in the current directory
     *  @return The database singleton */
    LDatabase  * 
    LDatabase::Instance( const  string  path  )
    {
        if( path != "" )
        {
           SetDatabase(path); 
        }
        if( fgInstance == nullptr  )
        {
            fgInstance = new LDatabase( );
        }
        return  fgInstance;
    }


    LDatabase::LDatabase(  ) : fMessage2Json()
    {
        OpenDatabase( fDBPath.c_str()  );
    }


    void 
    LDatabase::SetDatabaseDefault(    )
    {
        SetDatabase( "logmaster.db");
    }




    void 
    LDatabase::SetDatabase(  const  string  db_path  )
    {
        if( db_path != "" )
        {
            fDBPath =  db_path;
        }
        if( fgInstance != nullptr )
        {
           delete  fgInstance;
           fgInstance = nullptr;
        }
        fgInstance = new LDatabase(   );
    }


    /** @brief Writ a log entry to the database
     *  @param[in] msg a log message as produced by the logging system */
    void
    LDatabase::AddLogEntry( std::shared_ptr<LMessage>  msg  )
    {
        if(fMaxDbFileSize)
        {
            FILE *p_file = NULL;
            p_file = fopen(fDBPath.c_str(),"rb");
            fseek(p_file,0,SEEK_END);
            auto fileSize = ftell(p_file);
            fclose(p_file);
            if(fileSize > fMaxDbFileSize)
            {
                char *zErrMsg = 0;
                const char *sql = "REPLACE INTO t_triggerControl (name, enabled) VALUES ('delete_old', 1)";
                int rc = sqlite3_exec(fDataBase, sql, NULL, 0, &zErrMsg);
                if (rc != SQLITE_OK)
                {
#ifdef HAS_LOGGING
                    HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
                    HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif

                    sqlite3_free(zErrMsg);
                }
                fMaxDbFileSize = fileSize;
            }
        }
        int rc;
        static char sql[1000];
        char *zErrMsg = 0;
        nlohmann::json j;
        fMessage2Json.Message2Json(msg, j);
        std::string jsonStr = JsonToString(j);

/** @todo epoch time should be storeD as a FLOAT*/
#ifndef WIN32
        snprintf(sql, 1000, "INSERT INTO t_logging (time_int, time_float, level, category, json ) VALUES ('%d', %d, %d, %d,'%s')",
#else
       sprintf_s(sql, 1000, "INSERT INTO t_logging (time_int, time_float, level, category, json ) VALUES ('%d', %d, %d, %d,'%s')",
#endif
                   (int)msg->fEpochTime,  (int)msg->fEpochTime, (int)msg->fLevel,  (int)msg->fSystem, 
                   jsonStr.c_str() );

        rc = sqlite3_exec(fDataBase, sql, NULL, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
         //   HandleError( GLOCATION, eMSGLEVEL::LOG_ERROR, "AddEntry SQL error: %s", zErrMsg );
            printf("ERROR %s:%dAddEntry (msg to log = %s) SQL error: %s\n", __FILE__, __LINE__,   msg->fMsgBody,  zErrMsg );
            sqlite3_free(zErrMsg);
        }
    }



    /** @brief  Delete all log entries from the database 
     *  @return true if the deletion was successful, false othervise */
    bool
    LDatabase::DeleteEntries()
    {
        return GDataBaseIF::DeleteEntries(  string("t_logging")  );
    }


    /** @brief   Fetch all log entries that matches the SQL query
     *  @details On of the InitSQLQuery() functions must be called first
     *  @return a vector of log entries matching the sql query which was previously 
     *  initialized with  InitSQLQuery(..) */
    vector< LLogEntrySQL> 
    LDatabase::FetchAll(   )
    {
        std::vector< LLogEntrySQL >  msg_v;
        LLogEntrySQL msg;
        while(  ( LDatabase::Instance()->ReadEntriesGetEntry( msg ) == true )   ) 
        {
            msg_v.push_back( msg );
        }
        return  msg_v;
    } 



    /** @name Querey
    * @brief   Query the database
    * @details Query the database for all entries matching the search criteria. These functions comprises the high level interface.
    * The query is performed in two steps. First
    * @param[in] sql SQL search expression
    * @param[in] time Unix epoch time
    * @param[in] time_min Unix epoch time
    * @param[in] time_max Unix epoch time
    * @param[in] opt  For time search this specfifes wether to return 
    * log entries with either larger, lower or equal time stamp than "time"
    * @param[in] max_cnt The maximum number of entries to return
    * @param[in] sy  subsystem/category ( return the messages matching sub system )
    * @param[in] lvl subsystem/category ( return the messages for a given log level )
    @return vector of log entries matching the search criteria */
    /**@{ */
     /** Queries the database using a user defined SQL query string */   
    vector<  LLogEntrySQL >  
    LDatabase::Query( const string sql )
    {
        InitSQLQuery(sql  );
        return FetchAll();
    }

    /** Retiurn all log entries from the dtabase without any filter. max_cnt represnts the */   
    vector<  LLogEntrySQL >  
    LDatabase::Query(const int max_cnt )
    {
        InitSQLQuery( max_cnt  );
        return FetchAll();
    }

  
    /** Returns all log entries matching a given time stamp (time). The time si Unix epoch time with
     * a resolution of seconds. 
     *  The search option "opt" search option  can be one of the follwing 
     *    -  eTIME_SEARCH_OPTION::EXACTLY Return enties that matches "time" exactly.
     *    -  eTIME_SEARCH_OPTION::INCLUDING_AND_ABOVE Return entries that are newer than "time" 
     *    -  eTIME_SEARCH_OPTION::INCLUDING_AND_BELOW Return entries that are older than "time" 
     * */
    vector<  LLogEntrySQL >  
    LDatabase::Query(  const uint64_t time, const eTIME_SEARCH_OPTION  opt, const int max_cnt )
    {
        InitSQLQuery(time, opt, max_cnt);
        return FetchAll();
    }

    /** Return entries with a timestamp that is newer or equal to time_min and older or equla to time_min*/ 
    vector<  LLogEntrySQL >  
    LDatabase::Query( const  uint64_t time_min, const int time_max,  const int max_cnt )
    {
        InitSQLQuery(  time_min, time_max, max_cnt );
        return FetchAll();
    }


    vector<  LLogEntrySQL >  
    LDatabase::Query( const  eMSGSYSTEM sys,  const int max_cnt ) 
    {
        InitSQLQuery(sys, max_cnt);
        return FetchAll();
    }

    vector<  LLogEntrySQL >  
    LDatabase::Query( const  eMSGLEVEL lvl,  const int max_cnt  )  
    {
        InitSQLQuery(lvl, max_cnt);
        return FetchAll();

    }

    /** Function 6 in group 2. Details. */    
    vector< LLogEntrySQL >  
    LDatabase::Query( const  eMSGLEVEL lvl,  const  eMSGSYSTEM sys, const int max_cnt  )
    {
        InitSQLQuery(lvl, sys, max_cnt);
        return FetchAll();
    }
/**@}*/



    /** @name  InitSQLQuery
    * @brief   Generates a SQL search string based on the input parameters
    * @details Query the database for all entries matching the search criteria. These functions comprises the high level interface.
    * The query is performed in two steps. First
    * @param[in] sql SQL search expression
    * @param[in] time Unix epoch time
    * @param[in] time_min Unix epoch time
    * @param[in] time_max Unix epoch time
    * @param[in] opt  For time search this specfifes wether to return 
    * log entries with either larger, lower or equal time stamp than "time"
    * @param[in] max_cnt The maximum number of entries to return
    * @param[in] sy  subsystem/category ( return the messages matching sub system )
    * @param[in] lvl subsystem/category ( return the messages for a given log level )
    @return true if a valid SQL search string could be generated, false othervise */
 /**@{ */
    bool  
    LDatabase::InitSQLQuery( const eMSGLEVEL level,  const int max_cnt )
    {
        std::stringstream buffer;
        buffer <<  "SELECT * FROM t_logging WHERE level = " << (int)level << " ORDER BY id DESC";
        return InitQuery( buffer.str(), max_cnt );
    }


  
    bool  
    LDatabase::InitSQLQuery( const eMSGSYSTEM  system,  const int max_cnt )
    {
        std::stringstream buffer;
         buffer <<  "SELECT * FROM t_logging WHERE category = " << (int)system << " ORDER BY id DESC"; 
        return InitQuery( buffer.str(), max_cnt );
    }


    bool  
    LDatabase::InitSQLQuery(  const eMSGLEVEL level,  const eMSGSYSTEM  system, const int max_cnt )
    {
        std::stringstream buffer;
        buffer <<  "SELECT * FROM t_logging WHERE category = " << (int)system << " AND level = " <<  (int)level << " ORDER BY id DESC";
        return InitQuery( buffer.str(), max_cnt );
    }


    bool 
    LDatabase::InitSQLQuery(  const int max_cnt )
    {
        std::stringstream buffer;
        buffer <<  "SELECT * FROM t_logging  ORDER BY id DESC";
        return InitQuery( buffer.str(), max_cnt );
    }
   


    bool 
    LDatabase::InitSQLQuery(  const string sql )
    {
        return InitQuery( sql, 0 );
    }


    bool
    LDatabase::InitQuery( string sql_query,  const int limit  )
    {
        if( fDataBase == nullptr )
        {
#ifdef HAS_LOGGING
            HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "fDataBase  = NULLPTR !!!! " );   
#else
            HandleError(GLOCATION, DISABLE_EXCEPTION, "fDataBase  = NULLPTR !!!! ");
#endif

            return false;
        }

        if(limit > 0)
        {
          sql_query += LimitString(limit);  
        }

        
        const char **test = 0;
        int rc = sqlite3_prepare(fDataBase, sql_query.c_str(), (int)sql_query.length(), &fStmt, nullptr);    

        if (rc != SQLITE_OK)
        {
#ifdef HAS_LOGGING
            HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION, "SQL error: %s", sqlite3_errmsg(fDataBase));   
#else
            HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", sqlite3_errmsg(fDataBase));
#endif

            return false;
        }
        else
        {
            return true;
        }
    }

    bool LDatabase::DeleteOldestEntries(int nEntries)
    {
        int rc;
        char sql[200];
        char *zErrMsg = 0;
        snprintf(sql, 200, "DELETE FROM t_logging WHERE id IN (SELECT id FROM t_logging ORDER BY id ASC LIMIT %d);", nEntries );

        rc = sqlite3_exec(fDataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
#ifdef HAS_LOGGING
            HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION, "Could not delete old entries: SQL error: %s", sqlite3_errmsg(fDataBase) );
#else
            HandleError(GLOCATION, DISABLE_EXCEPTION, "Could not delete old entries: SQL error: %s", sqlite3_errmsg(fDataBase));

#endif
            
            return false;
        }
        else
        {
            return true;
        }

    }

    

    bool
    LDatabase::InitSQLQuery(const uint64_t time, const eTIME_SEARCH_OPTION opt, const int max_cnt )
    {
        std::stringstream buffer;

        switch (opt)
        {
        case eTIME_SEARCH_OPTION::EXACTLY:
            buffer <<  "SELECT * FROM t_logging WHERE time_int = " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), max_cnt );
            break;
        case eTIME_SEARCH_OPTION::INCLUDING_AND_ABOVE:
            buffer <<  "SELECT * FROM t_logging WHERE time_int >= " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), max_cnt );
            break;
        case eTIME_SEARCH_OPTION::INCLUDING_AND_BELOW:
            buffer <<  "SELECT * FROM t_logging WHERE time_int <= " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), max_cnt );
            break;
        default:
            return false;
            break;
        }
    }


    bool   
    LDatabase::InitSQLQuery(  const uint64_t time_min, const uint64_t time_max,  int cnt )
    {
        std::stringstream buffer; 
        buffer <<   "SELECT * FROM t_logging WHERE time >= " << time_min << " AND time <= " << time_max  << " ORDER BY id DESC";
        return InitQuery( buffer.str(), cnt );
    }    
/**@}*/


  
    /** @brief    Loop over all entries matching the current SQL query
     *  @details  The sql query must be initialized beforehand by calling InitSQLQuery(). The function returns true
     *  until the log entires matching the SQL query is exhausted.  
     *  @param[in,out]  entry The retrieved log entry is stored in this object
     *  @return true as long as ther are more entries to retrieve, false 
     *  when the last entry has been reached. 
     *  @return false if the sql query has not been initialized. */
    bool
    LDatabase::ReadEntriesGetEntry(LLogEntrySQL  &entry )
    {
        if( fStmt == nullptr )
        {
#ifdef HAS_LOGGING
            HandleError( GLOCATION, eMSGLEVEL::LOG_FATAL, DISABLE_EXCEPTION,  "NO SQL QUERY INITIALIZED" );   
#else
            HandleError(GLOCATION, DISABLE_EXCEPTION, "NO SQL QUERY INITIALIZED");
#endif 
            //HandleError(const GLocation  l, const bool  throw_ex, const char* fmt, const Args... args)
            return false;    
        }

        int rc;
        do
        {
            rc = sqlite3_step(fStmt);

        } while ((rc != SQLITE_DONE) && (rc != SQLITE_ROW) && (rc != SQLITE_ERROR));


           if (rc == SQLITE_ROW)
           {
             //  int ColumnCount = sqlite3_column_count(fStmt);
               int i = 0;

               try
               {
                   entry.fId  = ReadInteger( fStmt,  i,  "id",  SQLITE_INTEGER, GLOCATION ); 
                   i++;
                   entry.fTimeI = ReadInteger( fStmt,  i,  "time_int",  SQLITE_INTEGER, GLOCATION ); 
                   i++;
                   entry.fTimeD =ReadFloat( fStmt,  i,  "time_float",  SQLITE_FLOAT, GLOCATION ); 
                   i++;
                   entry.fLevel  = ReadInteger( fStmt,  i,  "level",  SQLITE_INTEGER, GLOCATION ); 
                   i++;
                   entry.fCategory   = ReadInteger( fStmt,  i,  "category",  SQLITE_INTEGER, GLOCATION ); 
                   i++;
                   entry.fJson = ReadText( fStmt,  i,  "json",  SQLITE_TEXT, GLOCATION ); 
               }
               catch( GException &e )
               {
                   DB_FATAL("Exception caught: %s", e.what() );
                   return false;
               }
               catch( std::exception &e )
               {
                   DB_FATAL("Exception caught: %s", e.what() ); 
                   return false;
               }
               catch(...)
               {
                  DB_FATAL("Uknown exception caught" ); 
                  return false;
               }

              return true;
            }
            else
            {
               sqlite3_finalize(fStmt);
               return false;
            }
    }

    void LDatabase::SetMaxDbFileSize(const uint64_t maxSize)
    {
        fMaxDbFileSize = maxSize;
        char *zErrMsg = 0;
        const char *sql = "REPLACE INTO t_triggerControl (name, enabled) VALUES ('delete_old', 0)";


        int rc = sqlite3_exec(fDataBase, sql, NULL, 0, &zErrMsg);

        if (rc != SQLITE_OK)
        {
#ifdef HAS_LOGGING
            HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
            HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif
            sqlite3_free(zErrMsg);
        }
    }

    std::string LDatabase::GetDBPath() const
    {
        return fDBPath;
    }
    

    bool 
    LDatabase::CreateTables()
    {
          char *zErrMsg = 0;  
              const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS t_logging ( "
                                     "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                     "time_int   INTEGER, "
                                     "time_float FLOAT(53), "
                                     "level INTEGER, "
                                     "category INTEGER,"
                                     "json TEXT );";

            // Create logging table
            int rc = sqlite3_exec(fDataBase, LoggingSQL, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK)
            {
#ifdef HAS_LOGGING
                HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
                HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif
                sqlite3_free(zErrMsg);
                return false;
            }

            const char *TriggerControlSQL = "CREATE TABLE IF NOT EXISTS t_triggerControl ( "
                                            "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                            "name TEXT, "
                                            "enabled INTEGER);";
            rc = sqlite3_exec(fDataBase, TriggerControlSQL, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK)
            {
#ifdef HAS_LOGGING
                HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
                HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif

                sqlite3_free(zErrMsg);
                return false;
            }

            const char *RingBufferTriggerSQL = "CREATE TRIGGER IF NOT EXISTS delete_old AFTER INSERT ON t_logging "
                                               "WHEN (SELECT enabled from t_triggerControl WHERE name='delete_old') "
                                               "BEGIN "
                                               "DELETE FROM t_logging WHERE id IN (SELECT id FROM t_logging ORDER BY id ASC LIMIT 1); "
                                               "END";
            rc = sqlite3_exec(fDataBase, RingBufferTriggerSQL, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK)
            {

#ifdef HAS_LOGGING
                HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
                HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif

                sqlite3_free(zErrMsg);
                return false;
            }

            const char *UniqueIdxSQL = "CREATE UNIQUE INDEX IF NOT EXISTS idx_triggerControl_name  ON t_triggerControl (name)";

            rc = sqlite3_exec(fDataBase, UniqueIdxSQL, NULL, 0, &zErrMsg);
            if (rc != SQLITE_OK)
            {
#ifdef HAS_LOGGING
                HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,  DISABLE_EXCEPTION,  "SQL error: %s",  zErrMsg  );
#else
                HandleError(GLOCATION, DISABLE_EXCEPTION, "SQL error: %s", zErrMsg);
#endif

                sqlite3_free(zErrMsg);
                return false;
            }

            return true;
    }



} // namespace LOGMASTER
