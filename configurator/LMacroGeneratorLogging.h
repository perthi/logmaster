// -*- mode: c++ -*-
#ifndef LMACROGENERATORLOGGING_H
#define LMACROGENERATORLOGGING_H

#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;



class  LMacroGeneratorLogging
{
	public:
	   LMacroGeneratorLogging();
	   virtual ~LMacroGeneratorLogging();

	   void Generate(   const string outfile, 
	                    vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                    vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const;

	private:
		struct LMacroEntry
		{
  			LMacroEntry(  vector<string> s, vector<string> m, bool is_assert )  : fSystems(s), fMacroNames(m), fIsAssertMacro(is_assert)  {} ;
  			vector<string> fSystems;
  			vector<string> fMacroNames;
  			bool fIsAssertMacro = false;  

		};

		void GenerateLines( const LMacroEntry m  ) const;
		
		string fLevelEnumName =  "eMSGLEVEL";
	    string fSystemEnumName =  "eMSGSYSTEM";
};

#endif
