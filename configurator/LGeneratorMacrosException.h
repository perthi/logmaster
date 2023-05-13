// -*- mode: c++ -*-
#ifndef LMACROGENERATOREXCEPTION_H
#define LMACROGENERATOREXCEPTION_H


#include "LGenerator.h"
#include <utilities/GDefinitions.h>

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>




class LXmlEntitySubSystem;


class  LGeneratorMacrosException : public LGenerator
{
	public:
		API LGeneratorMacrosException( const string fname );
		virtual API ~LGeneratorMacrosException() = default;
		virtual vector<string>  API Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause ) const override;

	public:
		void API GenerateClasses(          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
		void API GenerateExceptionMacros(  vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
		void API GenerateAssertMacros(     vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
  		vector<string> API MacroNames(     std::shared_ptr<LXmlEntitySubSystem >  sys  ) const;
		string API ClassName(std::shared_ptr<LXmlEntitySubSystem >  sys ) const;  
};

#endif
