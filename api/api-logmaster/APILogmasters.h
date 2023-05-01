// -*- mode: c++ -*-

#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <logging/LLogging.h>
#include <logging/LHashMaps.h>
#include <logging/LEnums.h>
#include "APILogmaster.h"
#include <map>
#include <vector>

using std::pair;
using std::map;
using namespace LOGMASTER;


class APILogMasters
{
public:
    APILogMasters();
    ~APILogMasters();
    API static APILogMasters* Instance();
    inline APILogmaster* GetCurrent(){return fLogMasters[fCurrentTarget]; }
    inline int GetCurrentTarget() {return (int)fCurrentTarget;}
    inline void SetCurrent(eMSGTARGET target){ fCurrentTarget = target; }
    inline void SetCurrent(int target) { fCurrentTarget = (eMSGTARGET)target; }
    inline std::vector<APILogmaster*> &GetLogMasterList() {return fLogMasterList; }
    
private:
    APILogMasters  operator=(const APILogMasters&);
    APILogMasters(const APILogMasters&);
    map<eMSGTARGET, APILogmaster*> fLogMasters{};
    eMSGTARGET fCurrentTarget = eMSGTARGET::TARGET_GUI;
    LOGMASTER::LLogging *fLogHandle = nullptr;
    std::vector<APILogmaster*> fLogMasterList = std::vector<APILogmaster*>();
    LHashMaps fHashMap{};
    
};
