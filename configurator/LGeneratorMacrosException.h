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
		virtual void  API GenerateContent(const logentity_vec levels, const sysentity_vec  systems)  override;

	public:
		void API GenerateClasses(const sysentity_vec  systems, content_vec & content) const;
		void API GenerateExceptionMacros(const sysentity_vec systems,  content_vec & content) const;
		//void API GenerateAssertMacros( sysentity_vec  systems, content_vec & content) const;
		vector<string> API MacroNames(sysentity_ptr  sys) const;
		string API ClassName( const sysentity_ptr  sys) const;
	};

}

#endif
