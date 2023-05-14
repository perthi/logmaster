



LIBNAME_SO=libconfigurator.so
LIBNAME_A=libconfigurator.a


SRCCPP:= LConfigurator.cpp \
	     LGenerator.cpp \
         LGeneratorEnum.cpp \
         LGeneratorHashMap.cpp \
	     LGeneratorMacrosException.cpp \
         LGeneratorMacrosLogging.cpp \
         LGeneratorLogTest.cpp \
         LCopyright.cpp \
         LXmlEntity.cpp \
         LXmlEntityLogLevel.cpp \
         LXmlEntitySubSystem.cpp \
         LXmlParser.cpp


include ../../common.mk





