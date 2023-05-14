// -*- mode: c++ -*-
#ifndef LGENERATOR_H
#define LGENERATOR_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/

#include <memory>


#include <string>
using std::string;


#include <vector>
using std::vector;


class LXmlEntityLogLevel; 
class LXmlEntitySubSystem;

class  LGenerator
{
	public:
	 LGenerator( const string path, const string xml, const string xsd );
	 virtual ~LGenerator() = default;

	virtual std::vector<string>  Generate(  std::vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                   std::vector< std::shared_ptr<LXmlEntitySubSystem > >  systems) = 0;

	string GetFilePath( ) const { return fFilePath; };	
	void   GenerateHeader(const string xml, const string xsd);

	//protected:
		string fFilePath		         =  "UNKNOWN";        //!< Full path of the .cpp or .h source file
		string fClassName                =  "UNKNOWN";        //!< Name of the class (extracted from the file path
		string fSourceFileName           =  "UNKNOWN";        //!< Name of the .cpp source file if applicable
		string fHeaderFileName           =  "UNKNOWN";        //!< Name of the .h header file if applicable
		string fLevelEnumName            =  "eLOGLEVEL";      //!< enum identifier for log level in generated files
	    string fSystemEnumName           =  "eMSGSYSTEM";     //!< enum identifier for subsystem in generated files					
		vector<string> fFileLineEntries;  //!< The lines that will be written to the generated file 	

};

#endif
