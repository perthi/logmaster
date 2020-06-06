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
#include "LEnums.h"
#include "LLogApi.h"
#include "LMessageGenerator.h"
#include "LPublisher.h"

#include <utilities/GFileIOHandler.h>

#include "sqlite/sqlite3.h"
#include  <json/json.hpp>
#include  <stdio.h>
#include  <string.h>

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
    LDatabase *LDatabase::fgInstance = nullptr;
    string    LDatabase::fDBPath = "logmaster.db";

    /** Singleton instance of the database
     *  @param[in] path The full path to the base, if empty then
     *  The defaul path is used  ( "logmaster.db" ) in the current directory
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
        //    CERR << "CREATING INSTANCE" << endl;
            fgInstance = new LDatabase( );
        
        }
        return  fgInstance;
    }


    LDatabase::LDatabase(  )
    {
        fMessageGenerator = std::make_shared<LMessageGenerator>(); 
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


    LDatabase::~LDatabase()
    {
        // CloseDatabase();
        // delete fgInstance;
        // fgInstance = nullptr;
    }


    /** @brief Writa a log entry to the databse
     *  @param[in] msg a log message as produced by the logging system */
    void
    LDatabase::AddLogEntry(const std::shared_ptr<LMessage> msg  )
    {
       // HandleError( GLOCATION, eMSGLEVEL::LOG_ERROR, "this is a test" ) ;
        int rc;
        static char sql[1000];
        char *zErrMsg = 0;
        nlohmann::json j;
        LMessage2Json::Message2Json( msg, j );
        std::stringstream buffer;
        buffer << j;

#ifndef WIN32
        snprintf(sql, 1000, "INSERT INTO t_logging (time_int, time_float, level, category, json ) VALUES ('%d', %f, %d, %d,'%s')",
#else
       snprintf_s(sql, "INSERT INTO  t_logging (time, level, category, json ) VALUES ('%d', %f, %d, %d,'%s')",
#endif
                   (int)msg->fEpochTime,  msg->fEpochTime, (int)msg->fLevel,  (int)msg->fSystem, 
                   buffer.str().c_str() );

        rc = sqlite3_exec(m_DataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
         //   HandleError( GLOCATION, eMSGLEVEL::LOG_ERROR, "AddEntry SQL error: %s", zErrMsg );
            printf("AddEntry SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }



    /** @brief  Delete all log entries from the database 
     *  @return true if the deletion was sucessful, false othervise */
    bool
    LDatabase::DeleteEntries()
    {
        int rc;
        char sql[200];
        char *zErrMsg = 0;
        snprintf(sql, 200, "DELETE FROM t_logging;");

        rc = sqlite3_exec(m_DataBase, sql, NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK)
        {
            CERR <<  "Log DeleteEntries SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
            return false;
        }
        return true;
    }


    /** @brief   Fetch all log entries that matches the SQL query
     *  @details On of the InitSQLQuery() functions must be called firts
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
    * The quere is performed in two steps. First
    * @param[in] sql SQL search expression
    * @param[in] time Unix epoch time
    * @param[in] time_min Unix epoch time
    * @param[in] time_max Unix epoch time
    * @param[in] opt  For time search this specfifes wether to return 
    * log entris with either larger, lower or equla time stamp than "time"
    * @param[in] max_cnt The maximum number of entries to return
    * @param[in] sy  subsystem/category ( return the messages matching sub system )
    * @param[in] lvl subsystem/category ( return the messages for a given log level )
    @return vector of log entries matching the search criteria */
    /**@{ */
     /** Queries the database uisng a user defiedn SQL query string */   
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

  
    /** Returns all log entries matcing a given time stamp (time). The time si Unix epoc time with
     * a resolution of seconds. 
     *  The serach option "opt" serach option  can be one of the follwing 
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
    LDatabase::Query( const  int time_min, const int time_max,  const int max_cnt )
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
    * The quere is performed in two steps. First
    * @param[in] sql SQL search expression
    * @param[in] time Unix epoch time
    * @param[in] time_min Unix epoch time
    * @param[in] time_max Unix epoch time
    * @param[in] opt  For time search this specfifes wether to return 
    * log entris with either larger, lower or equla time stamp than "time"
    * @param[in] max_cnt The maximum number of entries to return
    * @param[in] sy  subsystem/category ( return the messages matching sub system )
    * @param[in] lvl subsystem/category ( return the messages for a given log level )
    @return true if a valid SQL serach string could be generated, false othervise */
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
        if( m_DataBase == nullptr )
        {
            CERR << "DB = NULLPTR !!!!" << endl;
            return false;
        }



        if(limit > 0)
        {
          sql_query += LimitString(limit);  
        }

        int rc = sqlite3_prepare(m_DataBase, sql_query.c_str(), sql_query.length(), &m_stmt, nullptr);    

        if (rc != SQLITE_OK)
        {
            COUT << "Log ReadEntriesPrepare SQL error: " << sqlite3_errmsg(m_DataBase) << endl;
            return false;
        }
        else
        {
            return true;
        }
    }

    

    bool
    LDatabase::InitSQLQuery(const int time, const eTIME_SEARCH_OPTION opt, const int cnt )
    {
        std::stringstream buffer;

        switch (opt)
        {
        case eTIME_SEARCH_OPTION::EXACTLY:
            buffer <<  "SELECT * FROM t_logging WHERE time_int = " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), cnt );
            break;
        case eTIME_SEARCH_OPTION::INCLUDING_AND_ABOVE:
            buffer <<  "SELECT * FROM t_logging WHERE time_int >= " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), cnt );
            break;
        case eTIME_SEARCH_OPTION::INCLUDING_AND_BELOW:
            buffer <<  "SELECT * FROM t_logging WHERE time_int <= " << time  << " ORDER BY id DESC";
            return InitQuery( buffer.str(), cnt );
            break;
        default:
            return false;
            break;
        }
    }


    bool   
    LDatabase::InitSQLQuery(  const int time_min, const int time_max,  int cnt )
    {
        std::stringstream buffer; 
        buffer <<   "SELECT * FROM t_logging WHERE time >= " << time_min << " AND time <= " << time_max  << " ORDER BY id DESC";
        return InitQuery( buffer.str(), cnt );
    }    
/**@}*/



    string 
    LDatabase::LimitString( const int limit )
    {
        std::stringstream buffer;
        buffer << " LIMIT " << limit;
        return buffer.str();
    }





    /** @brief    Loop over all entries matching the current SQL query
     *  @details  The sql query must be initialized beforehand by calling InitSQLQuery(). The function returns true
     *  until the log entires matching the SQL query is exhausted.  
     *  @param[in,out]  entry The retrieved log entry is stored in this object
     *  @param[in] cnt  cnt The maximum number of entries to return
     *  @return true was long as ther are more entries to retriev, false
     *  when the last entry has been reached. 
     *  @return false if the sql query has not been initialized.
     * */
    bool
    LDatabase::ReadEntriesGetEntry(LLogEntrySQL  &entry )
    {

     //   HandleError(GLOCATION, eMSGLEVEL::LOG_FATAL, "This is a test");

        if( m_stmt == nullptr )
        {
            CERR << "NO SQL QUERY INITIALIZED" << endl;
            return false;    
        }

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
                        entry.fId = sqlite3_column_int(m_stmt, i);
                    }

                    else
                     {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type  (%d = %s)  \"id\"",  SQLITE_INTEGER, SQLType2String(SQLITE_INTEGER ).c_str()  );
                     }   
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "time_int") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER )
                    {
                        entry.fTimeI = (sqlite3_column_int( m_stmt, i));
                    }
                    else
                    {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type  (%d = %s) \"time_int\"",  SQLITE_INTEGER, SQLType2String(SQLITE_INTEGER ).c_str()    );  
                    }
                }

                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "time_float") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_FLOAT)
                    {
                        entry.fTimeD = (sqlite3_column_double(m_stmt, i));
                    }
                    else
                    {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type (%d = %s)   ) \"time_float\"",  SQLITE_FLOAT, SQLType2String(SQLITE_FLOAT).c_str()    );   
                    }
                }

                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "level") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER)
                    {
                        entry.fLevel = sqlite3_column_int( m_stmt, i);
                    }
                    else
                    {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type   (%d = %s)  \"level\"",  SQLITE_INTEGER, SQLType2String(SQLITE_INTEGER).c_str()   );   
                    }
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "category") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_INTEGER)
                    {
                        entry.fCategory = sqlite3_column_int( m_stmt, i);
                    }
                    else
                    {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type  (%d = %s) \"category\"",  SQLITE_INTEGER, SQLType2String(SQLITE_INTEGER).c_str()   );   
                    }
                }
                else if (strcasecmp(sqlite3_column_name(m_stmt, i), "json") == 0)
                {
                    if (sqlite3_column_type(m_stmt, i) == SQLITE_TEXT)
                    {
                        entry.fJson = std::string(reinterpret_cast<const char *>(sqlite3_column_text(m_stmt, i)));
                    }
                    else
                    {
                        HandleError(GLOCATION, eMSGLEVEL::LOG_ERROR,"Incorrect Type (%d = %s) for \"json\"", SQLITE_TEXT, SQLType2String(SQLITE_TEXT).c_str()  );   
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


	string 
    LDatabase::SQLType2String( const int sql_type  ) const
    {
        switch ( sql_type )
        {
        case  SQLITE_INTEGER:
            return  "SQLITE_INTEGER";
            break;
        case  SQLITE_FLOAT:
            return  "SQLITE_FLOAT";
            break;
        case  SQLITE_BLOB:
            return  "SQLITE_BLOB (binary large object)";
            break; 
        case  SQLITE_TEXT:
            return  "SQLITE_TEXT";
            break; 
        case  SQLITE_NULL:
            return  "SQLITE_NULL";
            break;
        default:
            std::stringstream buffer;
            buffer << "Unknown SQL type " << sql_type;
            return buffer.str();
            break;
        }
    }



    /**  Opens the databse and creates the necessary logging table if it doesn allready exists 
     *   @param[in]   db_path The fulle path to hte database
     *   @return      TRUE if the databse was opened sucessfullt, false othervise */
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
              const char *LoggingSQL = "CREATE TABLE IF NOT EXISTS t_logging ( "
                                     "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                                     "time_int   INTEGER, "
                                     "time_float FLOAT(53), "
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

     ///   COUT << "Database " <<  fDBPath  << " was closed" << endl;
    }


////  std::shared_ptr<LMessage>   API   
////  GenerateMsg( std::shared_ptr<LMessage> msg,  const eMSGFORMAT format, const eMSGLEVEL l,  const eMSGSYSTEM s, 
////  const char *fname, int line, const char * func, const char * fmt, va_list ap, string addendum = "" );


	void 
    LDatabase::HandleError( const GLocation l,   eMSGLEVEL lvl, const char * fmt, ...)
    {
        va_list ap;
        va_start(ap, fmt);
        std::shared_ptr<LMessage>  msg = std::make_shared< LMessage>();
        
        char formatted_message[2048] = {0};
        vsnprintf(formatted_message, sizeof(formatted_message) - 1, fmt, ap);
        fMessageGenerator->GenerateMsg( msg, eMSGFORMAT::PREFIX_ALL, lvl,  eMSGSYSTEM::SYS_DATABASE, l.fFileName.c_str(), l.fLineNo,  l.fFunctName.c_str(), fmt, ap  );

        LPublisher::Instance()->PublishToConsole(msg);
        LPublisher::Instance()->PublishToFile("db.log", msg);
        LPublisher::Instance()->PublishToSubscribers(msg);
        LPublisher::Instance()->PublishToSubscribers(msg);
        va_end(ap);
    }


} // namespace LOGMASTER
