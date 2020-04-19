// -*- mode: c++ -*-
#ifndef LMACROGENERATOREXCEPTION_H
#define LMACROGENERATOREXCEPTION_H

#include "LGenerator.h"

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>



class LXmlEntitySubSystem;


class  LGeneratorMacrosException : public LGenerator
{
	public:
		LGeneratorMacrosException( const string fname );
		virtual ~LGeneratorMacrosException();
		virtual vector<string>  Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const override;

	public:
		void GenerateClasses(          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
		void GenerateExceptionMacros(  vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
		void GenerateAssertMacros(     vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,   vector<string>  &in  ) const;	
  		vector<string> MacroNames(     std::shared_ptr<LXmlEntitySubSystem >  sys  ) const;
		string ClassName(std::shared_ptr<LXmlEntitySubSystem >  sys ) const;  
};

#endif
