

PROGRAM:=logging-configurator

SRCCPP+=logging-configurator.cpp 


LIBS+=  -lconfigurator  -lxml-embc  -lxml2  -llogmaster -lexception -lutilities  -lpthread   -lreadline 

include ../../../common.mk

