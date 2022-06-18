

LIBNAME_SO=libgui-fsm.so
#LIBNAME_A=libgui-fsm.a


SRCCPP:= GUIFsmGui.cpp \
	GUIFSMState.cpp \
	GUIFsmSubsciber.cpp \
	GUIFsmGui_moc.cpp \
	GUIFSMState_moc.cpp \
	GUIFsmSubsciber_moc.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)
include ../../../common.mk
INCLUDES+= -I $(QT_INCLUDE) 


