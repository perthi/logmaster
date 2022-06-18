

#LIBNAME_SO=libgui-common.so
LIBNAME_A=libgui-common.a


SRCCPP:=GUICentralPlaceholder.cpp \
	GUICommonGui.cpp \
	GUIPushButton.cpp \
	GUIInitStyles.cpp \
	GUILoggerBase.cpp \
	GUICentralPlaceholder_moc.cpp \
	GUICommonGui_moc.cpp  \
	GUIPushButton_moc.cpp \
	GUICringPushButton.cpp \
	GUICringPushButton_moc.cpp \
	GUIPainterClass.cpp \
	GUIPainterClass_moc.cpp \
	GUIGraphicalIndicator.cpp \
	GUIGraphicalSlider.cpp


export CPPFLAGS:=$(CPPFLAGS_RELAXED)
include ../../../common.mk
INCLUDES+= -I $(QT_INCLUDE)



