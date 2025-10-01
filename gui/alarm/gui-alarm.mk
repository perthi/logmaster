


LIBNAME_SO=libgui-alarm.so
LIBNAME_A=libgui-alarm.a



SRCCPP:= GUIAlarmGui.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk

INCLUDES+= -isystem $(QT_INCLUDE)   





