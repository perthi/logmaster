// -*- mode: c++ -*-
#include "LGeneratorEnum.h"
#include <configurator/LXmlEntitySubSystem.h>
#include <configurator/LXmlEntityLogLevel.h>
#include <utilities/GUtilities.h>
#include <utilities/GString.h>
#include <sstream>

#include <logging/LLogApi.h>
using namespace LOGMASTER;

#include <bitset>


namespace CONFIGURATOR
{


    /** @copydoc LGenerator */
    LGeneratorEnum::LGeneratorEnum(const string fname, const LXMLInfo xmlinfo) : LGenerator(fname, xmlinfo)
    {

    }
    
    /** @copydoc LGenerator::GenerateContent 
     * 
     * Generation of enums for logging levels and subsystems.
    */
    void LGeneratorEnum::GenerateContent(vector<std::shared_ptr<LXmlEntityLogLevel>> levels,
                                         vector<std::shared_ptr<LXmlEntitySubSystem>> systems)
    {
        GenerateSystems(systems, fFileLineEntries);
        fFileLineEntries.push_back("\n\n");
        GenerateLevels(levels, fFileLineEntries);
    }


    /** Generation of c++ enums code fragment for the logging levels of the logging system
    * (typically DEBUG, INFO .... FATAL). The content is added to "lines" that will
    * be used to generate the file at a later stage.
    * @param[in] levels log levels that was parsed form a XML file (for instance config/logging.xml or similar)
    * @param[in, out] lines The content is added to this vector*/
    void
        LGeneratorEnum::GenerateLevels(vector< std::shared_ptr<LXmlEntityLogLevel > >  levels, vector<string>& lines) const
    {
        lines.push_back("/*Enum controlling the log level*/");
        lines.push_back("#ifdef __cplusplus");
        lines.push_back("enum class  eLOGLEVEL");
        lines.push_back("#else");
        lines.push_back("enum eLOGLEVEL");
        lines.push_back("#endif");
        lines.push_back("{");

        lines.push_back("\tLOG_OFF\t\t\t=  0x00,    //  00000000   No sub system");
        int i = 0;

        for (auto& lvl : levels)
        {
            string line = g_utilities()->TabAlign("\tLOG_" + lvl->fName + " ", 3) + "=  " + ToHexString(1 << i, 2) + ",    //  " + ToBinaryString(1 << i, 8);
            lines.push_back(line);
            i++;
        }

        lines.push_back("\tLOG_FORCE_DEBUG\t\t= " + ToHexString(1 << i, 2) + ",  // " + ToBinaryString(1 << i, 8));
        lines.push_back("\tLOG_ALL\t\t\t=  0xff,    //  11111111   All sub systems");
        lines.push_back("};");
    }


    /** Generation of c++ enums code fragment for the logging sub systems of the logging system
   * The content is added to @ref lines that will * be used to generate the file at a later stage.
   * @param[in] levels log levels that was parsed form a XML file (for instance config/logging.xml or similar)
   * @param[in, out] lines The content is added to this vector*/
    void
    LGeneratorEnum::GenerateSystems(vector<std::shared_ptr<LXmlEntitySubSystem>> systems, vector<string>& lines) const
    {
        lines.push_back("// -*- mode: c++ -*-/n/n");
        lines.push_back("#pragma once\n\n");
        lines.push_back(" #ifdef __cplusplus");
        lines.push_back("enum class " + fSystemEnumName);
        lines.push_back("#else");
        lines.push_back("enum  " + fSystemEnumName);
        lines.push_back("#endif");
        lines.push_back(" {");
        lines.push_back("\tSYS_NONE\t\t=  0x0000,    //  00000000 00000000    No sub system");
        lines.push_back("\tSYS_EX\t\t\t=  0x0001,    //  00000000 00000001    The exception handling sub system");

        int i = 1;

        for (auto& sys : systems)
        {
            string line = g_utilities()->TabAlign("\tSYS_" + sys->fName + " ", 3) + "=  " + ToHexString(1 << i) + ",    //  " + ToBinaryString(1 << i);
            lines.push_back(line);
            i++;
        }

        lines.push_back("\tSYS_ALL\t\t\t=  0xffff     //  11111111 11111111    Any sub system (message will apply if logging is turned on for any of the sub system)");
        lines.push_back("};");
    }


    /** @todo move to GUtilities, or check if function already exists*/
    string
        LGeneratorEnum::ToHexString(const int num, const int width) const
    {
        std::stringstream buffer;
        buffer << "0x" << std::hex << std::setw(width) << std::setfill('0') << num;
        return buffer.str();
    }


    /** @todo move to GUtilities, or check if function already exists*/
    string
        LGeneratorEnum::ToBinaryString(int num, const int width) const
    {
        int upper = (num & 0xff00) >> 8;
        int lower = num & 0x00ff;

        std::bitset<8> x1(upper);
        std::bitset<8> x2(lower);
        std::stringstream buffer1;
        if (width > 8)
        {
            buffer1 << x1 << " " << x2 << std::setfill('0');
        }
        else
        {
            buffer1 << x2 << std::setfill('0');
        }

        CERR << "Binary string =\ty" << buffer1.str() << ENDL;

        return buffer1.str();
    }


}