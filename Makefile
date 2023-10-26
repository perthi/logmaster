# -*- mode: makefile-gmake -*-



########################################
## AUTHOR: Per Thomas Hille pth@embc.no
## COPYRIGHT: Embedded Consulting A/S
########################################



##########################################################################
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.
##########################################################################

# This Makefile has two primary build targets: 'x86' and 'arm'
# When building each of these the Makefile will call itself with
# the TARGET variable set accordingly, but with no goals. For example:
# "make TARGET=arm". The TARGET variable is responsible for setting
# the value of the "all-src" list which contains all directories that
# shall be built for the given target.


export BUILDDIR=$(CURDIR)/build
export BINDIR=$(BUILDDIR)/$(TARGET)/bin
export LIBLOCAL=$(BUILDDIR)/$(TARGET)/lib
export INSTALLDIRS=$(BUILDDIR) $(BUILDDIR)/x86  $(BUILDDIR)/x86/bin  $(BUILDDIR)/x86/lib  $(BUILDDIR)/arm  $(BUILDDIR)/arm/bin  $(BUILDDIR)/arm/lib
export VERSIONINFO_EXE=$(BUILDDIR)/x86/bin/version-info

## export COMMON_FLAGS:= -fPIC -O3 -std=c++17  -g 
export LOGMASTER_HOME=$(PWD)
export COMMON_FLAGS:= -fPIC  -std=c++23  -g   -Wno-psabi  -DGUI_DIR='"$(LOGMASTER_HOME)"'

## export PEDANTIC_FLAGS:= -Weffc++ -Wshadow -Wall -Wextra -Wpedantic -Wno-unknown-pragmas -Wswitch-enum -Wimplicit-fallthrough -Wignored-qualifiers -Wfatal-errors  -Werror
export PEDANTIC_FLAGS:=  -ggdb  -Weffc++ -Wshadow -Wall -Wextra -Wpedantic -Wno-psabi -Wno-unknown-pragmas -Wswitch-enum  -Wimplicit-fallthrough -Wignored-qualifiers -Wno-format-security


export HAS_LOGGING:=""
export LOGMASTER_HOME=$(PWD)
export CPPFLAGS:=           $(COMMON_FLAGS) $(PEDANTIC_FLAGS)   -DHAS_LOGGING
export CPPFLAGS_RELAXED:=   $(COMMON_FLAGS) $(PEDANTIC_FLAGS)   -DHAS_LOGGING
export XML_DIR:=$(CURDIR)/xml/3rd-party/
export XML_INCLUDES:= -I $(XML_DIR)
export LIBFLAGS:= -shared
export CONFIG_DIR:=$(PWD)/config


INCLUDES:= -I $(PWD)/include/  -isystem $(PWD)/include/system   -isystem $(PWD)/xml/xml/3rd-party
## GTEST_INCLUDES:= -isystem $(PWD)/
GTEST_INCLUDES:= -isystem $(PWD)/productivity/

LIBS= -L $(PWD)/build/$(TARGET)/lib  -lm

export SUPPORT_LIBS:= -lcmdline -lutilities   -llogmaster 
export UNIT_TEST_LIBS:= $(SUPPORT_LIBS) -lgtest -lpthread 

version-info:=           productivity/utilities/version-info/$(TARGET)
#gtest-embc:=             productivity/gtest-embc/$(TARGET)
utilities:=              utilities/$(TARGET)
#utilities-unittest:=     utilities/unit-tests/commit/$(TARGET)
logging:=                logging/$(TARGET)
#logging-example1:=       logging/examples/logging-example1/$(TARGET)
logging-unittest:=       logging/unit-tests/commit/$(TARGET)
cmdline:=                cmdline/$(TARGET)
#cmdline-example1:=       cmdline/examples/cmdline-example1/$(TARGET)
#cmdline-unittest:=       cmdline/unit-tests/commit/$(TARGET)
xml:=                    xml-parser/xml/$(TARGET)
configurator:=           configurator/$(TARGET)
#configurator-unittest:=  configurator/unit-tests/commit/$(TARGET)
# logging-configurator:=   configurator/logging-configurator/$(TARGET)
#helloworld:=             helloworld/$(TARGET)
#db-test:=                database-test/$(TARGET)
sqlite:=                 productivity/sqlite/$(TARGET) 
api-logmaster:=          api/api-logmaster/$(TARGET) 
#gui-example1:=           gui/logger/examples/gui-loggergui-example1/$(TARGET)
#gui-example2:=           gui/logmaster/examples/gui-qt-logmaster-example1/$(TARGET)
#gui-alarm:=              gui/alarm/$(TARGET) 
#gui-logger:=             gui/logger/$(TARGET) 
#gui-logmaster:=          gui/logmaster/$(TARGET) 
#gui-common:=             gui/common/$(TARGET) 
#gui-alarm-example1:=     gui/alarm/examples/gui-alarm-example1/$(TARGET) 

unittests:= 	$(utilities-unittest) \
		        $(exception-unittest) \
                $(logging-unittest) \
		        $(cmdline-unittest)


support-modules:= 	$(utilities) \
			$(logging) \
			$(cmdline)

gui-lib+=$(gui-logger) $(gui-logmaster) $(gui-common) $(gui-alarm)
gui-exe+=$(gui-example1)   $(gui-alarm-example1) $(gui-example2)  

src-lib:= $(support-modules) \
	$(gtest-embc) \
	$(testlib) \
	$(xml) \
	$(common) \
    $(exception) \
	$(sqlite)




src-exe:=$(helloworld) \
	$(unittests) \
	$(logging-example1) \
	$(cmdline-example1) \
	$(db-test)


#	$(version-info)



arm-src:=$(src-lib) $(src-exe)
x86-src:=$(src-lib) $(src-exe)

all-clean:= $(src-lib)  $(x86-src) $(configurator-unittest) $(configurator)  $(api-logmaster)  $(xml-validator) $(configurator-example1) $(logging-configurator)  $(gui-lib)  $(gui-exe)

ifeq (x86, $(TARGET))
#unittests+= $(configurator-unittest)
src-lib+= $(configurator)  $(api-logmaster)
src-exe+= $(xml-validator) $(configurator-example1) $(logging-configurator) $(configurator-unittest)
x86-src:= $(src-lib) $(src-exe)
all-src:=$(x86-src)
all-clean:=$(all-src)
endif


ifeq (arm, $(TARGET))
LIBS+=-L  $(CURDIR)/arm-extras
all-src:=$(arm-src)
endif

ifdef GUI
src-lib+=$(gui-lib)
src-exe+=$(gui-exe)
x86-src:= $(src-lib) $(src-exe)
all-src:=$(x86-src)
endif

#default target is x86, we define it here to avoid cheking for the arm compiler if
#compiling just for x86
export TARGET=x86

## Set compiler and archive builder to toolchain.
##ifeq ($(strip $(ARCH)),)
ifeq (x86, $(TARGET))
CCLOCAL:=c++   -std=c++23
ARLOCAL:=ar
else
LIBS+= -L$(CURDIR)/productivity/3rd-party/arm/lib/
CCLOCAL:=arm-linux-gnueabihf-g++   -std=c++23 -DARM
CC:= arm-linux-gnueabihf-gcc
ARLOCAL:=arm-linux-gnueabihf-ar
endif


ifdef CC-CROSS
CCLOCAL:=$(CC-CROSS)
endif


export

#$(all-src) : $(version-info)

#$(version-info) :
#	$(MAKE) --directory=$@ all



.PHONY: all $(all-src)
all: $(all-src)

$(src-exe) : $(src-lib)


#$(all-src): $(version-info)
$(all-src):
	$(MAKE) --directory=$@ all


# $(version-info) :
#	$(MAKE) --directory=$@ all

.PHONY: check-compiler
check-compiler:
	$(CCLOCAL) --version /dev/null;


$(INSTALLDIRS):
	mkdir -p $@

$(src-exe): $(version-info)

x86:    $(INSTALLDIRS)
	$(MAKE) TARGET=x86

arm:    $(INSTALLDIRS)
	@$(MAKE) TARGET=arm

$(unittests) : gtest


.PHONY : gtest
gtest:
	cd gtest ;\
	cmake googletest-1.13.0 ;\
	make ;\
	cd .. ;\
	cp gtest/lib/* build/$(TARGET)/lib


.PHONY : rcc
rcc:
	rcc   gui/resources/gui-qt.qrc  >  gui/resources/gui-qt.rcc


.PHONY : moc
moc: rcc
	./generate-moch.sh  $(gui-lib) $(gui-exe)


.PHONY: clean 
clean:  clean-x86 clean-arm
	@find -name *.d -exec rm {} \;
	@find -name *.gdb -exec rm {} \;
	@find -name *.o -exec rm {} \;


.PHONY: clean-x86
clean-x86:
	@for d in $(all-clean); \
	do \
	    $(MAKE)  --directory=$$d/x86  --no-print-directory clean TARGET=x86; \
	done
	@rm -rf build/x86

.PHONY: clean-arm
clean-arm:
	@for d in $(all-clean); \
	do \
	    $(MAKE)  --directory=$$d/x86  --no-print-directory clean TARGET=arm; \
	done
	@rm -rf build/x86

#.PHONY: clean-logs
clean-logs:
	rm -f *.log*  *.db


#.PHONY: distclean
distclean: clean clean-logs
	@-$(RM) -r build
	@-$(RM) `find -name "SvnInfo*" | grep -v .svn`
	@find -name *.so    |  egrep  -v  3rd-party  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |  egrep -v   '^\./arm-lib-dep/' |  xargs rm -f
	@find -name *.so.*  |  egrep  -v  3rd-party  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |  egrep -v   '^\./arm-lib-dep/' |  xargs rm -f
	@find -name *.a     |  egrep  -v  3rd-party  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |   xargs rm -f
	@find -name *~ -exec rm {} \;
	@find -name GVersion.cpp | xargs rm -f;
	@find -name tmp.cpp | xargs rm -f;

.PHONY: doc
doc:
	doxygen Doxyfile

