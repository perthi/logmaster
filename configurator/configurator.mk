



LIBNAME_SO=libconfigurator.so
LIBNAME_A=libconfigurator.a


SRCCPP:= LArgumentScanner.cpp \
         LCreateDefaultGenerators.cpp \
         LGeneratorTestBase.cpp \
         LGeneratorTestLConversion.cpp \
         LGenerator.cpp \
         LGeneratorHashMap.cpp \
         LGeneratorMacrosException.cpp \
         LXmlEntity.cpp \
         LXmlEntitySubSystem.cpp \
         LXmlParser.cpp \
         LCopyright.cpp \
         LFileCreator.cpp \
         LGeneratorEnum.cpp \
         LGeneratorLogTest.cpp \
         LGeneratorMacrosLogging.cpp \
         LXmlEntityLogLevel.cpp \
         LXMLInfo.cpp \
         LFileInfo.cpp \
         LGeneratorCommon.cpp \
         LGeneratorTestLHashMaps.cpp

CPPFLAGS+= -DLOGMASTER_HOME='"$(LOGMASTER_HOME)"'

include ../../common.mk





