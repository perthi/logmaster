
#LIBNAME_SO=libgui-logger.so
LIBNAME_A=libgui-logger.a


SRCCPP:=GUILogger.cpp \
	GUILogger_moc.cpp \
	GUILoggerGui.cpp \
	GUILoggerGui_moc.cpp



export CPPFLAGS:=$(CPPFLAGS_RELAXED)
include ../../../common.mk
INCLUDES+= -isystem $(QT_INCLUDE)   


