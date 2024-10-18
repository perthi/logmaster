
PROGRAM:=gui-alarm-example1

SRCCPP+=gui-alarm-example1.cpp \
	GVersion.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)

#include ../../../common.mk


INCLUDES+= -isystem $(QT_INCLUDE)   
LIBS+=  -lcmdline  -llogmaster -lutilities   \
 -lreadline  -lpthread  -lgui-alarm -lgui-common -lsqlite-embc -ldl -lfmt


include ../../../../../common.mk
include ../../../../../gui.mk


