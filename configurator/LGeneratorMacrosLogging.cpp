// -*- mode: c++ -*-



#include  <configurator/LGeneratorMacrosLogging.h>
#include  <configurator/LCopyright.h>
#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <utilities/GUtilities.h>
#include  <logging/LLogApi.h>
using namespace LOGMASTER;

#include <sstream>



LGeneratorMacrosLogging::LGeneratorMacrosLogging( const string name,  const string xml, const string xsd) : LGenerator( name, xml, xsd)
{

}




LGeneratorMacrosLogging::LMacroEntry 
LGeneratorMacrosLogging::GenerateMacroEntry(  std::shared_ptr<LXmlEntityLogLevel> lvl, 
                                             std::shared_ptr<LXmlEntitySubSystem >  sys, 
                                             bool with_user ) const
{
    vector<LMacroName> names;
    vector<LSystem> systems;
    string user = with_user == true ? "_U" : "";
    names.push_back(LMacroName( sys->fName + "_" + lvl->fName + user, false));

    if (with_user == false)
    {
        names.push_back( LMacroName( sys->fName + "_" + "ASSERT_" + lvl->fName, true )) ;

    
    }

    if (sys->fName != sys->fNameShort)
    {
        names.push_back(LMacroName(sys->fNameShort + "_" + lvl->fName + user, false));
        if (with_user == false)
        {
            names.push_back( LMacroName( sys->fNameShort + "_" + "ASSERT_" + lvl->fName, true ) ) ;
        }
    }

    systems.push_back(LSystem(sys->fName));

    if (with_user == true)
    {
        systems.push_back(LSystem("USER"));
    }
    return  LMacroEntry( lvl->fName , names, systems  );
}





vector<string> 
LGeneratorMacrosLogging::Generate(  vector<std::shared_ptr<LXmlEntityLogLevel > > levels,
	                                vector<  std::shared_ptr< LXmlEntitySubSystem > >  systems )
{
    vector<string>     lines_common = GenerateCommon(  );
    std::stringstream  buffer;
    vector<string>     lines;


    lines.insert(lines.end(), lines_common.begin(), lines_common.end());

    for (auto &sys : systems)
    {
        for (auto &lvl : levels)
        {
            vector<LMacroEntry> entries;
            LMacroEntry e = GenerateMacroEntry(lvl, sys, false);
            entries.push_back(LMacroEntry(e));
            e = GenerateMacroEntry(lvl, sys, true);
            entries.push_back(LMacroEntry(e));
            vector<string> new_lines = GenerateLines(entries);
            lines.insert(lines.end(), new_lines.begin(), new_lines.end());
            lines.push_back("\n");
        }
        lines.push_back("\n\n\n");
    }

    lines.push_back("\n\n");
    lines.push_back( "#endif" );
    lines.push_back("\n\n");

    return lines;
}


vector<string> 
LGeneratorMacrosLogging::GenerateLines( const vector<LMacroEntry>  m_entries  )  const
{
  vector<string> lines;

    for( auto &entry: m_entries )
    {
    
        for ( auto &m: entry.fMacroNames)
        {
            string line;
            line = GenerateLine(  m , entry.fSystems,  entry.fLevel );
            lines.push_back(line);
        } 
    }
    return lines;    
}



string  
LGeneratorMacrosLogging::GenerateLine( const LMacroName m,  const vector<LSystem> s, const string lvl  ) const
{
    std::stringstream buffer;
    buffer << "#define ";

    if (m.fIsAssert == true)
    {
        buffer << g_utilities()->TabAlign(m.fMacroName + "(expr, ...) " + "\tif ( ! (expr) )", 7);
        buffer << "LLogging::Instance()->Log( " + fLevelEnumName + "::";
    }
    else
    {
        buffer << g_utilities()->TabAlign(m.fMacroName + "(...) ", 7);
        buffer << "LLogging::Instance()->Log( " + fLevelEnumName + "::";
    }

    buffer << "LOG_" << lvl << ",    ";
    size_t sz = s.size();

    for (size_t i = 0; i < sz; i++)
    {
        if (i > 0 && sz > 1)
        {
            buffer << " | ";
        }

        buffer << fSystemEnumName << "::" << "SYS_" <<s.at(i).fSystem;
    }

    buffer << ", ";
    buffer << "GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)";
    
    return buffer.str();
}


/** 

*/
vector<string>  
LGeneratorMacrosLogging::GenerateCommon(    ) 
{
   // vector<string> lines;
    //lines.push_back("// -*- mode: c++ -*-\n\n\n");
    //lines.push_back( LCopyright().Copyright() + "\n\n\n\n");
 //   fFileLineEntries

  //  fFileLineEntries.push_back( autoclause );
    fFileLineEntries.push_back("#ifdef _WIN32");
    fFileLineEntries.push_back("#define __func__ __FUNCTION__");
    fFileLineEntries.push_back("#endif");
    fFileLineEntries.push_back("#include  <logging/LEnums.h>");
    fFileLineEntries.push_back("#include  <logging/LLogging.h>");
    fFileLineEntries.push_back("#include  <logging/LOperators.h>");
    fFileLineEntries.push_back("#include  <utilities/GDefinitions.h>");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#ifdef ERROR");
    fFileLineEntries.push_back("#undef ERROR");
    fFileLineEntries.push_back("#endif");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#ifdef __cplusplus");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#include <utilities/GLocation.h>");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define SET_LOGLEVEL(level)          LLogging::Instance()->SetLogLevel(level )");
    fFileLineEntries.push_back("#define SET_LOGFORMAT(format )       LLogging::Instance()->SetLogFormat(format )");
    fFileLineEntries.push_back("#define SET_LOGTARGET(target )       LLogging::Instance()->SetLogTarget(target )");
    fFileLineEntries.push_back("#define SET_LOGFILENAME(filename)    LLogging::Instance()->SetLogFileName(filename )");
    fFileLineEntries.push_back("#define SET_APPLICATION(src)         LLogging::Instance()->SetApplication(src) ");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define PUSH()                       LLogging::Instance()->Push(  )");
    fFileLineEntries.push_back("#define POP()                        LLogging::Instance()->Pop(  )");
    fFileLineEntries.push_back("#define LOG_DATA(data, ...)          LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,  eMSGSYSTEM::SYS_DATA,  GLocation( __FILE__, __LINE__, __func__ ), data,  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_LOG(level, system, ...)    LLogging::Instance()->Log( level, system,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define FORCE_DEBUG(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_FORCE_DEBUG, eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define EX_ERROR(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define EX_FATAL(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_EX,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define ALARM_WARNING(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALARM_ERROR(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALARM_FATAL(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALARM_ASSERT_WARNING(expr, ...)    if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALARM_ASSERT_ERROR(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALARM_ASSERT_FATAL(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALARM,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_DEBUG(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_INFO(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_WARNING(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ERROR(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_FATAL(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ASSERT_DEBUG(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ASSERT_INFO(expr, ...)       if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ASSERT_WARNING(expr, ...)    if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ASSERT_ERROR(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define ALL_ASSERT_FATAL(expr, ...)      if( ! ( expr ))  LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_ALL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define G_DEBUG(...)                 LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_INFO(...)                  LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_WARNING(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ERROR(...)                 LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_FATAL(...)                 LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_GENERAL,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_DEBUG_U(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_INFO_U(...)                LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_WARNING_U(...)             LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ERROR_U(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_FATAL_U(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,	   eMSGSYSTEM::SYS_GENERAL | eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ASSERT_DEBUG(expr, ...)    if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,     eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ASSERT_INFO(expr,  ...)    if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ASSERT_WARNING(expr, ...)  if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ASSERT_ERROR(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define G_ASSERT_FATAL(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_GENERAL,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("\n\n");
    fFileLineEntries.push_back("#define USER_DEBUG(...)              LLogging::Instance()->Log(eLOGLEVEL::LOG_DEBUG,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_INFO(...)               LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,        eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_WARNING(...)            LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ERROR(...)              LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_FATAL(...)              LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_USER,   GLocation( __FILE__, __LINE__, __func__ ),  __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ASSERT_DEBUG(expr, ...)    if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::DEBUG,     eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ASSERT_INFO(expr,  ...)    if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_INFO,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ASSERT_WARNING(expr, ...)  if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_WARNING,     eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ASSERT_ERROR(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_ERROR,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("#define USER_ASSERT_FATAL(expr,  ...)   if(! (expr) ) LLogging::Instance()->Log(eLOGLEVEL::LOG_FATAL,       eMSGSYSTEM::SYS_USER,  GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)");
    fFileLineEntries.push_back("\n\n");

    //return lines;

    return fFileLineEntries;
}
