PROGRAM:=xml-validator

SRCCPP+=xml-validator.cpp
LIBS+= -lxml-embc  -lxml2  -lutilities -llogmaster -lsqlite-embc -lutilities -lreadline


include ../../../../common.mk
