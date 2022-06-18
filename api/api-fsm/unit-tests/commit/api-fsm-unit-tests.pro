
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


TARGET=logging-unit-tests
DESTDIR = ../../../build/x86/bin
INCLUDEPATH+=${FERROTECH_HOME}/modules/include


LIBS += -L${FERROTECH_HOME}/modules/build/x86/lib
LIBS+=  -llogmaster -ltestlib  -lutilities -lcmdline -lgtest  -lpthread -lboost_system -lboost_filesystem

SOURCES += \
api-fsm-dll-test.cpp \
TestKAFSMController.cpp

HEADERS += \
api-fsm-dll-test.h \
TestKAFSMController.h
