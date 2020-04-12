


LIBNAME_SO=libconfigurator.so
#LIBNAME_A=liblogmaster.a


SRCCPP:= LConfigurator.cpp \
         LEnumGenerator.cpp \
	 LHashMapGenerator.cpp \
	 LMacroGeneratorException.cpp \
	 LMacroGeneratorLogging.cpp  \
         LXmlEntity.cpp \
         LXmlEntityLogLevel.cpp \
	 LXmlEntitySubSystem.cpp \
         LXmlParser.cpp

include ../../common.mk





