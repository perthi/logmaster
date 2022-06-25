

#LIBNAME_SO=libgui-common.so
LIBNAME_A=libgui-common.a


SRCCPP:=GUICommonGui.cpp \
	GUIPushButton.cpp \
	GUIInitStyles.cpp \
	GUILoggerBase.cpp \
	GUICommonGui_moc.cpp  \
	GUIPushButton_moc.cpp 


export CPPFLAGS:=$(CPPFLAGS_RELAXED)

include ../../../common.mk
INCLUDES+= -isystem $(QT_INCLUDE)



