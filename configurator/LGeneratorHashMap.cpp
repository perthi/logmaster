// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <utilities/GUtilities.h>
#include  <utilities/GString.h>
#include  <exception/GException.h>

#include <sstream>
#include <algorithm>


#define MAX_ADDITIONL_SUBSYSTEMS 12

LGeneratorHashMap::LGeneratorHashMap( const string fname ) : LGenerator(fname)
{
    
}


LGeneratorHashMap::~LGeneratorHashMap()
{

}


vector< string > 
LGeneratorHashMap::Generate(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, const string autoclause ) const
{
    vector<string> lines;


    XML_INFO("levles size = %d",  levels.size() );
    XML_INFO("systems size = %d", systems.size() );

    G_ASSERT_EXCEPTION(  systems.size() <= MAX_ADDITIONL_SUBSYSTEMS, 
    "Max number of syb systems exeeeded. You can define maximum 12 additional sub systems, \
    you hav defined %d. please check your XML configuration",   systems.size() );    
    
    lines.push_back(  autoclause ); 

    lines.push_back("#include \"LHashMapsBase.h\"");
    lines.push_back("#include <utilities/GNumbers.h>");
    lines.push_back("#include <utilities/GUtilities.h>");
  
    lines.push_back("\n\n");

    lines.push_back( "namespace LOGMASTER");
    lines.push_back( "{" );
    
    lines.push_back("LHashMapsBase::LHashMapsBase( ) : fLogLevelHash(), fDefaultLevel(eMSGLEVEL::LOG_WARNING){}");
    lines.push_back("LHashMapsBase::LHashMapsBase( const eMSGLEVEL  level) : fLogLevelHash(), fDefaultLevel( level ) {}");
    lines.push_back("LHashMapsBase::~LHashMapsBase(){ }");

    lines.push_back("\n\n");

    GenerateInitHashLogLevel( systems,        lines );
    GenerateInitHashSystem2String( systems,   lines );
    GenerateInitHashLevel2String( levels,     lines );
    GenerateInitHashLogTags( levels, systems, lines );
 
    lines.push_back( "}" );

    return lines;

}	


void  
LGeneratorHashMap::GenerateInitHashLogTags(   vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                          vector< std::shared_ptr<LXmlEntitySubSystem > >  systems,  
                                              vector<string> &lines  ) const
{
    lines.push_back("\n\n");
    lines.push_back("   void");
    lines.push_back("   LHashMapsBase::InitHashLogTags(  map<string, std::tuple<eMSGSYSTEM, eMSGLEVEL>>  *SubCmdHash   )");
    lines.push_back("   {");

    for (auto sys : systems)
    {
        vector<string> tags;
        tags.push_back(sys->fTag);
        if (sys->fTag != sys->fTagShort)
        {
            tags.push_back(sys->fTagShort);
        }

        for (auto tag : tags)
        {
        
            lines.push_back( g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-off\"" + ",", 5)  +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_OFF));");

            for (auto lvl : levels)
            {
                string tmptag = tag + "-" + g_string()->ToLower(lvl->fName);  
               lines.push_back(  g_utilities()->TabAlign( "\tSubCmdHash->emplace(\"" + tmptag + "\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_"+ lvl->fName  +"));");   
            }

            lines.push_back(  g_utilities()->TabAlign("\tSubCmdHash->emplace(\"" + tag + "-all\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_ALL));");
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
    lines.push_back("   LHashMapsBase::InitHashLevel2String(  map<eMSGLEVEL, string> *Level2StringHash  )");
    lines.push_back("   {");

    lines.push_back("\tLevel2StringHash->emplace(eMSGLEVEL::LOG_OFF, \"OFF\");");
    lines.push_back("\tLevel2StringHash->emplace(eMSGLEVEL::LOG_FORCE_DEBUG, \"Force_Debug\");");

    for( auto lvl: levels )
    {
        std::stringstream buffer; 
        buffer << "\tLevel2StringHash->emplace(eMSGLEVEL::" << "LOG_" << lvl->fName << ",\t" << "\"" << g_string()->ToPascalCase(  lvl->fName ) << "\"" ");";
        lines.push_back(  buffer.str()  );
    }

    lines.push_back("\tLevel2StringHash->emplace(eMSGLEVEL::LOG_ALL, \"ALL loglevels\");");
    lines.push_back("   }");
}


void   
LGeneratorHashMap::GenerateInitHashSystem2String( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems, vector<string> &lines ) const
{
    lines.push_back("\n\n");
    lines.push_back("   void");
    lines.push_back("   LHashMapsBase::InitHashSystem2String( map<eMSGSYSTEM, string>  *System2StringHash )");
    lines.push_back("   {");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_EX,       \"Exeption\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_GENERAL,  \"General\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_USER,     \"User\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_ALARM,    \"Alarm\");");
    lines.push_back( "\tSystem2StringHash->emplace(eMSGSYSTEM::SYS_NONE,     \"System Unknown\");");
    
    for (auto sys : systems)
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
    *  This hash table holds the current logging level for a given sub-system. This table is checked every time the logging system is asked to log a message, and if logging is enabled for the given level \
    *  and sub-system then the message is created. Where the message is actuall written (if at all) is decided by the target configuration, wether or not logging is enabled to to file, to console, etc.. \
    *  @param l  All system are initialized with logging for this level or higher.  */");

    lines.push_back("   void");
    lines.push_back("   LHashMapsBase::InitHashLogLevel(const eMSGLEVEL /*l*/)");
    lines.push_back("   {");
    lines.push_back("\tfLogLevelHash.clear();");
    lines.push_back("//\teMSGLEVEL level = (eMSGLEVEL)(PAD((int)l));");

    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_EX,")  +    "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_ERROR)  );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_USER,") +   "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_ALARM,") +  "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );");

    for (auto sys : systems)
    {
        std::stringstream buffer;
        buffer << "\t" + g_utilities()->TabAlign("fLogLevelHash.emplace(" + fSystemEnumName + "::" + "SYS_" + sys->fName + ", ");
        buffer << "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_" + sys->fDefault + ") );";
        lines.push_back(buffer.str());
        //FORCE_DEBUG("name = %s", buffer.str().c_str() );
    }


    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_GENERAL,") +   "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );");
    lines.push_back("\t" + g_utilities()->TabAlign( "fLogLevelHash.emplace(eMSGSYSTEM::SYS_NONE,") +      "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_WARNING ) );");

    lines.push_back("   }");

}	 	