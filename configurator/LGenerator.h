// -*- mode: c++ -*-
#ifndef LGENERATOR_H
#define LGENERATOR_H
/***************************************************
* @copyright Embedded Consulting AS                *
* @author Per Thomas Hille <pth@embc.no>           *
***************************************************/


#include "LDefinitions.h"
#include "LXMLInfo.h"

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
	 LGenerator( const string path, const  LXMLInfo info );
	 virtual ~LGenerator() = default;

	virtual void  GenerateContent(   loglevel_vec   levels,
	                                 subsystem_vec  systems) = 0;

	string GetFilePath( ) const { return fFilePath; };	
	
	void   GenerateHeader(  const LXMLInfo );
	
	vector<string>& GetContent() { return  fFileLineEntries; };

	//static string SetXmlInfo(LXMLInfo);

	protected:
		static LXMLInfo   fXMLFileName;  //    
		string fFilePath		         =  "UNKNOWN";        //!< Full path of the .cpp or .h source file
		string fClassName                =  "UNKNOWN";        //!< Name of the class (extracted from the file path
		string fSourceFileName           =  "UNKNOWN";        //!< Name of the .cpp source file if applicable
		string fHeaderFileName           =  "UNKNOWN";        //!< Name of the .h header file if applicable
		string fLevelEnumName            =  "eLOGLEVEL";      //!< enum identifier for log level in generated files
	    string fSystemEnumName           =  "eMSGSYSTEM";     //!< enum identifier for subsystem in generated files					
		vector<string> fFileLineEntries;  //!< The lines that will be written to the generated file 	

};

#endif
