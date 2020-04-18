// -*- mode: c++ -*-
#ifndef LMACROGENERATOREXCEPTION_H
#define LMACROGENERATOREXCEPTION_H

#include <vector>
#include <string>
using std::string;
using std::vector;

#include <memory>


class LXmlEntitySubSystem;


class  LGeneratorMacrosException
{
	public:
		LGeneratorMacrosException();
		virtual ~LGeneratorMacrosException();

	  vector<string>   Generate( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems   ) const;	 	
};

#endif
