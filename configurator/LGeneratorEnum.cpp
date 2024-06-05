// -*- mode: c++ -*-
#include "LGeneratorEnum.h"
#include "LXmlEntitySubSystem.h"
#include "LXmlEntityLogLevel.h"
#include <utilities/GUtilities.h>

#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <format.h>



namespace CONFIGURATOR
{


    /** @copydoc LGenerator */
    LGeneratorEnum::LGeneratorEnum(const string path, const string classname,  const LXMLInfo xmlinfo) : LGenerator(path, classname,  xmlinfo)
    {
        fDoGenerateHeader = true;
    }
    
    /** @copydoc LGenerator::GenerateContent 
     * 
     * Generation of enums for logging levels and subsystems.
    */
    void LGeneratorEnum::GenerateContent(logentity_vec levels, sysentity_vec systems)
    {

        GenerateSystems(systems, fFileContentHeader);
        fFileContentHeader.push_back("\n\n");
        GenerateLevels(levels, fFileContentHeader);
    }


    /** Generation of c++ enums code fragment for the logging levels of the logging system
    * (typically DEBUG, INFO .... FATAL). The content is added to "lines" that will
    * be used to generate the file at a later stage.
    * @param[in] levels log levels that was parsed form a XML file (for instance config/logging.xml or similar)
    * @param[in, out] lines The content is added to this vector*/
    void
        LGeneratorEnum::GenerateLevels( logentity_vec levels, content_vec & content) const
    {
        content.push_back("/*Enum controlling the log level*/");
        content.push_back("#ifdef __cplusplus");
        content.push_back("enum class  eLOGLEVEL");
        content.push_back("#else");
        content.push_back("enum eLOGLEVEL");
        content.push_back("#endif");
        content.push_back("{");
        content.push_back("\tLOG_OFF\t\t\t=  0x00,    //  00000000   No sub system");
        
        int i = 0;

        for (auto& lvl : levels)
        {
            string line2 = fmt::format("    LOG_{:12} = 0x{:02x},    ", lvl->fName, (1 << lvl->fIndex));
            content.push_back(line2);
            i++;
        }

       // content.push_back("\tLOG_FORCE_DEBUG\t\t= " +   LUtilities::ToHexString(1 << i, 2) + ",  // " + LUtilities::ToBinaryString(1 << i, 8));
        content.push_back("\tLOG_ALL\t\t\t=  0xff,    //  11111111   All sub systems");
        content.push_back("};");
    }


    /** Generation of c++ enums code fragment for the logging sub systems of the logging system
   * The content is added to @ref lines that will * be used to generate the file at a later stage.
   * @param[in] levels log levels that was parsed form a XML file (for instance config/logging.xml or similar)
   * @param[in, out] lines The content is added to this vector*/
    void
    LGeneratorEnum::GenerateSystems( sysentity_vec systems,  content_vec & content) const
    {
        content.push_back("#pragma once\n\n");
        content.push_back(" #ifdef __cplusplus");
        content.push_back("enum class " + fSystemEnumName);
        content.push_back("#else");
        content.push_back("enum  " + fSystemEnumName);
        content.push_back("#endif");
        content.push_back(" {");
        content.push_back("\tSYS_NONE\t\t=  0x0000,    //  00000000 00000000    No sub system");
        int i2 = 1;
        

        for (auto& sys : systems)
        {
//            string line = g_utilities()->TabAlign("\tSYS_" + sys->fName + " ", 3) + "=  " + LUtilities::ToHexString(1 << sys->fIndex ) + ",    //  " +  LUtilities::ToBinaryString(1 << sys->fIndex );
            string line = std::format("    SYS_{:12} = 0x{:04x},    ", sys->fName, (1 << sys->fIndex) );
            content.push_back(line);
            i2++;
        }
        
        content.push_back("\tSYS_ALL\t\t\t=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)");
        content.push_back("};");
    }
}