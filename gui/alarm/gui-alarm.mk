
LIBNAME_SO=libgui-alarm.so
#LIBNAME_A=libgui-alarm.a


SRCCPP:= GUIAlarm.cpp \
	GUIAlarmGui.cpp \
	GUIAlarm_moc.cpp \
	GUIAlarmGui_moc.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk

INCLUDES+= -I $(QT_INCLUDE)   





