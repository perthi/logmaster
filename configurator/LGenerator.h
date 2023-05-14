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
	 LGenerator( const string path );
	 virtual ~LGenerator() = default;

	virtual vector<string>  Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause ) const = 0;

	string GetFilePath( ) const { return fFilePath; };	


	protected:
		string fFilePath		 =  "UNKNOWN"; //!< Fulll path of the .cpp or .h source file
		string fClassName        =  "UNKNOWN"; //!< Name of the class (extracted from the file path
		string fSourceFileName     =  "UNKNOWN"; //!< Name of the .cpp source file if applicable
		string fHeaderFileName     =  "UNKNOWN"; //!< Name of the .h header file if applicable
		string fLevelEnumName    =  "eLOGLEVEL"; //!< enum indentifier for loglevel in generated files
	    string fSystemEnumName   =  "eMSGSYSTEM";//!< enum indentifier for subsystem in generated files					

};

#endif
