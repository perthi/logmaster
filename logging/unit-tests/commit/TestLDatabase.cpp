// -*- mode: c++ -*-
/**************************************************************************
 * This file is property of and copyright by Embedded Consulting'  2020    *
 *                                                                        *
 * Author: Per Thomas Hille <pth@embc.no>                                 *
 * Contributors are mentioned in the code where appropriate.              *
 * Please report bugs to pth@embc.no                                      *
 **************************************************************************/

#include "TestLDatabase.h"


#include <logging/LDatabase.h>
#include <logging/LLogApi.h>
#include <logging/LLogEntrySQL.h>
#include <utilities/GRandom.h>
//#include <logging/LEnums.h>

#include <memory>

#include <vector>
using std::vector;

using namespace LOGMASTER;


LDatabase *  TestLDatabase::fgDatabase = nullptr;
string    TestLDatabase::fgDatabaseBasePath = "";


#ifndef LOGMASTER_HOME
constexpr char LOGMASTER_HOME[] = "ERROR_NOT_SET";
#endif


#define STRINGLIFY(x) #x
#define EXPAND(x) STRINGLIFY(x)


void 
TestLDatabase::SetUpTestCase()
{
    string s = EXPAND(LOGMASTER_HOME);
    s.erase(0, 1);
    s.erase(s.size() - 2);

    fgDatabaseBasePath = s + "\\test-data";
    s = fgDatabaseBasePath + "\\logmaster-test.db";
    CERR << "s = " << s << ENDL;
    fgDatabase =  LDatabase::Instance( s );
}


void 
TestLDatabase::TearDownTestCase()
{
    fgDatabase->CloseDatabase(); 
    fgDatabase->SetDatabaseDefault();
}


void 
TestLDatabase::SetUp()
{
    PUSH();
    SET_LOGTARGET("--target-off --target-file --target-stdout");
    SET_LOGLEVEL("--all-info");
}


void 
TestLDatabase::TearDown()
{
    POP();
}




TEST_F( TestLDatabase , all_entries )
{
    auto db = fgDatabase;
    auto entries = db->Query( ALL_ENTRIES );
    size_t entries_max = entries.size();
    EXPECT_EQ(entries_max , 3285 );

    entries = db->Query(100 );
    EXPECT_EQ(entries.size() ,100 );

    entries = db->Query( 1);
    EXPECT_EQ(entries.size() ,1 );
    entries = db->Query(   3285  );
    EXPECT_EQ(entries.size() ,  3285 );

    for(int i = 0; i < 20; i++ )
    {
        int n = g_random()->Uniform<int>( (int)1, (int)entries_max  );

        entries =   db->Query( n );   
        EXPECT_EQ(entries.size() , n  );

    }

}




TEST_F( TestLDatabase , specific_system )
{
     auto db = fgDatabase;
     vector<eMSGSYSTEM> sys_v = { eMSGSYSTEM::SYS_FSM, eMSGSYSTEM::SYS_GENERAL, eMSGSYSTEM::SYS_COM };

    
    for( auto s: sys_v )
    {
        auto entries = db->Query ( s, ALL_ENTRIES );
        EXPECT_GE( entries.size(), 0  );

        for( auto  e : entries )
        {
           EXPECT_EQ ( (int)e.fCategory, (int)s  );     
        }

    }
    
}




TEST_F( TestLDatabase , specific_system_multiple )
{
    auto db = fgDatabase;
    vector<eMSGSYSTEM> sys_v = { eMSGSYSTEM::SYS_FSM, eMSGSYSTEM::SYS_GENERAL, eMSGSYSTEM::SYS_COM };

    for( auto s: sys_v )
    {
        auto entries = db->Query ( s | eMSGSYSTEM::SYS_USER , ALL_ENTRIES );
        EXPECT_GE( entries.size(), 0  );

        for( auto  e : entries )
        {
            EXPECT_EQ ( (int)e.fCategory, (int) ( s | eMSGSYSTEM::SYS_USER)  );     
        }

    }
}



TEST_F( TestLDatabase , specific_level )
{
    auto db = fgDatabase;
    vector <eMSGLEVEL> level_v  = { eMSGLEVEL::LOG_DEBUG,   eMSGLEVEL::LOG_INFO,  eMSGLEVEL::LOG_WARNING,  eMSGLEVEL::LOG_ERROR,  eMSGLEVEL::LOG_FATAL}; 

    for( auto lvl : level_v )
    {
        auto entries = db->Query( lvl, ALL_ENTRIES  );
        EXPECT_GE( entries.size(), 0  );

        for( auto  e : entries )
        {
           EXPECT_EQ ( (int)e.fLevel, (int)lvl  );     
        }

    }
}



TEST_F( TestLDatabase , specific_level_sys )
{
    auto db = fgDatabase;
   
    vector <eMSGLEVEL> level_v  = { eMSGLEVEL::LOG_DEBUG,   eMSGLEVEL::LOG_INFO,  eMSGLEVEL::LOG_WARNING,  eMSGLEVEL::LOG_ERROR,  eMSGLEVEL::LOG_FATAL}; 
    vector<eMSGSYSTEM> sys_v = { eMSGSYSTEM::SYS_FSM, eMSGSYSTEM::SYS_GENERAL, eMSGSYSTEM::SYS_COM };

    for( auto lvl: level_v )
    {
        for( auto s : sys_v )
        {
            auto entries = db->Query( lvl,  s, ALL_ENTRIES  ); 

            for( auto  e : entries )
            {
            
              EXPECT_EQ ( (int)e.fLevel, (int)lvl  );     
              EXPECT_EQ ( (int)e.fCategory, (int)s  );   
            }

        }

    }
}




TEST_F( TestLDatabase , specific_level_sys_multiple )
{
    auto db = fgDatabase;

    vector <eMSGLEVEL> level_v  = { eMSGLEVEL::LOG_DEBUG,   eMSGLEVEL::LOG_INFO,  eMSGLEVEL::LOG_WARNING,  eMSGLEVEL::LOG_ERROR,  eMSGLEVEL::LOG_FATAL}; 
    vector<eMSGSYSTEM> sys_v = { eMSGSYSTEM::SYS_FSM, eMSGSYSTEM::SYS_GENERAL, eMSGSYSTEM::SYS_COM };
    for (auto lvl : level_v)
    {
        for (auto s : sys_v)
        {
            auto entries = db->Query(lvl, s | eMSGSYSTEM::SYS_USER, ALL_ENTRIES);

            EXPECT_GE(  entries.size() , 0 );

            for (auto e : entries)
            {

                EXPECT_EQ((int)e.fLevel, (int) lvl);
                EXPECT_EQ((int)e.fCategory, (int) ( s | eMSGSYSTEM::SYS_USER ) );
            }
        }
    }
}




TEST_F( TestLDatabase , time )
{
    auto db = fgDatabase;
    auto entries = db->Query(ALL_ENTRIES);

    uint64_t time =  1591452646;

    entries = db->Query(  time  , eTIME_SEARCH_OPTION::EXACTLY, ALL_ENTRIES);
    for (auto e : entries)
    {
        EXPECT_EQ(  time , e.fTimeI);
    }

    entries = db->Query( time , eTIME_SEARCH_OPTION::INCLUDING_AND_ABOVE, ALL_ENTRIES);
    for (auto e : entries)
    {
        EXPECT_TRUE( e.fTimeI >=  time  );
    }

    entries = db->Query(   time , eTIME_SEARCH_OPTION::INCLUDING_AND_BELOW, ALL_ENTRIES);
    for (auto e : entries)
    {
        if( ( long int)e.fTimeI  != -1 )
        {
           EXPECT_TRUE( e.fTimeI <=  time );
        }
    }

}



TEST_F( TestLDatabase , logrotation)
{
    auto oldPath = fgDatabase->GetDBPath();

    string rotatePath = fgDatabaseBasePath += "\\logmaster-test-rotate.db";
   // string rotatePath = string(LOGMASTER_HOME) + string("/logging/unit-tests/commit/test-data/logmaster-test-rotate.db");
    
    fgDatabase =  LDatabase::Instance(rotatePath);
    fgDatabase->SetMaxDbFileSize(1);
    auto db = fgDatabase;
    auto nEntries = db->Query(ALL_ENTRIES).size();

    std::shared_ptr<std::map<eMSGTARGET, std::shared_ptr< LMessage > > > test = LLogging::Instance()->GetLastMessages();
    auto msg =  ( (*test)[eMSGTARGET::TARGET_STDOUT] );
    db->AddLogEntry(msg);
    db->AddLogEntry(msg);
    db->AddLogEntry(msg);
    db->AddLogEntry(msg);
    db->AddLogEntry(msg);

    EXPECT_EQ(nEntries, db->Query(ALL_ENTRIES).size());
    db->SetMaxDbFileSize(0);
    db = LDatabase::Instance(oldPath);
}

