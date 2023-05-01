// -*- mode: c++ -*-

#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <logging/LLogging.h>
#include <logging/LEnums.h>
#include <logging/LHashMaps.h>

#include <utility>
#include <map>
#include <vector>

using std::pair;
using std::map;
using namespace LOGMASTER;

#include <vector>
using std::vector;
#include <memory>



/** @brief      APILogmasterData
*   @details    Common class used by APILogmasterSubSysControl, APILogmasterOutputTargets, APIMessageFormat and APISubSystemsAndLevelControl**/
class APILogmasterData
{
public:
    inline std::string GetName() { return(fName); }
    inline int GetValue() { return(fValue); }
    inline bool GetEnabled() {return (fEnabled);}
    inline int GetXLevel() { return (fX_Lev); }
    inline int GetYSystem() { return (fY_Sys); }
    inline int GetColor() { return (fColor); }

protected:
    
    std::string fName = "";
    int         fValue = 0;
    bool        fEnabled = false;
    int         fX_Lev = 0;
    int         fY_Sys = 0;
    int         fColor = 0;

    
};


/** @brief      APISubSystemsControl
*   @details    This class is made to return Logmaster subsystem Control text and Hex value definition (int)**/
class APISubSystemsControl : public APILogmasterData
{
public:
    inline APISubSystemsControl(std::string name, int value) { fName = name; fValue = value; }
    inline APISubSystemsControl(const APISubSystemsControl& rhs) { fName = rhs.fName; fValue = rhs.fValue; }
};


/** @brief      APIOutputTargets
*   @details    This class returns Logmaster Output Targets text, Hex value definition (int) and if target is enabled (bool).**/
class APIOutputTargets : public APILogmasterData
{
public:
    inline APIOutputTargets(std::string name, int value, bool enabled) { fName = name; fValue = value; fEnabled = enabled; }
    inline APIOutputTargets(const APIOutputTargets& rhs) { fName = rhs.fName; fValue = rhs.fValue; fEnabled = rhs.fEnabled;}
};


/** @brief      APIMessageFormat
*   @details    This class returns the Logmaster Message Format text, Hex value definition (int) and an enable bit (bool).**/
class APIMessageFormat : public APILogmasterData
{
public:
    inline APIMessageFormat(std::string name, int value, bool enabled) { fName = name; fValue = value; fEnabled = enabled;}
    inline APIMessageFormat(const APIMessageFormat& rhs) { fName = rhs.fName; fValue = rhs.fValue; fEnabled = rhs.fEnabled;}
};

/** @brief      APISubSysAndLevControl
*   @details    This class returns the Logging System and Level control name, x-y coordinates, color and enable bit.**/
class APISubSysAndLevControl : public APILogmasterData
{
public:
    inline APISubSysAndLevControl(std::string name, int x_Lev, int y_Sys, int color, bool enabled) { fName = name; fX_Lev = x_Lev; fY_Sys = y_Sys; fColor = color; fEnabled = enabled; }
    inline APISubSysAndLevControl(const APISubSysAndLevControl& rhs) { fName = rhs.fName; fX_Lev = rhs.fX_Lev; fY_Sys = rhs.fY_Sys; fColor = rhs.fColor; fEnabled = rhs.fEnabled; }
};


class APILogmaster 
{
public:
    static  API APILogmaster*               Instance();
    void    API                             SetLoggingTarget(const  string  &target);
    API std::vector<APISubSystemsControl>   GetSubSystemsControl();
    API std::vector<APIOutputTargets>       GetOutputTargets();
    API std::vector<APIMessageFormat>       GetMessageFormat();
    API std::vector<APISubSysAndLevControl> GetSubSysAndLevControl();
    API bool                                GetOutputTargetEnabled(int target);
    inline  int                             GetTargetInt(){return (int)fTarget;}
    void    API                             SetOutputTarget(string target, bool enable);
    void    API                             SetMessageFormat(string format, bool enable);
    void    API                             SetSubSystem(string system);
    void    API                             SetSubSysAndLevControl(int x_Lev, int y_Sys, bool enable);
    void    API                             WriteTestMessages();

    inline std::vector<string>              GetTextFieldData() { return (fText); }
    inline void                             ClearTextFieldData() { fText.clear(); }
    inline void                             SetTextFieldData(string text) { fText.push_back(text); }
    inline string                           GetTargetName() {return fTargetName; }
    
private:
    APILogmaster(string targetName, eMSGTARGET target);
    ~APILogmaster();
    APILogmaster operator=(const  APILogmaster &);
    APILogmaster  (const  APILogmaster &);
    
    void        ConvertXYToLevSys(int x_lev, int y_Sys, eMSGLEVEL *lvl, eMSGSYSTEM *sys);
    bool        IsLevSysEnabled(int x_lev, int y_Sys);
    void        SetNumberOfSystems();
    void        SetNumberOfLevels();
    inline int  GetNumberOfSystems() { return fSystemsCount; }
    inline int  GetNumberOfLevels() { return fLevelsCount; }
    bool        isLevelEnabledForAllSystems(eMSGLEVEL level);
    bool        isSystemEnabledForAllLevels(eMSGSYSTEM system);
    bool        isAllSystemAndAllLevelsEnabled();

    friend class APILogMasters;

    LOGMASTER::LLogging *fLogHandle = nullptr;
    eMSGTARGET fTarget = eMSGTARGET::TARGET_GUI; // default GUI
    string fTargetName = "--target-gui";
    std::vector<string> fText =std::vector<string>();
    bool fAllFieldsMessageFormatEnable = false; // Keep track of Message Format --all-off for correct togling of GUI check box.
    std::map < std::pair<int, int>, std::pair<eMSGLEVEL, eMSGSYSTEM> > fSybSysLevelXYTrack =   std::map < std::pair<int, int>, std::pair<eMSGLEVEL, eMSGSYSTEM> > (); // Keep track of X/Y position in GUI and mapping towards level and system 
    int fSystemsCount = 0;
    int fLevelsCount = 0;

    map<eMSGLEVEL, string> fLevels =   map<eMSGLEVEL, string>(); 
    map<eMSGSYSTEM, string> fSystems =  map<eMSGSYSTEM, string>();

    LHashMaps* fHashMap = nullptr;

};
