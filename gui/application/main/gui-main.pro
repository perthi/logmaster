
QT       += core gui widgets


TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt


SOURCES += \
gui-main.cpp \
GUIMainWindow.cpp \
GUIResources.cpp


HEADERS += \
gui-main.h \
GUIMainWindow.h

        
DESTDIR=../../../build/x86/bin
INCLUDEPATH+=${FERROTECH_HOME}/software/include
INCLUDEPATH+=${QT_INCLUDE}

LIBS += -L${FERROTECH_HOME}/software/build/x86/lib
#LIBS+=  -lkf-main -lapi-fsm -lcmdline -llogmaster -lcommon-core -lutilities -lxml -lxml2     -lboost_system -lboost_filesystem

LIBS+=  -lcmdline  -llogmaster -lutilities \
 -lreadline  -lpthread -lgui-logger  -lgui-logmaster -lapi-logmaster -lgui-common \
 -lgui-fsm -lgui-settings -lkf-main  -lcommon-core   -lapi-fsm -lcmdline -llogmaster  \
  -lxml -lxml2  -lgui-common  -lgui-sensors -lgui-alarm -lapi-sensors  -lcontrol-engine \
-lutilities -lboost_system  -lboost_filesystem
# -L $(QT_LIBS)  -lQt5Widgets  -lQt5Core -lQt5Gui

#LIBS+= -L $(QT_LIBS)  -lQt5Widgets  -lQt5Core -lQt5Gui
