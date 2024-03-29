// -*- mode: c++ -*-

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the UTILITIESDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// UTILITIESDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UTILITIESDLL_EXPORTS
#define UTILITIESDLL_API __declspec(dllexport)
#else
#define UTILITIESDLL_API __declspec(dllimport)
#endif

// This class is exported from the utilities-dll.dll
class UTILITIESDLL_API Cutilitiesdll {
public:
	Cutilitiesdll(void);
	// TODO: add your methods here.
};

extern UTILITIESDLL_API int nutilitiesdll;

UTILITIESDLL_API int fnutilitiesdll(void);
