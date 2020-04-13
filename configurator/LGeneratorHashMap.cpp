// -*- mode: c++ -*-


#include "LGeneratorHashMap.h"
#include <logging/LLogApi.h>

using namespace LOGMASTER;

#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <utilities/GUtilities.h>
#include  <utilities/GString.h>

#include <sstream>

#include <algorithm>


LGeneratorHashMap::LGeneratorHashMap()
{

}


LGeneratorHashMap::~LGeneratorHashMap()
{

}


void 
LGeneratorHashMap::Generate(   const string /*outfile*/, 
	                    vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                    vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const
{
    FORCE_DEBUG( "levels.size() = %d",    levels.size() );
    FORCE_DEBUG( "systems.size() = %d",   systems.size() );

    GenerateInitHashLogLevel( systems );
    GenerateInitHashSystem2String( systems );
    GenerateInitHashLevel2String( levels );
    GenerateInitHashLogTags( levels, systems );

}	


vector<string>   
LGeneratorHashMap::GenerateInitHashLogTags(  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels,
	                                             vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const
{
    vector<string> lines;
    lines.push_back("   void");
    lines.push_back("   LHashMapsBase::InitHashLogTags()");
    lines.push_back("   {");

    for (auto sys : systems)
    {
        vector<string> tags;
        
      ///  string tmp = "fSubCmdHash.emplace(" + "--fsm-off" +"," + "std::make_pair(eMSGSYSTEM::SYS_" + "FSM" + "," + "eMSGLEVEL::LOG_OFF));";
        
        tags.push_back(sys->fTag);
        if (sys->fTag != sys->fTagShort)
        {
            tags.push_back(sys->fTagShort);
        }

        for (auto tag : tags)
        {
        
            lines.push_back( g_utilities()->TabAlign("\tfSubCmdHash.emplace(\"" + tag + "-off\"" + ",", 5)  +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_OFF));");

            for (auto lvl : levels)
            {
               /// lvl->fName
                string tmptag = tag + "-" + g_string()->ToLower(lvl->fName);  
               //  lines.push_back("fSubCmdHash.emplace(\"" + tag + "-off" + ", " +  "std::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_OFF));");   
               lines.push_back(  g_utilities()->TabAlign( "\tfSubCmdHash.emplace(\"" + tmptag + "\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_"+ lvl->fName  +"));");   
            }

            lines.push_back(  g_utilities()->TabAlign("\tfSubCmdHash.emplace(\"" + tag + "-all\"" + ",", 5) +  "\tstd::make_pair(eMSGSYSTEM::SYS_" + sys->fName + ","	+ "  eMSGLEVEL::LOG_ALL));");

        }
        lines.push_back("\n");
    }

    lines.push_back("   }");

    for (auto l : lines)
    {
        cout << l << endl;
    }

    return lines;
}                                                 



vector<string>   
LGeneratorHashMap::GenerateInitHashLevel2String (  vector< std::shared_ptr<LXmlEntityLogLevel  > >  levels ) const
{
    vector<string> lines;
    lines.push_back("   void" );
    lines.push_back("   LHashMapsBase::InitHashLevel2String()");
    lines.push_back("   {");

    lines.push_back("\tfLevel2StringHash.emplace(eMSGLEVEL::LOG_OFF, \"OFF\");");
    lines.push_back("\tfLevel2StringHash.emplace(eMSGLEVEL::LOG_FORCE_DEBUG, \"Force_Debug\");");

    for( auto lvl: levels )
    {
        std::stringstream buffer; 
        buffer << "\tfLevel2StringHash.emplace(eMSGLEVEL::" << "LOG_" << lvl->fName << ",\t" << "\"" << g_string()->ToPascalCase(  lvl->fName ) << "\"" ");";
        lines.push_back(  buffer.str()  );
    }

    lines.push_back("\tfLevel2StringHash.emplace(eMSGLEVEL::LOG_ALL, \"ALL loglevels\");");
    lines.push_back("   }");

//  for (auto l : lines)
//     {
//         cout << l << endl;
//     }


    return lines;

}


vector<string>   
LGeneratorHashMap::GenerateInitHashSystem2String( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const
{
    vector<string> lines;
    lines.push_back("   void");
    lines.push_back("   LHashMapsBase::InitHashSystem2String()");
    lines.push_back("   {");
    lines.push_back( "\tfSystem2StringHash.emplace(eMSGSYSTEM::SYS_EX,       \"Exeption\");");
    lines.push_back( "\tfSystem2StringHash.emplace(eMSGSYSTEM::SYS_GENERAL,  \"General\");");
    lines.push_back( "\tfSystem2StringHash.emplace(eMSGSYSTEM::SYS_USER,     \"User\");");
    lines.push_back( "\tfSystem2StringHash.emplace(eMSGSYSTEM::SYS_NONE,     \"System Unknown\");");
    
    for (auto sys : systems)
    {
        std::stringstream buffer; 
        buffer << "\t" << "fSystem2StringHash.emplace(eMSGSYSTEM::" << "SYS_" << sys->fName + ", ";
        buffer <<  "\t" << "\"" +  g_string()->ToPascalCase (sys->fName )  + "\");";
        lines.push_back (  buffer.str() ) ;
    }

    lines.push_back("   }");
    //  for (auto l : lines)
    //  {
    //     cout << l << endl;
    //  }
    return lines;
}


vector<string>   
LGeneratorHashMap::GenerateInitHashLogLevel( vector< std::shared_ptr<LXmlEntitySubSystem > >  systems ) const
{
    vector<string> lines;

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

    for (auto sys : systems)
    {
        std::stringstream buffer;
        buffer << "\t" + g_utilities()->TabAlign("fLogLevelHash.emplace(" + fSystemEnumName + "::" + "SYS_" + sys->fName + ", ");
        buffer << "(eMSGLEVEL)PAD( (int)eMSGLEVEL::LOG_" + sys->fDefault + ") );";
        lines.push_back(buffer.str());
        //FORCE_DEBUG("name = %s", buffer.str().c_str() );
    }

    lines.push_back("   }");

    // for (auto l : lines)
    // {
    //     cout << l << endl;
    // }

    return lines;
}	 	