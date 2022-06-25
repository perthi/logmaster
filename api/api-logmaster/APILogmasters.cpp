// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include "APILogmasters.h"
#include "APILogmaster.h"
#include <logging/LHashMaps.h>



// APILogMasters is handling x numbers of Logmasters, one for each target

APILogMasters::APILogMasters()
{
    fLogHandle = LLogging::Instance();

    for ( auto it = fHashMap.GetTargetHash()->begin(); it != fHashMap.GetTargetHash()->end(); it ++ )
    {
        // Skip target OFF and ALL
        if (it->second == eMSGTARGET::TARGET_OFF || it->second == eMSGTARGET::TARGET_ALL)
        {
            continue;
        }
    
        APILogmaster* logmaster = new APILogmaster( it->first, it->second);
        
        fLogMasters.emplace( it->second, logmaster);
        
        if( it->second != eMSGTARGET::TARGET_GUI)
        {
            fLogMasterList.push_back(logmaster);
        }
    }
    
    if (fLogMasters.find(eMSGTARGET::TARGET_GUI) != fLogMasters.end())
    {
        SetCurrent(eMSGTARGET::TARGET_GUI); 
        // Add GUI at beginning of the vector/list.
        fLogMasterList.insert(fLogMasterList.begin(), fLogMasters.at(eMSGTARGET::TARGET_GUI));
    }
    else
    {
        SetCurrent(fLogMasters.begin()->first);
    }
    
    fLogHandle->SetLogTarget(GetCurrent()->GetTargetName());
}


APILogMasters::~APILogMasters()
{
    for  (auto logmaster : fLogMasters)
    {
            delete logmaster.second;
    }
}


APILogMasters 
* APILogMasters::Instance()
{
    static APILogMasters *instance = new APILogMasters();
    return instance;
}

