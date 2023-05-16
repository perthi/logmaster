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
		virtual void  API GenerateContent(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
			vector< std::shared_ptr<LXmlEntitySubSystem > >  systems)  override;

	public:
		void API GenerateClasses(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& in) const;
		void API GenerateExceptionMacros(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& in) const;
		void API GenerateAssertMacros(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& in) const;
		vector<string> API MacroNames(std::shared_ptr<LXmlEntitySubSystem >  sys) const;
		string API ClassName(std::shared_ptr<LXmlEntitySubSystem >  sys) const;
	};

}

#endif
