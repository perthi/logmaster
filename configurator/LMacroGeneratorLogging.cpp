// -*- mode: c++ -*-


#include "LMacroGeneratorLogging.h"

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 

#include <logging/LLogApi.h>

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
	// 		LMacroEntry(vector<string> m, vector<string> s, bool is_assert) : fMacroNames(m), fSystems(s), fIsAssertMacro(is_assert){};
	// 		vector<string> fMacroNames;
	// 		vector<string> fSystems;
	// 		bool fIsAssertMacro = false;
	// 	};

void 
LMacroGeneratorLogging::Generate(  const string outfile, 
	                               vector<std::shared_ptr<LXmlEntityLogLevel > > levels,
	                               vector<  std::shared_ptr< LXmlEntitySubSystem > >  systems ) const
{
    FORCE_DEBUG("oufile = %s",  outfile.c_str() );
    FORCE_DEBUG("levels size = %d",  levels.size()  );
    FORCE_DEBUG("systems size = %d",  systems.size()  ); 

    vector<string> lines;

    for (auto l : levels)
    {
        for (auto s : systems)
        {

            vector<LMacroEntry> entries;
            entries.push_back(LMacroEntry(l->fName, {s->fName + "_" + l->fName, s->fNameShort + "_" + l->fName}, {s->fName}, false));
            entries.push_back(LMacroEntry(l->fName, {s->fName + "_" + l->fName + "_U", s->fNameShort + "_" + l->fName + "_U"}, {s->fName, "USER"}, false));
            entries.push_back(LMacroEntry(l->fName, {s->fName + "_" + l->fName, s->fNameShort + "_" + l->fName}, {s->fName}, true));
            std::stringstream buffer;
        }
    }
}



void 
LMacroGeneratorLogging::GenerateLines( const vector<LMacroEntry>  m_entries  ) const
{
  

    for( auto entry: m_entries )
    {
        for ( auto m: entry.fMacroNames)
        {
            string line;
            std::stringstream buffer;
            
            buffer <<  "#define " +  m + "(...) "  + " LLogging::Instance()->Log( " + fLevelEnumName + "::" ;
            buffer <<  "LOG_" <<  entry.fLevel <<  ",    ";
            //buffer <<  "LOG_" <<  entry.fLevel <<  ",    " << fSystemEnumName << "::";
            
            // if( entry.fSystems.size() == 1  )
            // {
            //     buffer << fSystemEnumName << "::"  << entry.fSystems.at(0) + "," ;
            // }

           size_t  sz =   entry.fSystems.size();

            for(size_t i = 0; i < sz;  i++ )
            {
                buffer << fSystemEnumName << "::"  << entry.fSystems.at(0) + "," ;
                if( i > 1 && i < ( sz -1)  )
                {
                    buffer << " | "; 
                }
            }

            buffer << ", ";
            buffer <<  "GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)" << endl;
            
            PUSH();
            line = buffer.str();
            FORCE_DEBUG("The generated line is: %s", line.c_str() );
            POP();
        
        } 
        


    }

}