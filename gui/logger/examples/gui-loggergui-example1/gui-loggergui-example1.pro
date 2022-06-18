TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

QT       += core gui widgets

SOURCES += \
gui-qt-loggergui-example1.cpp


HEADERS += \
gui-qt-loggergui-example1.h

        
DESTDIR=../../../../build/x86/bin


INCLUDEPATH+=${FERROTECH_HOME}/software/include
LIBS += -L${FERROTECH_HOME}/software/build/x86/lib


LIBS+=  -lcmdline  -llogmaster -lutilities \
 -lreadline -lboost_system  -lboost_filesystem -lpthread -lgui-logger  -lgui-logmaster -lapi-logmaster -lgui-common


