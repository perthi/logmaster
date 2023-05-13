
ifdef QT_LIBS
	LIBS+= -L $(QT_LIBS)
endif

LIBS+= -lQt6Widgets  -lQt6Core -lQt6Gui -lQt6Core5Compat
INCLUDES+= -I $(QT_INCLUDE) 
