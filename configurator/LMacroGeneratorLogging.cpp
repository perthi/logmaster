// -*- mode: c++ -*-


#include "LMacroGeneratorLogging.h"

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <logging/LLogApi.h>
#include  <utilities/GUtilities.h>

#include <sstream>

using namespace LOGMASTER;


LMacroGeneratorLogging::LMacroGeneratorLogging()
{

}

LMacroGeneratorLogging::~LMacroGeneratorLogging()
{

}


	// struct LMacroEntry
	// 	{
	// 		LMacroEntry(const string lvl, vector<LMacroName> m, vector<LSystems> s, bool is_assert) : 
	// 		                               fLevel(lvl), 
	// 									   fMacroNames(m), 
	// 									   fSystems(s), 
	// 									   fIsAssertMacro(is_assert){};
	// 		string fLevel;
	// 		vector< LMacroName> fMacroNames;
	// 		vector<LSystems> fSystems;
	// 		bool fIsAssertMacro = false;
	// 	};

LMacroGeneratorLogging::LMacroEntry 
LMacroGeneratorLogging::GenerateMacroEntry(  std::shared_ptr<LXmlEntityLogLevel> lvl, 
                                             std::shared_ptr<LXmlEntitySubSystem >  sys, 
                                             bool with_user ) const
{
   // LMacroEntry tmp;
    vector<LMacroName> names;
    vector<LSystem> systems;
    string user = with_user == true ? "_U" : "";

    names.push_back(LMacroName(sys->fName + "_" + lvl->fName + user, false));

    if (with_user == false)
    {
        names.push_back( LMacroName( sys->fName + "_" + "ASSERT_" + lvl->fName, true )) ;
    }

    if (sys->fName != sys->fNameShort)
    {
        names.push_back(LMacroName(sys->fNameShort + "_" + lvl->fName + user, false));

        if (with_user == false)
        {
            names.push_back( LMacroName( sys->fNameShort + "_" + "ASSERT_" + lvl->fName, true ) ) ;
        }
    }

    systems.push_back(LSystem(sys->fName));

    if (with_user == true)
    {
        systems.push_back(LSystem("USER"));
    }

    return  LMacroEntry( lvl->fName , names, systems  );
}




void 
LMacroGeneratorLogging::Generate(  const string /*outfile*/, 
	                               vector<std::shared_ptr<LXmlEntityLogLevel > > levels,
	                               vector<  std::shared_ptr< LXmlEntitySubSystem > >  systems ) const
{
    vector<string> lines;

    for (auto sys : systems)
    {
        for (auto lvl : levels)
        {
            vector<LMacroEntry> entries;
            LMacroEntry e = GenerateMacroEntry(lvl, sys, false);

            entries.push_back(LMacroEntry(e));
            e = GenerateMacroEntry(lvl, sys, true);

            GenerateLines(entries);
        }
    }
}


void 
LMacroGeneratorLogging::GenerateLines( vector<LMacroEntry>  m_entries  )  const
{
  
    for( auto entry: m_entries )
    {
        for ( auto m: entry.fMacroNames)
        {
            string line;
            std::stringstream buffer;
            buffer <<  "#define ";

            //if( entry.m.fIsAssertMacro == true )
            if(  m.fIsAssert  == true )
            {
                buffer <<   g_utilities()->TabAlign ( m.fMacroName + "(expr ...) "  + " if ( ! (expr) )", 6);
                buffer <<  "LLogging::Instance()->Log( " + fLevelEnumName + "::";  

            }
            else
            {
                buffer <<  g_utilities()->TabAlign ( m.fMacroName + "(...) ", 6 ); 
                buffer <<  "LLogging::Instance()->Log( " + fLevelEnumName + "::" ;
            }

            buffer <<  "LOG_" <<  entry.fLevel <<  ",    ";
            size_t  sz =   entry.fSystems.size();

            for(size_t i = 0; i < sz;  i++ )
            {
                if( i > 0 && sz > 1  )  
                {
                    buffer << " | "; 
                }
                
                buffer << fSystemEnumName << "::"  << entry.fSystems.at(i).fSystem ;
            }

            buffer << ", ";
            buffer <<  "GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)";
            
            PUSH();
            SET_LOGFORMAT("00000001");
            line = buffer.str();
            FORCE_DEBUG("The generated line is: %s", line.c_str() );
            POP();
        } 
    }
    
}
