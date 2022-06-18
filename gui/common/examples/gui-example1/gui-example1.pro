TEMPLATE = app
CONFIG += console c++11



QT       += core gui widgets

SOURCES += \
gui-example1.cpp \
MyWidget.cpp


HEADERS += \
gui-example1.h \
MyWidget.h

        
DESTDIR=../../../../build/x86/bin

INCLUDEPATH+=${FERROTECH_HOME}/software/include
LIBS += -L${FERROTECH_HOME}/software/build/x86/lib



LIBS+=  -lapi-fsm -lgui-fsm  -lgui-common -lcommon-core -lxml -lxml2 \
-lcmdline  -llogmaster -lutilities  -lboost_system  -lboost_filesystem -lpthread
