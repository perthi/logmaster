// -*- mode: c++ -*-
#ifndef LGENERATORMACROSLOGGING_H
#define LGENERATORMACROSLOGGING_H

#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;

#include <configurator/LGenerator.h>
#include <utilities/GDefinitions.h>


class  LGeneratorMacrosLogging : public LGenerator
{
	public:
	   API LGeneratorMacrosLogging( const string fname, const string xml, const string xsd );
	   virtual API ~LGeneratorMacrosLogging() = default;

	   virtual void API Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                           vector< std::shared_ptr<LXmlEntitySubSystem > >  systems )  override;

	private:



		struct LSystem
		{
			LSystem( const  string name) : fSystem(name) {}
			string fSystem = "";
		};

		struct LMacroName 
		{
			LMacroName(const string name, bool is_assert) : fMacroName(name), fIsAssert( is_assert ) {}
			string fMacroName = "";
			bool   fIsAssert  = false;
		};


		struct LMacroEntry
		{
			LMacroEntry(const string lvl, vector<LMacroName> m, vector<LSystem> s ): 
			                               fLevel(lvl), 
										   fMacroNames(m), 
										   fSystems(s) {};
			string fLevel;
			vector< LMacroName> fMacroNames;
			vector<LSystem> fSystems;
		};

		LMacroEntry GenerateMacroEntry(  std::shared_ptr<LXmlEntityLogLevel>   lvl, 
		                                         std::shared_ptr<LXmlEntitySubSystem > sys, 
												 bool with_user = false) const;
		
		void  GenerateLines( const vector<LMacroEntry> m  );
		
		string  GenerateLine( const LMacroName m,  const vector<LSystem> s, const string lvl ) const;

		void  GenerateMandatory( );


};

#endif
