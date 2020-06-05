// -*- mode: c++ -*-
/**************************************************************************
 * This file is property of and copyright by Embedded Cosnulting  2020    *
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
#include <logging/LEnums.h>

#include <memory>

#include <vector>
using std::vector;

using namespace LOGMASTER;


LDatabase *  TestLDatabase::fgDatabase = nullptr;


TestLDatabase::TestLDatabase()
{


}


TestLDatabase::~TestLDatabase()
{

}






void 
TestLDatabase::SetUpTestCase()
{
    string path = string(LOGMASTER_HOME) + string("/logging/unit-tests/commit/test-data/logmaster-test.db");
   // LDatabase::Instance();
    fgDatabase =  LDatabase::Instance( path ); 
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
    EXPECT_EQ(entries_max , 758 );
    
    entries = db->Query(100 );
    EXPECT_EQ(entries.size() ,100 );

    entries = db->Query( 1);
    EXPECT_EQ(entries.size() ,1 );
    entries = db->Query(  758 );
    EXPECT_EQ(entries.size() , 758 );

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
           EXPECT_EQ ( (int)e.m_category, (int)s  );     
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
            EXPECT_EQ ( (int)e.m_category, (int) ( s | eMSGSYSTEM::SYS_USER)  );     
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
           EXPECT_EQ ( (int)e.m_level, (int)lvl  );     
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
            
              EXPECT_EQ ( (int)e.m_level, (int)lvl  );     
              EXPECT_EQ ( (int)e.m_category , (int)s  );   
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

                EXPECT_EQ((int)e.m_level, (int) lvl);
                EXPECT_EQ((int)e.m_category, (int) ( s | eMSGSYSTEM::SYS_USER ) );
            }
        }
    }
}



TEST_F( TestLDatabase , time )
{

    auto db = fgDatabase;
    auto entries = db->Query(ALL_ENTRIES);

    entries = db->Query(1591273465, eTIME_SEARCH_OPTION::EXACTLY, ALL_ENTRIES);
    for (auto e : entries)
    {
        EXPECT_EQ(1591273465, (int64_t)e.m_time);
    }

    entries = db->Query(1591273465, eTIME_SEARCH_OPTION::INCLUDING_AND_ABOVE, ALL_ENTRIES);
    for (auto e : entries)
    {
        EXPECT_TRUE((int64_t)e.m_time >= 1591273465);
    }

    entries = db->Query(1591273465, eTIME_SEARCH_OPTION::INCLUDING_AND_BELOW, ALL_ENTRIES);
    for (auto e : entries)
    {
        EXPECT_TRUE((int64_t)e.m_time <= 1591273465);
    }

}

