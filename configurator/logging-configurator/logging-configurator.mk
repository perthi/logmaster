

PROGRAM:=logging-configurator

SRCCPP+=logging-configurator.cpp \
         GVersion.cpp



LIBS+=  -lconfigurator  -lxml-embc  -lxml2  -lcmdline  -llogmaster -lexception -lutilities   -lpthread   -lreadline   -lsqlite-embc -ldl -lpthread

include ../../../common.mk

