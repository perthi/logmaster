// -*- mode: c++ -*-
#ifndef LGENERATOR_H
#define LGENERATOR_H
/***************************************************
 * @copyright Embedded Consulting AS                *
 * @author Per Thomas Hille <pth@embc.no>           *
 ***************************************************/

#include "LDefinitions.h"
#include "LXMLInfo.h"
//#include "LFileInfo.h"

#include <memory>

#include <string>
using std::string;
#include <vector>
using std::vector;

class LXmlEntityLogLevel;
class LXmlEntitySubSystem;

namespace CONFIGURATOR
{
    class LFileInfo;


    class LGenerator
    {
    public:
        LGenerator(const string path, const string classname,  const LXMLInfo info);
        virtual ~LGenerator() = default;

        /** Generate the content that will be written to file. This abstract method
         * must  be implemented by all derived classes. The generated content will typically
         * be a .cpp or .h source file. The parameters \ref levels and  \ref systems is parsed from
         * a XML/XSD file. By default they should be defined in config/logging.xml and config/logging.xsd,
         * but any other XML file can be used as long as it is validated by config/logging.xsd,
         * @param levels The log levels parsed from the XML file
         * @param systems The logging sub-systems parsed from the XML file*/
        virtual void GenerateContent(const logentity_vec levels, const sysentity_vec systems) = 0;


        ///string GetFilePath() const { return fFilePath; };

        /** @todo Check if this function name is logical */
        void GenerateLicenseHeader(const LXMLInfo);

        vector<string>& GetContentHeader( ) { return fFileContentHeader; };
        vector<string>& GetContentSource() { return fFileContentSource; };
        
        std::shared_ptr<LFileInfo> GetFileInfo() { return  fFileInfo; };


        bool IsEnabledHeader( ) { return fDoGenerateHeader;  };
        bool IsEnabledSource( ) { return fDoGenerateSource; };

    protected:
        std::shared_ptr<LFileInfo> fFileInfo = nullptr;
        
        static LXMLInfo fXMLFileNames;                        // XML and XSD file used to generate files
        
        /** @todo use these variables everywhere instead of hardcoding  eLOGLEVEL & eMSGSYSTEM*/
        string fLevelEnumName = "eLOGLEVEL";                //!< enum identifier for log level in generated files
        string fSystemEnumName = "eMSGSYSTEM";                //!< enum identifier for subsystem in generated files
        
        vector<string> fFileContentSource = vector<string>();  //!< The data that will be written to the .cpp source file
        vector<string> fFileContentHeader =   vector<string>();  //!< The data that will be written to the .h header file

        bool fDoGenerateHeader = false;
        bool fDoGenerateSource = false;
    };

}

#endif
