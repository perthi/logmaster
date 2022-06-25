// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/


#include "APILogmaster.h"
#include "APILogmasters.h"
#include "APILogmasterBitmap.h"

#include <logging/LConfig.h>
#include <logging/LColorMap.h>
#include <logging/LLogTest.h>
#include <bitset>

#include <logging/LLogApi.h>
using namespace LOGMASTER;

APILogmaster* APILogmaster::Instance()
{
    return APILogMasters::Instance()->GetCurrent();
}



APILogmaster::APILogmaster(string targetName, eMSGTARGET target)
{
    //fHashMap = new LHashMaps( eMSGLEVEL::LOG_WARNING );
    fHashMap = new LHashMaps( );

    fLogHandle = LLogging::Instance();

    if (fLogHandle == nullptr)
    {
        //USER_WARNING("Can't initialize logmaster, returned zero pointer" );
    }

    // Get Log levels and and systems, these variables does not change during runtime
    fLevels =  *fHashMap->GetLevel2StringHash();
    fSystems = *fHashMap->GetSystem2StringHash();

    // Set number of Systems and Levels, these variables does not change during runtime
    SetNumberOfSystems();
    SetNumberOfLevels();

    fTargetName  = targetName;
    fTarget = target;
}


APILogmaster::~APILogmaster()
{
}



/** @brief      SetLoggingTarget
*   @details    This Function will Set the Logging target, and then get the target
*               from the loggingsystem before updating the local variable
*   @param[in]  target **/
void
APILogmaster::SetLoggingTarget(const  string  &target)
{
    ///@todo OLP must be removed when the tabs is in place
    fLogHandle->SetLogTarget(target);
    fTarget = fLogHandle->GetLogTarget();
}


/** @brief      GetSubSystemsControl
*   @details    This Function will return a vector with object APISubSystemsControl that
*               contain Logmaster subsystem Control text and Hex value definition (int)
*   @return     vector<APISubSystemsControl>  */
std::vector<APISubSystemsControl>
APILogmaster::GetSubSystemsControl()
{
    std::vector<APISubSystemsControl> v;

    auto config = LLogging::Instance()->GetConfig(fTarget);

    for (auto tag : *(config->GetHash()->GetSubCmdHash()))
    {
        v.push_back(APISubSystemsControl(tag.first.c_str(), (int64_t)std::get<0>(tag.second)));
    }

    return v;
}


/** @brief      APIOutputTargets
*   @details    This Function will return a vector with object APIOutputTargets that contains
*               logmaster Output Targets text, Hex value definition (int) and if target is enabled (bool).
*               TARGET_OFF and TARGET_ALL is not included.
*   @return     vector<APIOutputTargets> */
std::vector<APIOutputTargets>
APILogmaster::GetOutputTargets()
{

    std::vector<APIOutputTargets> v;
    
    for (auto target : *fHashMap->GetTargetHash())
    {
        // Skip target OFF and ALL
        if (target.second == eMSGTARGET::TARGET_OFF || target.second == eMSGTARGET::TARGET_ALL)
        {
            continue;
        }
        bool enabled = (bool) ((int64_t)target.second & (int)fLogHandle->GetLogTarget());
        v.push_back(APIOutputTargets(target.first.c_str(), (int64_t)target.second, enabled));
    }
    return v;
}


/** @brief      GetMessageFormat
*   @details    This Function will return a vector with object APIMessageFormat that
*               contain the Message Format text, Hex value definition (int) and an enable bit (bool).
*   @return     vector<APIMessageFormat>  */
std::vector<APIMessageFormat>
APILogmaster::GetMessageFormat()
{
    std::vector<APIMessageFormat> v;
    bool enabled = false;
    
    for (auto format : * fHashMap->GetFormatHash())
    {
        //Special case for ALL_FIELDS_OFF
       if (format.second == eMSGFORMAT::ALL_FIELDS_OFF)
        {
            //enabled = fAllFieldsMessageFormatEnable;
        }
       else
        {
            // get bitmap from LoFormat(better name GetMsgFormat)
            int targetLogformat = (int)fLogHandle->GetLogFormat(fTarget);
            // bool enabled if format is in targetLogformat. 
            enabled = ((int64_t)format.second & targetLogformat) == (int64_t)format.second;
            if(enabled)
            {
                fAllFieldsMessageFormatEnable = false;
            }
        }

        v.push_back(APIMessageFormat(format.first, (int64_t)format.second, enabled));
    }
    
    return v;
}


/** @brief      GetSubSysAndLevControl
*   @details    This Function will return a vector with object APISubSysAndLevControl that
*               contain the Logging System and Level control name, x-y coordinates, color and enable bit.
*   @return     vector<APISubSysAndLevControl> */
std::vector<APISubSysAndLevControl> 
APILogmaster::GetSubSysAndLevControl()
{
    std::vector<APISubSysAndLevControl> v;
    bool enable = false;            // used to enable or disable buttons
    int x_lev = 0;                  // Columns - Rows
    int y_sys = 0;                  // System - Columns
    fSybSysLevelXYTrack.clear();    // clear data to XY vs Sys / Lev map

    // Step through all Loggin System, except SYS_NONE and SYS_DB_ALL
    for (auto sys = fSystems.rbegin(); sys != fSystems.rend(); sys++)
    {
        //Skip none system
        if (sys->first == eMSGSYSTEM::SYS_NONE)     continue;
        
        //Make Select all button if SYS_ALL.
        if (sys->first == eMSGSYSTEM::SYS_ALL)
        {
            enable = isAllSystemAndAllLevelsEnabled();
            v.push_back(APISubSysAndLevControl("Select All", x_lev, y_sys, (LColorMap::Instance()->GetRGB(eMSGLEVEL::LOG_ALL)), enable));
            fSybSysLevelXYTrack.emplace(std::make_pair(x_lev, y_sys), std::make_pair(eMSGLEVEL::LOG_ALL, sys->first));
        }

        // Reset x_lev for every restart of system increment.
        x_lev = 0;

        // Stet through all Logging Levels, except for LOG_OFF and LOG_FORCE_DEBUG
        for (auto lvl = fLevels.rbegin(); lvl != fLevels.rend(); lvl++)
        {
            if (lvl->first == eMSGLEVEL::LOG_OFF)           continue;
            if (lvl->first == eMSGLEVEL::LOG_FORCE_DEBUG)   continue;

            // Add data to XY vs Sys/Lev map
            fSybSysLevelXYTrack.emplace(std::make_pair(x_lev, y_sys), std::make_pair(lvl->first, sys->first));

            // Use level name for button
            if (sys->first == eMSGSYSTEM::SYS_ALL && lvl->first != eMSGLEVEL::LOG_ALL) 
            {       
                enable = isLevelEnabledForAllSystems(lvl->first);
                v.push_back(APISubSysAndLevControl(lvl->second, x_lev, y_sys, (LColorMap::Instance()->GetRGB(lvl->first)), enable));
            }
            // Use system name for button
            if (sys->first != eMSGSYSTEM::SYS_ALL && lvl->first == eMSGLEVEL::LOG_ALL) 
            {
                enable = isSystemEnabledForAllLevels(sys->first);
                v.push_back(APISubSysAndLevControl(sys->second, x_lev, y_sys, (LColorMap::Instance()->GetRGB(lvl->first)), enable));
            }
            // Use On/Off name for all other buttons
            if (sys->first != eMSGSYSTEM::SYS_ALL && lvl->first != eMSGLEVEL::LOG_ALL) 
            {
                enable = IsLevSysEnabled(x_lev, y_sys);
                v.push_back(APISubSysAndLevControl(enable ? "On" : "Off", x_lev, y_sys, (LColorMap::Instance()->GetRGB(lvl->first)), enable));
            }
            // Increment X to go to next level (5 Levels)
            x_lev++;    
        }
        // Increment Y to go to next system (11 systems)
        y_sys++;
    }   
    /// Print out Vector for debug
    ///for (auto tmp : v)
    ///{
    /// USER_WARNING("%s %i %i %i %i", tmp.GetName().c_str(), tmp.GetXLevel(), tmp.GetYSystem(), tmp.GetColor(), (int)tmp.GetEnabled());
    ///}
    return v;
}

bool 
APILogmaster::GetOutputTargetEnabled(int target)
{

    for (auto it : GetOutputTargets())
    {
        if (target == it.GetValue())
        {
            if (it.GetEnabled())
            {
                return true;
            }
        }
    }
    return false;
}
    

/** @brief      isLevelEnabledForAllSystems
*   @details    This Function will return true if selected level is enabled for all systems
*   @param[in]  level The log level
*   @return     true or false (bool)**/
bool APILogmaster::isLevelEnabledForAllSystems(eMSGLEVEL level)
{
    int cnt = 0;


    for (auto sys = fSystems.rbegin(); sys != fSystems.rend(); sys++)
    {
        if(sys->first == eMSGSYSTEM::SYS_NONE)      continue;
    //  if(sys->first == eMSGSYSTEM::SYS_DB_ALL)     continue;

        for (auto lvl = fLevels.rbegin(); lvl != fLevels.rend(); lvl++)
        {
            if (lvl->first == eMSGLEVEL::LOG_OFF)           continue;
            if (lvl->first == eMSGLEVEL::LOG_FORCE_DEBUG)   continue;
            if (lvl->first == eMSGLEVEL::LOG_ALL)           continue;
                        
            bool enabled  = LLogging::Instance()->CheckLevel(sys->first, lvl->first, fTarget);
            if ((lvl->first == level) && (enabled))
            {
                cnt++;
            }
        }
    }

    if (cnt == GetNumberOfSystems())
    {
        return true;
    }
    return false;
}


/** @brief       isSystemEnabledForAllLevels
*   @details     This Function will return true if selected system is enabled for all levels
*   @param[in]   system eMSGSYSTEM system
*   @return      true or false (bool)**/
bool APILogmaster::isSystemEnabledForAllLevels(eMSGSYSTEM system)
{
    int cnt = 0;
    ///FORCE_DEBUG("TP0");
    
    for (auto lvl = fLevels.rbegin(); lvl != fLevels.rend(); lvl++)
    {
        if (lvl->first == eMSGLEVEL::LOG_OFF)           continue;
        if (lvl->first == eMSGLEVEL::LOG_FORCE_DEBUG)   continue;
        if (lvl->first == eMSGLEVEL::LOG_ALL)           continue;

        for (auto sys = fSystems.rbegin(); sys != fSystems.rend(); sys++)
        {
            if (sys->first == eMSGSYSTEM::SYS_NONE)     continue;
//          if (sys->first == eMSGSYSTEM::SYS_DB_ALL)   continue;

            if ((sys->first == system) && (LLogging::Instance()->CheckLevel(sys->first, lvl->first, fTarget)))
            {
                cnt++;
            }
        }
    }

    if (cnt == GetNumberOfLevels())
    {
        return true;
    }
    return false;
}


/** @brief      isAllSystemAndAllLevelsEnabled
*   @details    This Function will return true if All levels and and systems are ON
*   @return     true or false (bool)**/
bool APILogmaster::isAllSystemAndAllLevelsEnabled()
{
    int cnt = (int)isLevelEnabledForAllSystems(eMSGLEVEL::LOG_FATAL);
    cnt += (int)isLevelEnabledForAllSystems(eMSGLEVEL::LOG_ERROR);
    cnt += (int)isLevelEnabledForAllSystems(eMSGLEVEL::LOG_WARNING);
    cnt += (int)isLevelEnabledForAllSystems(eMSGLEVEL::LOG_DEBUG);
    cnt += (int)isLevelEnabledForAllSystems(eMSGLEVEL::LOG_INFO);

    if (cnt == GetNumberOfLevels())
    {
        return true;
    }
    return false;
}


/** @brief      SetOutputTarget
*   @details    This Function will try to adjust the LogTarget On or Off 
*   @param[in]  target as defined by the Logging system.
*   @param[in]  enable - true or false (bool)**/
void 
APILogmaster::SetOutputTarget(string target, bool enable)
{
    try
    {
        LLogging::Instance()->SetLogTarget(target, enable);

        // Update text vector for GUI text message window, add On/Off text
        string msg = target + (enable == true ? "  On" : "  Off");
        SetTextFieldData(msg);
    }
    catch (std::exception& e)
    {
        //G_ERROR("Could not set Output target to %s (%s)", target.c_str(), e.what());
    }
    return;
}


/** @brief      SetMessageFormat
*   @details    This Function will try to adjust the LogFormat On or Off
*   @param[in]  format as defined by the Logging system.
*   @param[in]  enable - true or false (bool)**/
void
APILogmaster::SetMessageFormat(string format, bool enable)
{
    string cmd = GetTargetName() + " " + format;

    try
    {
        
        LLogging::Instance()->SetLogFormat(cmd, enable);

        // Update text vector for GUI text message window
        string msg = cmd + (enable == true ? "  On" : "  Off");
        SetTextFieldData(msg);

        // Keep track of special case --all-off
        if (format == "--all-off")
        {
            fAllFieldsMessageFormatEnable = enable;
        }
    }
    catch (std::exception& e)
    {
        //G_ERROR("Could not set log target to %s (%s)", cmd.c_str(), e.what());
    }
    return;
}


/** @brief      SetSubSystem
*   @details    This Function will try to adjust to the coresponding Subsystem
*   @param[in]  system on string format, as defined by the Logging system.**/
void
APILogmaster::SetSubSystem(string system)
{
    string cmd = GetTargetName() + " " + system;

    try
    {
        LLogging::Instance()->SetLogLevel((cmd));
        SetTextFieldData(cmd);


        // Keep track of special case --all-off
        if (system == "--all-off")
        {
            fAllFieldsMessageFormatEnable = false;
        }
    }
    catch (std::exception& e)
    {
        //G_ERROR("Could not set SetSubSystem to %s (%s)", cmd.c_str(), e.what());
    }
    return;
}


/** @brief      SetSubSysAndLevControl
*   @details    This Function will try to adjust the System and Level On or Off
*   @param[in]  x_Lev - x position in the GUI matrix, also defined as level
*   @param[in]  y_Sys - y position in the GUI matrix, also defined as system
*   @param[in]  enable - true or false (bool)**/
void
APILogmaster::SetSubSysAndLevControl(int x_Lev, int y_Sys, bool enable)
{
    eMSGLEVEL lvl, levelActual;
    eMSGSYSTEM sys;
    
    ConvertXYToLevSys(x_Lev, y_Sys, &lvl, &sys);
    
    levelActual = LLogging::Instance()->GetLogLevel(sys, fTarget);
    
    if (lvl == eMSGLEVEL::LOG_ALL)
    {
        if (enable)
        {
            levelActual = lvl;
        }
        else
        {
            levelActual = eMSGLEVEL::LOG_OFF;
        }
    }

    APILogmasterBitmap bm(levelActual, sys);

    bm.Set(lvl, enable);

    int bitDesimal = bm.GetBitmap();

    // convert integer value to binary format of 24 bit as a string.
    string bitmap = std::bitset<24>(bitDesimal).to_string();
    
    string cmd = GetTargetName() + " " + bitmap;

    try
    {
        LLogging::Instance()->SetLogLevel((cmd));
        SetTextFieldData(cmd);
    }
    catch (std::exception& e)
    {
        //G_ERROR("Could not SetSubSysAndLevControl to %s (%s)", cmd.c_str(), e.what());
    }
    return;
}


/** @brief      TestMessages
*   @details    This Function will write a set of predefined Test messages**/
void
APILogmaster::WriteTestMessages()
{
    LLogTest::WriteMessages();
    return;
}


/** @brief      ConvertXYToLevSys
*   @details    This Function will convert x_Lev and y_Sys  coordinates to eMSGLEVEL and eMSGSYSTEM using the fSybSysLevelXYTrack map
*   @param[in]  x_Lev - x position in the GUI matrix, also defined as level
*   @param[in]  y_Sys - y position in the GUI matrix, also defined as system
*   @param[out] lvl - will return a pointer to message level 
*   @param[out] sys - will return a pointer to message system**/
void APILogmaster::ConvertXYToLevSys(int x_Lev, int y_Sys, eMSGLEVEL *lvl, eMSGSYSTEM *sys)
{
    for (auto map : fSybSysLevelXYTrack)
    {
        if (map.first.first == x_Lev && map.first.second == y_Sys)
        {
            *lvl = map.second.first;
            *sys = map.second.second;
        }
    }
    return;
}


/** @brief      IsLevSysEnabled
*   @details    This Function will use the ConvertXYToLevSys() function and check to see if the selected level and system is enabled against the loggins system.
*   @param[in]  x_lev - x position in the GUI matrix, also defined as level
*   @param[in]  y_Sys - y position in the GUI matrix, also defined as system**/
bool
APILogmaster::IsLevSysEnabled(int x_lev, int y_Sys)
{
    eMSGLEVEL selLvl;
    eMSGSYSTEM selSys;

    ConvertXYToLevSys(x_lev, y_Sys, &selLvl, &selSys);

    // Now check wether selected Level and system is enabled in the logging system.
    return LLogging::Instance()->CheckLevel(selSys, selLvl, fTarget);
}


/** @brief      SetNumberOfSystems
*   @details    This Function will use fSystems map to get the number of systems. fSystemsCount will be updated**/
void 
APILogmaster::SetNumberOfSystems() 
{ 
    // Step through all Loggin System, except SYS_NONE and SYS_DB_ALL
    for (auto sys = fSystems.rbegin(); sys != fSystems.rend(); sys++)
    {
        if (sys->first == eMSGSYSTEM::SYS_NONE)     continue;
//      if (sys->first == eMSGSYSTEM::SYS_DB_ALL)   continue;
    
        // Increment fSystemsCount for every registered systems. (11 systems)  
        fSystemsCount++; 
    }
}


/** @brief      SetNumberOfLevels
*   @details    This Function will use fLevels map to get the number of levels. fLevelsCount will be updated**/
void 
APILogmaster::SetNumberOfLevels() 
{ 
    // Step through all Logging Levels, except for LOG_OFF, LOG_FORCE_DEBUG and LOG_ALL
    for (auto lvl = fLevels.rbegin(); lvl != fLevels.rend(); lvl++)
    {
        if (lvl->first == eMSGLEVEL::LOG_OFF)           continue;
        if (lvl->first == eMSGLEVEL::LOG_FORCE_DEBUG)   continue;
        if (lvl->first == eMSGLEVEL::LOG_ALL)           continue;

        // Increment fLevelsCount for every registered levels. (5 Levels)
        fLevelsCount++;
    }
}