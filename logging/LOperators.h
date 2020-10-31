
#pragma once

namespace LOGMASTER
{

inline eMSGSYSTEM operator | ( const eMSGSYSTEM &lhs, const eMSGSYSTEM &rhs )
	{
		return (eMSGSYSTEM)((int)lhs | (int)rhs);
	}

	inline eMSGLEVEL operator | ( const eMSGLEVEL &lhs, const eMSGLEVEL &rhs )
	{
		return (eMSGLEVEL)((int)lhs | (int)rhs);
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

	inline eMSGLEVEL operator & ( const eMSGLEVEL &lhs, const eMSGLEVEL &rhs )
	{
		return (eMSGLEVEL)((int)lhs & (int)rhs);
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
