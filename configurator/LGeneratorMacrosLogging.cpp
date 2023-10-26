// -*- mode: c++ -*-



#include  <configurator/LGeneratorMacrosLogging.h>
#include  <configurator/LCopyright.h>
#include  <configurator/LXmlEntityLogLevel.h>
#include  <configurator/LXmlEntitySubSystem.h> 
#include  <configurator/LGeneratorTestLConversion.h>
#include  <utilities/GUtilities.h>
#include  <logging/LLogApi.h>
using namespace LOGMASTER;

#include <sstream>


namespace CONFIGURATOR
{
    /** Class for generating macros used by the logging system
        @copydoc LGenerator */
    LGeneratorMacrosLogging::LGeneratorMacrosLogging(const string path, const string classname, const LXMLInfo xmlinfo) : LGenerator(path, classname, xmlinfo)
    {
        fDoGenerateHeader = true;
    }

    LGeneratorMacrosLogging::LMacroEntry
        LGeneratorMacrosLogging::GenerateMacroEntry( logentity_ptr lvl,
            sysentity_ptr sys,
            bool with_user) const
    {
        vector<LMacroName> names;
        vector<LSystem> systems;
        string user = with_user == true ? "_U" : "";
        names.push_back(LMacroName(sys->fName + "_" + lvl->fName + user, false));

        if (with_user == false)
        {
            names.push_back(LMacroName(sys->fName + "_" + "ASSERT_" + lvl->fName, true));


        }

        if (sys->fName != sys->fNameShort)
        {
            names.push_back(LMacroName(sys->fNameShort + "_" + lvl->fName + user, false));
            if (with_user == false)
            {
                names.push_back(LMacroName(sys->fNameShort + "_" + "ASSERT_" + lvl->fName, true));
            }
        }

        systems.push_back(LSystem(sys->fName));

        if (with_user == true)
        {
            systems.push_back(LSystem("USER"));
        }
        return  LMacroEntry(lvl->fName, names, systems);
    }





    void
        LGeneratorMacrosLogging::GenerateContent( const logentity_vec levels, const sysentity_vec  systems)
    {
        for (auto& sys : systems)
        {
            for (auto& lvl : levels)
            {
                vector<LMacroEntry> entries;
                LMacroEntry e = GenerateMacroEntry(lvl, sys, false);
                entries.push_back(LMacroEntry(e));
                e = GenerateMacroEntry(lvl, sys, true);
                entries.push_back(LMacroEntry(e));
                GenerateLines(entries);
             fFileContentHeader.push_back("\n");
            }
            fFileContentHeader.push_back("\n\n\n");
        }

        fFileContentHeader.push_back("\n\n");
    }


    void
        LGeneratorMacrosLogging::GenerateLines(const vector<LMacroEntry>  m_entries)
    {
        for (auto& entry : m_entries)
        {

            for (auto& m : entry.fMacroNames)
            {
                string line;
                line = GenerateLine(m, entry.fSystems, entry.fLevel);
                fFileContentHeader.push_back(line);
            }
        }
    }



    string
        LGeneratorMacrosLogging::GenerateLine(const LMacroName m, const vector<LSystem> s, const string lvl) const
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

            buffer << fSystemEnumName << "::" << "SYS_" << s.at(i).fSystem;
        }

        buffer << ", ";
        buffer << "GLocation( __FILE__, __LINE__, __func__ ),   __VA_ARGS__)";

        return buffer.str();
    }

}
