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
APILogmasterBitmap::Set(const eLOGLEVEL level, bool enable)
{
    if (enable)
    {
        switch (level)
        {
            case eLOGLEVEL::LOG_DEBUG   :   fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_DEBUG | eLOGLEVEL::LOG_INFO | eLOGLEVEL::LOG_WARNING | eLOGLEVEL::LOG_ERROR | eLOGLEVEL::LOG_FATAL);
                break;
            case eLOGLEVEL::LOG_INFO    :   fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_INFO | eLOGLEVEL::LOG_WARNING | eLOGLEVEL::LOG_ERROR | eLOGLEVEL::LOG_FATAL);
                break;
            case eLOGLEVEL::LOG_WARNING :   fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_WARNING | eLOGLEVEL::LOG_ERROR | eLOGLEVEL::LOG_FATAL);
                break;
            case eLOGLEVEL::LOG_ERROR   :   fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_ERROR | eLOGLEVEL::LOG_FATAL);
                break;
            case eLOGLEVEL::LOG_FATAL   :   fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_FATAL);
                break;
            case eLOGLEVEL::LOG_OFF     :   
                //fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_OFF);
                break;  
            case eLOGLEVEL::LOG_ALL     :   
                //fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_ALL);
                break;
            case eLOGLEVEL::LOG_FORCE_DEBUG     :   
                //fBitMap |= Level2Bitmap(eLOGLEVEL::LOG_FORCE_DEBUG);
                break;    
        }

    }
    else
    {

        fBitMap &= ~ Level2Bitmap(level);
    }
    
    return;
}

