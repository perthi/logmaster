#-------------------------------------------------
#
# Project created by QtCreator 2019-06-28T18:37:38
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = gui-logger
TEMPLATE = lib

DEFINES += SRC_LIBRARY

DESTDIR = ../../build/x86/lib

#include(../../modules.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
GUILogger.cpp \
GUILoggerGui.cpp


HEADERS += \
GUILoggerGui.h \
GUILogger.h


#SOURCES += \
#GUILogger.cpp \
#GUILoggerGui.cpp \
#GUILoggerGui_moc.cpp \
#GUILogger_moc.cpp \
#GUILoggerModel.cpp \
#GUILoggerModel_moc.cpp


#HEADERS += \
#GUILoggerGui.h \
#GUILoggerGui_moc.h \
#GUILogger.h \
#GUILogger_moc.h \
#GUILoggerModel.h \
#GUILoggerModel_moc.h



INCLUDEPATH+=${FERROTECH_HOME}/software/include
#INCLUDEPATH+=${QT_INCLUDE}

unix {
    target.path = /usr/lib
    INSTALLS += target
}