// -*- mode: c++ -*-
#ifndef LDATABASE_H
#define LDATABASE_H
/**************************************************************************
 * This file is property of and copyright by Embedded Consulting'  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/


#include  <utilities/GDefinitions.h>
#include  <utilities/GDataBaseIF.h>
#include  "LLogEntrySQL.h"
#include  <logging/LEnums.h>
#include  "LMessage2Json.h"

#include <utilities/GLocation.h>

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
 * <table>
 * <tr> 
 *  <td bgcolor="grey" > field</td> <td>id</td>   <td>time</td>  <td>level</td>    <td>category</td>  <td>json</td>
 * </tr>
 * <tr>
 *   <td bgcolor="grey"> type</td>       <td>int64</td>   <td>int64</td>    <td>int</td>  <td>int</td>    <td>text</td>       
 * </tr>
 * <tr>
 * <td  bgcolor="grey" > explanation</td>   <td>primary key</td>   <td>Unix epoch time</td>   <td>The log level   debug, error etc..</td>   <td>Sub system</td>  <td>The original message on json format </td>
 * </tr>
 * </table>       
 *               
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
    class LMessage;
    class LMessageGenerator;

    #define ALL_ENTRIES 0

    enum class eTIME_SEARCH_OPTION
    {
        EXACTLY = 1,
        INCLUDING_AND_ABOVE = 2,
        INCLUDING_AND_BELOW = 3,
    };


    class LDatabase : public GDataBaseIF
    {
        public:
        static LDatabase API * Instance ( const string db_path = "" );
            
            static void API SetDatabase(  const string db_path  );
            static void API SetDatabaseDefault(    );
            API LDatabase(  );
            virtual ~LDatabase() {};
            virtual bool API CreateTables()  override ;

            void API AddLogEntry (  std::shared_ptr<LMessage>  msg  );
            bool API DeleteEntries();
            
            bool API InitSQLQuery(const uint64_t time, const eTIME_SEARCH_OPTION opt, const int max_cnt);
            bool API InitSQLQuery(const uint64_t time_min, const uint64_t time_max, const int max_cnt);
            bool API InitSQLQuery(const eLOGLEVEL level, const int max_cnt);
            bool API InitSQLQuery(const eMSGSYSTEM system, const int max_cnt);
            bool API InitSQLQuery(const eLOGLEVEL level, const eMSGSYSTEM system, const int max_cnt);
            bool API InitSQLQuery(const int cnt);
            bool API InitSQLQuery(const string sql);
            
            vector< LLogEntrySQL>  API Query( const   string sql );
            vector< LLogEntrySQL>  API Query( const   int max_cnt);         
            vector< LLogEntrySQL>  API Query( const   uint64_t time,  const eTIME_SEARCH_OPTION  opt, const int max_cnt);
            vector< LLogEntrySQL>  API Query( const   uint64_t time_min,        const int time_max,  const int max_cnt );
            vector< LLogEntrySQL>  API Query( const   eMSGSYSTEM sys,  const int max_cnt) ;
            vector< LLogEntrySQL>  API Query( const   eLOGLEVEL lvl,  const int max_cnt) ;
            vector< LLogEntrySQL>  API Query( const   eLOGLEVEL lvl,  const  eMSGSYSTEM sys,  const int max_cnt) ;
            bool  API ReadEntriesGetEntry(LLogEntrySQL &entry);
            void  API SetMaxDbFileSize(const uint64_t maxSize);
            string API GetDBPath() const;

        private:
            vector< LLogEntrySQL> FetchAll(   ); 
            LDatabase( const LDatabase & );
            LDatabase operator = ( const LDatabase & );
            bool InitQuery( string query, const int limit  );
            bool DeleteOldestEntries(int nEntries = 10);
        
            static string  fDBPath;
            static  LDatabase *fgInstance;
            LMessage2Json fMessage2Json;

            uint64_t fMaxDbFileSize{0};


    };

} // namespace LOGMASTER

#endif
