
PROGRAM:=gstreamer-example1

SRCCPP+= gstreamer-example1.cpp \
	MediaApllication.cpp \
	MediaPlayer.cpp \
	MediaApllication_moc.cpp \
	MediaPlayer_moc.cpp

export CPPFLAGS:=$(CPPFLAGS_RELAXED)



ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

LIBS+= -lgstreamer-1.0   -lQt5Widgets  -lQt5Core -lQt5Gui   -lQtGLib-2.0    -lQtGStreamer-1.0  -lQtGStreamerUi-1.0  -lgstreamer-1.0


include ../../../../../common.mk


INCLUDES+= -I $(QT_INCLUDE) 

