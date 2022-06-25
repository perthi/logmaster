PROGRAM:=gui-loggergui-example1

SRCCPP+=gui-loggergui-example1.cpp \
	GVersion.cpp

	
export CPPFLAGS:=$(CPPFLAGS_RELAXED)
INCLUDES+= -isystem $(QT_INCLUDE)

LIBS+=  -lcmdline  -llogmaster -lutilities -lreadline \
 -lreadline -lboost_system  -lboost_filesystem -lpthread -lgui-logger  -lgui-logmaster -lapi-logmaster -lgui-common -llogmaster -lexception -lutilities -lsqlite-embc -ldl





#LIBS+=  -lcmdline  -llogmaster -lutilities -lreadline \
 -lreadline -lboost_system  -lboost_filesystem -lpthread -lgui-logger  -lgui-logmaster -lgui-common 


include ../../../../../common.mk
include ../../../../../gui.mk

