// -*- mode: c++ -*-


#include "LGeneratorMacrosLogging.h"

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <logging/LLogApi.h>
#include  <utilities/GUtilities.h>

#include <sstream>

using namespace LOGMASTER;


LGeneratorMacrosLogging::LGeneratorMacrosLogging()
{

}

LGeneratorMacrosLogging::~LGeneratorMacrosLogging()
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

LGeneratorMacrosLogging::LMacroEntry 
LGeneratorMacrosLogging::GenerateMacroEntry(  std::shared_ptr<LXmlEntityLogLevel> lvl, 
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
LGeneratorMacrosLogging::Generate(  const string /*outfile*/, 
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


vector<string> 
LGeneratorMacrosLogging::GenerateLines( const vector<LMacroEntry>  m_entries  )  const
{
  vector<string> lines;

    for( auto entry: m_entries )
    {
    
        for ( auto m: entry.fMacroNames)
        {
            string line;
            line = GenerateLine(  m , entry.fSystems,  entry.fLevel );
            lines.push_back(line);

            PUSH();
            SET_LOGFORMAT("00000001");
            FORCE_DEBUG("%s", line.c_str() );
            POP();
        } 
    }
    return lines;    
}



string  
LGeneratorMacrosLogging::GenerateLine( const LMacroName m,  const vector<LSystem> s, const string lvl  ) const
{
  //  string line = "";
    
    std::stringstream buffer;
    buffer << "#define ";

    //if( entry.m.fIsAssertMacro == true )
    if (m.fIsAssert == true)
    {
        buffer << g_utilities()->TabAlign(m.fMacroName + "(expr ...) " + "\tif ( ! (expr) )", 7);
        buffer << "LLogging::Instance()->Log( " + fLevelEnumName + "::";
    }
    else
    {
        buffer << g_utilities()->TabAlign(m.fMacroName + "(...) ", 7);
        buffer << "LLogging::Instance()->Log( " + fLevelEnumName + "::";
    }

    buffer << "LOG_" << lvl << ",    ";
    size_t sz = s.size();

    for (size_t i = 0; i < sz; i++)
    {
        if (i > 0 && sz > 1)
        {
            buffer << " | ";
        }

        buffer << fSystemEnumName << "::" << s.at(i).fSystem;
    }

    buffer << ", ";
    buffer << "GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)";
    
    return buffer.str();
}
