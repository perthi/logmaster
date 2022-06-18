TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
CONFIG += qt
QT       += core gui widgets

SOURCES += \
gui-sensors-example1.cpp


HEADERS += \
gui-sensors-example1.h

        
DESTDIR=../../../../build/x86/bin

INCLUDEPATH+=${FERROTECH_HOME}/software/include
LIBS += -L${FERROTECH_HOME}/software/build/x86/lib

LIBS+=  -llogmaster  -lcmdline -lutilities -lboost_system -lgui-sensors -lgui-common  -lapi-sensors -lcontrol-engine -lxml -lxml2 -llogmaster  -lutilities -lboost_filesystem


