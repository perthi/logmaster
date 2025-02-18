// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <configurator/LGeneratorCommon.h>

#include  <utilities/GUtilities.h>
#include  <utilities/GString.h>
#include  <logging/GException.h>
#include  <configurator/LFileInfo.h>

#include <sstream>
#include <fmt/format.h>


#define MAX_ADDITIONL_SUBSYSTEMS 12

namespace CONFIGURATOR
{


    /** @copydoc LGenerator */
    LGeneratorHashMap::LGeneratorHashMap(const string path, const string classname, const LXMLInfo xmlinfo) : LGenerator(path, classname, xmlinfo)
    {
        fDoGenerateSource = true;
    }



    void
    LGeneratorHashMap::GenerateContent(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
            vector< std::shared_ptr<LXmlEntitySubSystem > >  systems)
    {
        XML_INFO("levels size = %d", levels.size());
        XML_INFO("systems size = %d", systems.size());

        G_ASSERT_EXCEPTION(systems.size() <= MAX_ADDITIONL_SUBSYSTEMS,
            "Max number of sub systems exceeded. You can define maximum 12 additional sub systems, \
    you have defined %d. please check your XML configuration", systems.size());

        string classname = fFileInfo->GetClassName();

        //fFileContentSource.push_back("#include \"" + fClassName + ".h\"");
        fFileContentSource.push_back("#include \"" + classname + ".h\"");
        fFileContentSource.push_back("#include <utilities/GNumbers.h>");
        fFileContentSource.push_back("#include <utilities/GUtilities.h>");
        fFileContentSource.push_back("\n\n");
        fFileContentSource.push_back("namespace LOGMASTER");
        fFileContentSource.push_back("{");
        fFileContentSource.push_back(classname + "::" + classname + "( ) : fLogLevelHash() {}");
        fFileContentSource.push_back(classname + "::~" + classname + "(){ }");
        fFileContentSource.push_back("\n\n");

        GenerateInitHashLogLevel(systems,        fFileContentSource);
        GenerateInitHashSystem2String(systems,   fFileContentSource);
        GenerateInitHashLevel2String(levels,     fFileContentSource);
        GenerateInitHashLogTags(levels, systems, fFileContentSource);
        GenerateHashPermissions( systems, fFileContentSource);

        fFileContentSource.push_back("}");
    }


    void   
    LGeneratorHashMap::GenerateHashPermissions(sysentity_vec sys, content_vec& content ) const
    {
        content.push_back("\n\n");
        content.push_back("   void");
        content.push_back("   " + fFileInfo->GetClassName( ) + "::InitHashPermissions( map<eMSGSYSTEM, bool>  *permHash )");
        content.push_back("   {");
        
        for ( auto s : sys )
        {
            string boolstring  =  ( s->fCanModify == true ? "true" : "false");

            /** @todo Either use fSystemEnumName consistently in all function or remove this variable */
            content.push_back(fmt::format("        permHash->emplace( {}::SYS_{},{});", fSystemEnumName,s->fName, boolstring));
        }
        
        content.push_back("   }");
    }


    void
    LGeneratorHashMap::GenerateInitHashLogTags(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
            vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,
            vector<string>& lines) const
    {
        lines.push_back("\n\n");
        lines.push_back("   void");
        lines.push_back("   " + fFileInfo->GetClassName() + "::InitHashLogTags(  map<string, std::tuple<eMSGSYSTEM, eLOGLEVEL>>  *SubCmdHash   )");

        lines.push_back("   {");

        for (auto& sys : systems)
        {
            vector<string> tags;
            tags.push_back(sys->fTag);
            if (sys->fTag != sys->fTagShort)
            {
                tags.push_back(sys->fTagShort);
            }

            for (auto& tag : tags)
            {

                lines.push_back(g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-off\"" + ",", 5) + "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + "," + "  eLOGLEVEL::LOG_OFF));");

                /** @todo align output using spaces, not tabs */
                for (auto& lvl : levels)
                {
                    string tmptag = tag + "-" + g_string()->ToLower(lvl->fName);
                    /** @todo use fmt::format here */
                    lines.push_back(g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tmptag + "\"" + ",", 5) + "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + "," + "  eLOGLEVEL::LOG_" + lvl->fName + "));");
                }

                lines.push_back(g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-all\"" + ",", 5) + "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + "," + "  eLOGLEVEL::LOG_ALL));");
            }
            lines.push_back("\n");
        }
        lines.push_back("   }");
    }



    void
    LGeneratorHashMap::GenerateInitHashLevel2String(vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, vector<string>& lines) const
    {
        lines.push_back("\n\n");
        lines.push_back("   void");
        lines.push_back("   " +  fFileInfo->GetClassName() + "::InitHashLevel2String(  map<eLOGLEVEL, string> *Level2StringHash  )");
        lines.push_back("   {");
        
        
        lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_OFF, \"OFF\");");
        
        /** @bug FORCE_DEBUG should be added to XML file, but current regexp pattern does not allow underscore*/
        lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_FORCE_DEBUG, \"Force_Debug\");");

        for (auto& lvl : levels)
        {
            std::stringstream buffer;
            buffer << "\tLevel2StringHash->emplace(eLOGLEVEL::" << "LOG_" << lvl->fName << ",\t" << "\"" << toPascalCase(lvl->fName) << "\"" ");";
            lines.push_back(buffer.str());
        }

        lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_ALL, \"ALL log-levels\");");
        lines.push_back("   }");
    }


    void
    LGeneratorHashMap::GenerateInitHashSystem2String(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& lines) const
    {
        lines.push_back("\n\n");
        lines.push_back("   void");

        lines.push_back("   " +  fFileInfo->GetClassName() + "::InitHashSystem2String( map<eMSGSYSTEM, string>  *System2StringHash )");
        lines.push_back("   {");
        lines.push_back("\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_NONE,     \"System Unknown\");");

        for (auto& sys : systems)
        {
            std::stringstream buffer;
            buffer << "\t" << "System2StringHash->emplace(eMSGSYSTEM::" << "SYS_" << sys->fName + ", ";
            buffer << "\t" << "\"" +  toPascalCase(sys->fName) + "\");";
            lines.push_back(buffer.str());
        }

        lines.push_back("   }");

    }


    void
    LGeneratorHashMap::GenerateInitHashLogLevel(vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string>& content) const
    {
        content.push_back("\n\n");
        content.push_back("/** @brief initialization of the hash table for the logging level \
    * \
    *  This hash table holds the current logging level for a given sub-system. \
    *  This table is checked every time the logging system is asked to log a message, and if logging \
    *  is enabled for the given level and sub-system then the message is created. \
    *  Where the message is actually written (if at all) is decided by the target configuration,\
    *  whether or not logging is enabled to file, to console, etc.. */");

        content.push_back("   void");
        content.push_back("   " +  fFileInfo->GetClassName() + "::InitHashLogLevel( )");
        content.push_back("   {");
        content.push_back("\tfLogLevelHash.clear();");
        content.push_back("//\teLOGLEVEL level = (eLOGLEVEL)(PAD((int)l));");


        for (auto& sys : systems)
        {
            std::stringstream buffer;
            buffer << "\t" + g_utilities()->TabAlign("fLogLevelHash.emplace(" + fSystemEnumName + "::" + "SYS_" + sys->fName + ", ");
            buffer << "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_" + sys->fDefault + ") );";
            content.push_back(buffer.str());
        }

        content.push_back("   }");
    }


}
