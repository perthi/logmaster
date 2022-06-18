
#LIBNAME_SO=libgui-logmaster.so
LIBNAME_A=libgui-logmaster.a


SRCCPP:= GUILogMasterGui.cpp \
	 GUILogMasterGui_moc.cpp \
	 GUILogMasterTab.cpp \
	 GUILogMasterTab_moc.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)
include ../../../common.mk
INCLUDES+= -I $(QT_INCLUDE)   


