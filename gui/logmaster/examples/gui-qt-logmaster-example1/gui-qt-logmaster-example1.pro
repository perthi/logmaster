TEMPLATE = app
CONFIG += console c++11
CONFIG += qt

QT       += core gui widgets

SOURCES += \
gui-qt-logmaster-example1.cpp



HEADERS += \
gui-qt-logmaster-example1.h

        
DESTDIR=../../../../build/x86/bin

INCLUDEPATH+=${FERROTECH_HOME}/software/include
LIBS += -L${FERROTECH_HOME}/software/build/x86/lib


LIBS+=  -lcmdline  -llogmaster -lutilities \
 -lreadline -lboost_system  -lboost_filesystem -lpthread   -lgui-logmaster -lapi-logmaster -lgui-common -llogmaster


