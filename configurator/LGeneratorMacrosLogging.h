// -*- mode: c++ -*-
#ifndef LGENERATORMACROSLOGGING_H
#define LGENERATORMACROSLOGGING_H


#include "LGenerator.h"
#include "LXMLInfo.h"
#include <utilities/GDefinitions.h>


#include <memory>
#include <vector>
using std::vector;

#include <string>
using std::string;


class LXmlEntityLogLevel;
class LXmlEntitySubSystem;




namespace CONFIGURATOR
{

	class  LGeneratorMacrosLogging : public LGenerator
	{
	public:
		API LGeneratorMacrosLogging(const string path, const string classname,  const LXMLInfo xmlinfo);
		virtual API ~LGeneratorMacrosLogging() = default;

		virtual void API GenerateContent( const logentity_vec levels, const sysentity_vec systems)  override;

	private:



		struct LSystem
		{
			LSystem(const  string name) : fSystem(name) {}
			string fSystem = "";
		};

		struct LMacroName
		{
			LMacroName(const string name, bool is_assert) : fMacroName(name), fIsAssert(is_assert) {}
			string fMacroName = "";
			bool   fIsAssert = false;
		};


		struct LMacroEntry
		{
			LMacroEntry(const string lvl, const vector<LMacroName> m, const vector<LSystem> s) :
				fLevel(lvl),
				fMacroNames(m),
				fSystems(s) {};
			string fLevel;
			vector< LMacroName> fMacroNames;
			vector<LSystem> fSystems;
		};

		LMacroEntry GenerateMacroEntry( const logentity_ptr lvl, sysentity_ptr systems, bool with_user = false) const;

		void  GenerateLines(const vector<LMacroEntry> m);

		string  GenerateLine(const LMacroName m, const vector<LSystem> s, const string lvl) const;

	};

}

#endif
