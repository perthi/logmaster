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
	 LGenerator( const string fname );
	 virtual ~LGenerator();

	virtual vector<string>  Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause ) const = 0;

	string GetFilename( ) const { return fFileName; };	


	protected:
		string fFileName		= "UNKNOWN";
		string fLevelEnumName    =   "eLOGLEVEL";
	    string fSystemEnumName   =   "eMSGSYSTEM";					

};

#endif
