PROGRAM:=gui-example1

SRCCPP+= gui-example1.cpp \
	MyWidget.cpp \
	MyWidget_moc.cpp



export CPPFLAGS:=$(CPPFLAGS_RELAXED)

LIBS+=  -lcmdline  -llogmaster -lutilities -lgui-common 

ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

LIBS+= -lQt5Widgets  -lQt5Core -lQt5Gui 

include ../../../../../common.mk
INCLUDES+= -I $(QT_INCLUDE) 

