

#LIBNAME_SO=libgui-common.so
LIBNAME_A=libgui-common.a


SRCCPP:= GUIInitStyles.cpp \
	     GUILoggerBase.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk
INCLUDES+= -isystem $(QT_INCLUDE)



