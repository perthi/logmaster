PROGRAM:=gui-alarm-example1

SRCCPP+=../gui-alarm-example1.cpp \
	../GVersion.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)

LIBS+=  -lcmdline  -llogmaster -lutilities \
 -lreadline -lboost_system  -lboost_filesystem -lpthread  -lgui-alarm -lgui-common 


include ../../../../../common.mk
include ../../../../../gui.mk


