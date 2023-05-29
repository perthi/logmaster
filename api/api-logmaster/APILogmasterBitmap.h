// -*- mode: c++ -*-

#pragma once

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/

#include <logging/LLogging.h>

using namespace LOGMASTER;


// This class is needed to handle eLOGLEVEL/eMSGSYSTEM bitmaps
class APILogmasterBitmap
{
public:
    APILogmasterBitmap(const eLOGLEVEL level, const eMSGSYSTEM system) { fBitMap = Level2Bitmap(level) | System2Bitmap(system); }
    APILogmasterBitmap(const eMSGSYSTEM system, const eLOGLEVEL level) { fBitMap = Level2Bitmap(level) | System2Bitmap(system); }
    APILogmasterBitmap(int bitmap) { fBitMap = bitmap; }
    APILogmasterBitmap(const APILogmasterBitmap& rhs) { fBitMap = rhs.fBitMap; }
    int GetBitmap() { return(fBitMap); }
    eLOGLEVEL GetLevel() { return(Bitmap2Level(fBitMap)); }
    eMSGSYSTEM GetSystem() { return(Bitmap2System(fBitMap)); }
    bool operator==(const eLOGLEVEL level) { return((Level2Bitmap(level) & fBitMap) != 0); }
    bool operator==(const eMSGSYSTEM system) { return((System2Bitmap(system) & fBitMap) != 0); }
    
    API void Set(const eLOGLEVEL level, bool enable);

    // These 4 functions handles all conversion
    static int Level2Bitmap(const eLOGLEVEL level) { return(((int)level << (int)eLEVELSHIFT) & (int)eLEVELMASK); }
    static int System2Bitmap(const eMSGSYSTEM system) { return(((int)system << (int)eSYSTEMSHIFT) & (int)eSYSTEMMASK); }
    static eLOGLEVEL Bitmap2Level(const int bitmap) { return((eLOGLEVEL)(((int)bitmap & (int)eLEVELMASK) >> eLEVELSHIFT)); }
    static eMSGSYSTEM Bitmap2System(const int bitmap) { return((eMSGSYSTEM)(((int)bitmap & (int)eSYSTEMMASK) >> eSYSTEMSHIFT)); }
private:
    enum LogmasterBitmapConstants
    {
        eLEVELSHIFT = 16,
        eLEVELMASK = 0x3F0000,
        eSYSTEMSHIFT = 0,
        //eSYSTEMMASK = 0x0FFFF
        eSYSTEMMASK = 0x01FFF
        
    };
    int fBitMap = 0;
};
