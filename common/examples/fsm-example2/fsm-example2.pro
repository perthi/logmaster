TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += \
fsm-example2.cpp

HEADERS += \
fsm-example2.h

        
DESTDIR=../../../build/x86/bin


INCLUDEPATH+=${FERROTECH_HOME}/software/include
LIBS += -L${FERROTECH_HOME}/software/build/x86/lib


LIBS+=  -llogmaster  -lcmdline -lutilities -lapi-fsm -lcommon-core -lutilities -lxml -lxml2  -llogmaster -lboost_system -lboost_filesystem


