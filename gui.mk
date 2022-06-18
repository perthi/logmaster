
ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

LIBS+= -lQt5Widgets  -lQt5Core -lQt5Gui 
INCLUDES+= -I $(QT_INCLUDE) 
