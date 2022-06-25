// -*- mode: c++ -*-

/****************************************************
* Copyright: Embedded Consulting AS and others.
* For more information please contact pth@embc.no
******************************************************/
#include "APILogmasterBitmap.h"

#include <bitset>

/** @brief      Set
*   @details    This Function will adjust the bit map to enable levels above current level 
*   @param[in]  level - level to adjust on or off
*   @param[in]  enable - enable or disable selected level */
void 
APILogmasterBitmap::Set(const eMSGLEVEL level, bool enable)
{
    if (enable)
    {
        switch (level)
        {
            case eMSGLEVEL::LOG_DEBUG   :   fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_DEBUG | eMSGLEVEL::LOG_INFO | eMSGLEVEL::LOG_WARNING | eMSGLEVEL::LOG_ERROR | eMSGLEVEL::LOG_FATAL);
                break;
            case eMSGLEVEL::LOG_INFO    :   fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_INFO | eMSGLEVEL::LOG_WARNING | eMSGLEVEL::LOG_ERROR | eMSGLEVEL::LOG_FATAL);
                break;
            case eMSGLEVEL::LOG_WARNING :   fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_WARNING | eMSGLEVEL::LOG_ERROR | eMSGLEVEL::LOG_FATAL);
                break;
            case eMSGLEVEL::LOG_ERROR   :   fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_ERROR | eMSGLEVEL::LOG_FATAL);
                break;
            case eMSGLEVEL::LOG_FATAL   :   fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_FATAL);
                break;
            case eMSGLEVEL::LOG_OFF     :   
                fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_OFF);
                break;  
            case eMSGLEVEL::LOG_ALL     :   
                fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_ALL);
                break;
            case eMSGLEVEL::LOG_FORCE_DEBUG     :   
                fBitMap |= Level2Bitmap(eMSGLEVEL::LOG_FORCE_DEBUG);
                break;    
        }

    }
    else
    {

        fBitMap &= ~ Level2Bitmap(level);
    }
    
    return;
}

