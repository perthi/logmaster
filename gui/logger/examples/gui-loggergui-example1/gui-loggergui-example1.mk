PROGRAM:=gui-loggergui-example1

SRCCPP+=gui-loggergui-example1.cpp \
        GVersion.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)
INCLUDES+= -isystem $(QT_INCLUDE)

LIBS+=  -lcmdline  -llogmaster -lutilities -lreadline \
 -lreadline  -lpthread -lgui-logger  -lgui-logmaster -lapi-logmaster -lgui-common -llogmaster  -lutilities -lsqlite-embc -ldl -lfmt


include ../../../../../common.mk
include ../../../../../gui.mk

