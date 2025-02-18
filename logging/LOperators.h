
#pragma once

namespace LOGMASTER
{

inline eMSGSYSTEM operator | ( const eMSGSYSTEM &lhs, const eMSGSYSTEM &rhs )
    {
        return (eMSGSYSTEM)((int)lhs | (int)rhs);
    }

    inline eLOGLEVEL operator | ( const eLOGLEVEL &lhs, const eLOGLEVEL &rhs )
    {
        return (eLOGLEVEL)((int)lhs | (int)rhs);
    }

    inline eMSGFORMAT operator | ( const eMSGFORMAT &lhs, const eMSGFORMAT &rhs )
    {
        return (eMSGFORMAT)((int)lhs | (int)rhs);
    }

    inline eMSGTARGET operator | ( const eMSGTARGET &lhs, const eMSGTARGET &rhs )
    {
        return (eMSGTARGET)((int)lhs | (int)rhs);
    }

    inline eMSGSYSTEM operator & ( const eMSGSYSTEM &lhs, const eMSGSYSTEM &rhs )
    {
        return (eMSGSYSTEM)((int)lhs & (int)rhs);
    }

    inline eLOGLEVEL operator & ( const eLOGLEVEL &lhs, const eLOGLEVEL &rhs )
    {
        return (eLOGLEVEL)((int)lhs & (int)rhs);
    }

    inline eMSGFORMAT operator & ( const eMSGFORMAT &lhs, const eMSGFORMAT &rhs )
    {
        return (eMSGFORMAT)((int)lhs & (int)rhs);
    }

    inline eMSGTARGET operator & ( const eMSGTARGET &lhs, const eMSGTARGET &rhs )
    {
        return (eMSGTARGET)((int)lhs & (int)rhs);
    }


}
