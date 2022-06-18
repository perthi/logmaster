TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += \
gui-example1.cpp


HEADERS += \
gui-example1.h

        
DESTDIR=../../../../build/x86/bin
INCLUDEPATH+=${FERROTECH_HOME}/modules/include
INCLUDEPATH+=${QT_INCLUDE}

LIBS += -L${FERROTECH_HOME}/modules/build/x86/lib
LIBS+=  -llogmaster  -lcmdline -lutilities -lboost_system -lboost_filesystem


