

PROGRAM:=logging-configurator

SRCCPP+=logging-configurator.cpp \
         GVersion.cpp



LIBS+=  -lconfigurator  -lxml-embc  -lxml2  -lcmdline  -llogmaster  -lutilities   -lpthread   -lreadline   -lsqlite-embc -ldl -lpthread -lfmt

CPPFLAGS+= -DLOGMASTER_HOME='"(LOGMASTER_HOME)"'

include ../../../common.mk

