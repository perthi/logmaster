
PROGRAM:= version-info
LIBNAME_SO:= libversion-info.so

SRCCPP+=	version-info.cpp \
		VGenerateRCFile.cpp \
                VGenerateVersionInfo.cpp \
                VHelpers.cpp \
                VScanArguments.cpp \
                VVersionHeader.cpp



# LIBS+= -llogmaster -lutilities -lcmdline -lsqlite-embc  -ldl -lpthread -lreadline -lhistory -lncurses

LIBS+=  -lsqlite-embc  -ldl -lpthread

# ifneq (arm, $(TARGET))
LIBS+=   -lreadline -lhistory -lncurses
# endif


include ../../../common.mk
