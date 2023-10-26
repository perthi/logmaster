

LIBNAME_SO:= libcmdline.so
LIBNAME_A:= libcmdline.a


SRCCPP+= GArgument.cpp \
	GArgumentParsed.cpp \
	GCmdApi.cpp \
	GCmdScan.cpp \
	GCommandLineArgument.cpp \
	GLogApplication.cpp \
	GCmdWiki.cpp \
	GLogHelpers.cpp 


include ../../common.mk

