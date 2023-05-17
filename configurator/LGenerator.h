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

namespace CONFIGURATOR
{


	class LGenerator
	{
	public:
		LGenerator(const string path, const LXMLInfo info);
		virtual ~LGenerator() = default;

		/** Generate the content that will be written to file. This abstract method
		 * must  be implemented by all derived classes. The generated content will typically
		 * be a .cpp or .h source file. The parameters \ref levels and  \ref systems is parsed from
		 * a XML/XSD file. By default they should be defined in config/logging.xml and config/logging.xsd,
		 * but any other XML file can be used as long as it is validated by config/logging xsd,
		 * @param levels The log levels parsed from the XML file
		 * @param systems The logging sub-systems parsed from the XML file*/
		virtual void GenerateContent( logentity_vec levels,  sysentity_vec systems) = 0;

		string GetFilePath() const { return fFilePath; };

		void GenerateHeader(const LXMLInfo);

		vector<string>& GetContent() { return fFileLineEntries; };
		
	protected:
		static LXMLInfo fXMLFileNames;						// XML and XSD file used to generate files
		string fFilePath = "UNKNOWN";						//!< Full path of the .cpp or .h source file to be generated
		string fClassName = "UNKNOWN";						//!< Name of the class (extracted from the file path
		string fSourceFileName = "UNKNOWN";					//!< Name of the .cpp source file if applicable
		string fHeaderFileName = "UNKNOWN";					//!< Name of the .h header file if applicable
		string fLevelEnumName = "eLOGLEVEL";				//!< enum identifier for log level in generated files
		string fSystemEnumName = "eMSGSYSTEM";				//!< enum identifier for subsystem in generated files
		vector<string> fFileLineEntries = vector<string>(); //!< The data that will be written to file
	};

}

#endif
