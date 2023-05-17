// -*- mode: c++ -*-
#ifndef LMACROGENERATOREXCEPTION_H
#define LMACROGENERATOREXCEPTION_H


#include "LGenerator.h"
#include "LXMLInfo.h"
#include <utilities/GDefinitions.h>

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>


namespace CONFIGURATOR
{

	class LXmlEntitySubSystem;


	class  LGeneratorMacrosException : public LGenerator
	{
	public:
		API LGeneratorMacrosException(const string fname, const LXMLInfo xmlinfo);
		virtual API ~LGeneratorMacrosException() = default;
		virtual void  API GenerateContent(logentity_vec  levels, sysentity_vec  systems)  override;

	public:
		void API GenerateClasses(sysentity_vec  systems, vector<string>& content) const;
		void API GenerateExceptionMacros(sysentity_vec systems, vector<string>& in) const;
		void API GenerateAssertMacros( sysentity_vec  systems, vector<string>& in) const;
		vector<string> API MacroNames(sysentity_ptr  sys) const;
		string API ClassName(sysentity_ptr  sys) const;
	};

}

#endif
