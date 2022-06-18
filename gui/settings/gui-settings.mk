
LIBNAME_SO=libgui-settings.so
#LIBNAME_A=libgui-settings.a


SRCCPP:=GUISettingsDialog.cpp \
	GUISettingsDialog_moc.cpp \
	GUISettingsLanguage.cpp \
	GUISettingsLanguage_moc.cpp \
	GUISettingsStyle.cpp \
	GUISettingsStyle_moc.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)
include ../../../common.mk
INCLUDES+= -I $(QT_INCLUDE)   


