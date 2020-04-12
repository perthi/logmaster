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
  	// 		LMacroEntry(  vector<string> s, vector<string> m, bool is_assert )  : fSystems(s), fMacroNames(m), fIsAssertMacro(is_assert)  {} ;
  	// 		vector<string> fSystems;
  	// 		vector<string> fMacroNames;
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

    for( auto s : systems )
    {
        for( auto l : levels )
        {
            vector<LMacroEntry> entries;
         ///   LMacroEntry( { s->fName, s->fNameShort, ""   }; )

            std::stringstream buffer;
            // vector<string> m_names =  { s->fName +      "_" + l->fName,
            //                             s->fNameShort + "_" + l->fName
            //                            };
            // vector<string>  subsystems = { s->fName, s->fNameShort,   };

            //GenerateLine(  );


        }

    }

}


void 
LMacroGeneratorLogging::GenerateLines( const LMacroEntry m  ) const
{



}