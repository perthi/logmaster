// -*- mode: c++ -*-
#ifndef LGENERATOR_H
#define LGENERATOR_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <memory>
#include <vector>

using std::vector;

#include <string>
using std::string;

class LXmlEntityLogLevel; 
class LXmlEntitySubSystem;

class  LGenerator
{
	public:
	 LGenerator();
	 virtual ~LGenerator();

	virtual void Generate(   const string outfile, 
	                    vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                    vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const = 0;

	protected:
		string fLevelEnumName    =   "eMSGLEVEL";
	    string fSystemEnumName   =   "eMSGSYSTEM";					

};

#endif
