// -*- mode: c++ -*-

#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <logging/LLogging.h>
#include <logging/LHashMaps.h>
#include <common/FDefinitions.h>
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
    map<eMSGTARGET, APILogmaster*> fLogMasters;
    eMSGTARGET fCurrentTarget;
    LOGMASTER::LLogging *fLogHandle = nullptr;
    std::vector<APILogmaster*> fLogMasterList;
    LHashMaps fHashMap;
    
};
