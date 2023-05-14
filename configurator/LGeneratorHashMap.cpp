// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <utilities/GUtilities.h>
#include  <utilities/GString.h>
#include  <logging/GException.h>

#include <sstream>
#include <algorithm>
#include <algorithm>


#define MAX_ADDITIONL_SUBSYSTEMS 12

LGeneratorHashMap::LGeneratorHashMap( const string fname, const string xml, const string xsd) : LGenerator(fname, xml, xsd)
{
    
}



vector< string > 
LGeneratorHashMap::Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems )
{
//    vector<string> lines;


    XML_INFO("levles size = %d",  levels.size() );
    XML_INFO("systems size = %d", systems.size() );

    G_ASSERT_EXCEPTION(  systems.size() <= MAX_ADDITIONL_SUBSYSTEMS, 
    "Max number of syb systems exceeded. You can define maximum 12 additional sub systems, \
    you hav defined %d. please check your XML configuration",   systems.size() );    
    
  //  lines.push_back(  autoclause ); 
    fFileLineEntries.push_back("#include \""+ fClassName + ".h\"");
    fFileLineEntries.push_back("#include <utilities/GNumbers.h>");
    fFileLineEntries.push_back("#include <utilities/GUtilities.h>");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back( "namespace LOGMASTER");
    fFileLineEntries.push_back( "{" );
    fFileLineEntries.push_back( fClassName + "::" + fClassName+"( ) : fLogLevelHash() {}");
    fFileLineEntries.push_back( fClassName + "::~" + fClassName +"(){ }");
    fFileLineEntries.push_back("\n\n");

    GenerateInitHashLogLevel( systems,       fFileLineEntries  );
    GenerateInitHashSystem2String( systems,  fFileLineEntries  );
    GenerateInitHashLevel2String( levels,    fFileLineEntries   );
    GenerateInitHashLogTags( levels, systems, fFileLineEntries );
 
    //lines.push_back( "}" );
    fFileLineEntries.push_back("}");

    //return lines;
    return fFileLineEntries;
}	


void  
LGeneratorHashMap::GenerateInitHashLogTags(   vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,  
                                              vector<string> &lines  ) const
{
    lines.push_back("\n\n");
    lines.push_back("   void");
    lines.push_back("   "+ fClassName + "::InitHashLogTags(  map<string, std::tuple<eMSGSYSTEM, eLOGLEVEL>>  *SubCmdHash   )");
    
    lines.push_back("   {");

    for (auto &sys : systems)
    {
        vector<string> tags;
        tags.push_back(sys->fTag);
        if (sys->fTag != sys->fTagShort)
        {
            tags.push_back(sys->fTagShort);
        }

        for (auto &tag : tags)
        {
        
            lines.push_back( g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-off\"" + ",", 5)  +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eLOGLEVEL::LOG_OFF));");

            for (auto &lvl : levels)
            {
                string tmptag = tag + "-" + g_string()->ToLower(lvl->fName);  
               lines.push_back(  g_utilities()->TabAlign( "\tSubCmdHash->emplace(\"" + tmptag + "\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eLOGLEVEL::LOG_"+ lvl->fName  +"));");   
            }

            lines.push_back(  g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-all\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eLOGLEVEL::LOG_ALL));");
        }
        lines.push_back("\n");
    }
    lines.push_back("   }");
}                                                 



void   
LGeneratorHashMap::GenerateInitHashLevel2String (  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels, vector<string> &lines) const
{
    lines.push_back("\n\n");
    lines.push_back("   void" );
    lines.push_back("   " +  fClassName +"::InitHashLevel2String(  map<eLOGLEVEL, string> *Level2StringHash  )");
    lines.push_back("   {");
    lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_OFF, \"OFF\");");
    lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_FORCE_DEBUG, \"Force_Debug\");");

    for( auto &lvl: levels )
    {
        std::stringstream buffer; 
        buffer << "\tLevel2StringHash->emplace(eLOGLEVEL::" << "LOG_" << lvl->fName << ",\t" << "\"" << g_string()->ToPascalCase(  lvl->fName ) << "\"" ");";
        lines.push_back(  buffer.str()  );
    }

    lines.push_back("\tLevel2StringHash->emplace(eLOGLEVEL::LOG_ALL, \"ALL loglevels\");");
    lines.push_back("   }");
}


void   
LGeneratorHashMap::GenerateInitHashSystem2String( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &lines ) const
{
    lines.push_back("\n\n");
    lines.push_back("   void");
    
    lines.push_back("   " + fClassName + "::InitHashSystem2String( map<eMSGSYSTEM, string>  *System2StringHash )");
    lines.push_back("   {");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_EX,       \"Exeption\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_GENERAL,  \"General\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_USER,     \"User\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_ALARM,    \"Alarm\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_NONE,     \"System Unknown\");");
    
    for (auto &sys : systems)
    {
        std::stringstream buffer; 
        buffer << "\t" << "System2StringHash->emplace(eMSGSYSTEM::" << "SYS_" << sys->fName + ", ";
        buffer <<  "\t" << "\"" +  g_string()->ToPascalCase (sys->fName )  + "\");";
        lines.push_back (  buffer.str() ) ;
    }

    lines.push_back("   }");

}


void   
LGeneratorHashMap::GenerateInitHashLogLevel( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &lines  ) const
{
    lines.push_back("\n\n");
    lines.push_back("/** @brief initialization of the hash table for the logginglevel \
    * \
    *  This hash table holds the current logging level for a given sub-system. \
    *  This table is checked every time the logging system is asked to log a message, and if logging \
    *  is enabled for the given level and sub-system then the message is created. \
    *  Where the message is actually written (if at all) is decided by the target configuration,\
    *  whether or not logging is enabled to to file, to console, etc.. */");

    lines.push_back("   void");
    lines.push_back("   " + fClassName + "::InitHashLogLevel( )");

    lines.push_back("   {");
    lines.push_back("\tfLogLevelHash.clear();");
    lines.push_back("//\teLOGLEVEL level = (eLOGLEVEL)(PAD((int)l));");

    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_EX,")  +    "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_ERROR)  );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER,") +   "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING ) );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM,") +  "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING ) );");

    for (auto &sys : systems)
    {
        std::stringstream buffer;
        buffer << "\t" + g_utilities()->TabAlign("fLogLevelHash.emplace(" + fSystemEnumName + "::" + "SYS_" + sys->fName + ", ");
        buffer << "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_" + sys->fDefault + ") );";
        lines.push_back(buffer.str());
        //FORCE_DEBUG("name = %s", buffer.str().c_str() );
    }


    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL,") +   "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING ) );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_NONE,") +      "(eLOGLEVEL)PAD( (int)eLOGLEVEL::LOG_WARNING ) );");

    lines.push_back("   }");

}	 	