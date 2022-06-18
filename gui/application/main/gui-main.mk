
PROGRAM:=gui-main

SRCCPP+= gui-main.cpp \
	GUIMainWindow.cpp \
	GUIMainWindow_moc.cpp \
	GUIResources.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

LIBS+=  -lcmdline  -llogmaster -lutilities \
	-lreadline  -lpthread -lgui-logger  -lgui-logmaster -lapi-logmaster -lgui-common \
	-lgui-fsm -lgui-settings -lgui-alarm -lkf-main -lapi-fsm -lcommon -lcmdline -llogmaster  \
	-lxml-embc -lxml2  -lgui-common  -lgui-sensors   -lapi-sensors  -lcontrol-engine -lapi-hmi -lintercom -lcom -lprotocol  \
	-lutilities -lreadline -lboost_system  -lboost_filesystem  -lconfiguration \
	-lc-ring -lgui-operations -lsequence -lQt5Charts -lintercom -lkf-com -lcom -lkf-commands -lapi-hmi -lQt5Quick -lQt5Qml -lQt5QuickWidgets -lprotocol


include ../../../../common.mk
include ../../../../gui.mk

INCLUDES+=$(PROTOBUF_INCLUDES)

ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif