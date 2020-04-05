
PROGRAM:= version-info
#LIBNAME_SO:= libversion-info.so

SRCCPP+=	version-info.cpp \
		GGenerateVersionInfo.cpp

LIBS+=  -lpthread  

include ../../common.mk
