
PROGRAM:= version-info
LIBNAME_SO:= libversion-info.so

SRCCPP+=	version-info.cpp \
		VGenerateRCFile.cpp \
                VGenerateVersionInfo.cpp \
                VHelpers.cpp \
                VScanArguments.cpp \
                VVersionHeader.cpp


LIBS+=  -ldl -lpthread

LIBS+=  -lsqlite-embc  -ldl -lpthread

# ifneq (arm, $(TARGET))
LIBS+=   -lreadline -lhistory -lncurses
# endif
CPPFLAGS := $(filter-out -fprofile-arcs,  $(CPPFLAGS))
CPPFLAGS := $(filter-out -ftest-coverage, $(CPPFLAGS))


include ../../../../common.mk

