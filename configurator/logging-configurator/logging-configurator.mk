

PROGRAM:=logging-configurator

SRCCPP+=../logging-configurator.cpp 


LIBS+=  -llogmaster  -lutilities -lxml-embc  -lxml2 -lpthread  -lreadline -lconfigurator   -lexception

include ../../../common.mk

