# -*- mode: makefile-gmake -*-


########################################
## MAKEFILE FOR FERROTECH
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
export INSTALLDIRS=$(BUILDDIR) $(BUILDDIR)/$(TARGET)  $(BUILDDIR)/$(TARGET)/bin  $(BUILDDIR)/$(TARGET)/lib
export VERSIONINFO_EXE=$(BUILDDIR)/x86/bin/version-info

export COMMON_FLAGS:= -fPIC -std=c++17 -ggdb -g
export PEDANTIC_FLAGS:= -Weffc++ -Wshadow -Wall -Wextra -Wpedantic -Wno-unknown-pragmas -Wswitch-enum -Wimplicit-fallthrough -Wignored-qualifiers -Werror

export CPPFLAGS:=           $(COMMON_FLAGS) $(PEDANTIC_FLAGS)
export CPPFLAGS_RELAXED:=   $(COMMON_FLAGS)

export XML_DIR:=$(CURDIR)/xml/3rd-party/
export XML_INCLUDES:= -I $(XML_DIR)

export LIBFLAGS:= -shared


INCLUDES:= -I $(CURDIR)/include/
GTEST_INCLUDES:= -isystem $(CURDIR)/
LIBS= -L $(CURDIR)/build/$(TARGET)/lib  -lm


export SUPPORT_LIBS:= -lutilities -lcmdline  -llogmaster -lboost_system -lboost_filesystem -lreadline
export UNIT_TEST_LIBS:=-ltestlib $(SUPPORT_LIBS) -lgtest -lpthread -lboost_system -lboost_filesystem


version-info:=	  	version-info/$(TARGET)
helloworld:=  		helloworld/$(TARGET)
gtest-linux:=		gtest-linux/$(TARGET)
testlib:=		testlib/$(TARGET)
utilities:=  	  	utilities/$(TARGET)
utilities-unittest:=  	utilities/unit-tests/commit/$(TARGET)
logging:=    	  	logging/$(TARGET)
logging-example1:=	logging/examples/logging-example1/$(TARGET)
logging-unittest:=    	logging/unit-tests/commit/$(TARGET)
cmdline:= 		cmdline/$(TARGET)
cmdline-example1:=      cmdline/examples/cmdline-example1/$(TARGET)
cmdline-unittest:=	cmdline/unit-tests/commit/$(TARGET)


xml:=			xml/$(TARGET)
xml-unittest:= 		xml/unit-tests/commit/$(TARGET)
xml-example1:=     	xml/examples/xml-example1/$(TARGET)
xml-validator:=  	xml/xml-validator/$(TARGET)


common:= 			common/$(TARGET)
common-unittest:=       	common/unit-tests/commit/$(TARGET)
fsm-example1:=          	common/examples/fsm-example1/$(TARGET)
fsm-example2:=   		common/examples/fsm-example2/$(TARGET)
message-example1:= 		common/examples/message-example1/$(TARGET)
message-example2:= 		common/examples/message-example2/$(TARGET)
message-example3-blocking:= 	common/examples/message-example3-blocking/$(TARGET)
message-example4-timer:= 	common/examples/message-example4-timer/$(TARGET)


com:=				com/$(TARGET)
com-unittest:=       		com/unit-tests/commit/$(TARGET)
com-example1:= 			com/examples/tcp-example1/$(TARGET)
com-server:= 			com/tcp-server/$(TARGET)
com-client:= 			com/tcp-client/$(TARGET)


common-examples:= $(fsm-example1) $(fsm-example2)  $(message-example1) \
		$(message-example2) $(message-example3-blocking) $(message-example4-timer)


 unittests:= 	$(utilities-unittest) \
		$(logging-unittest) \
		$(cmdline-unittest) \
		$(xml-unittest) \
		$(common-unittest) \
		$(intercom-unittets) \
		$(configuration-unittests) \
		$(com-unittest)



support-modules:= 	$(utilities) \
			$(logging) \
			$(cmdline)


src-lib:= $(support-modules) \
	$(gtest-linux) \
	$(testlib) \
	$(xml) \
	$(common) \
	$(com) \


src-exe:=$(helloworld) \
	$(unittests) \
	$(logging-example1) \
	$(cmdline-example1) \
	$(fsm-example2) \
	$(message-example1) \
	$(message-example2) \
	$(message-example3-blocking) \
	$(message-example4-timer) \
	$(com-example1) \
	$(com-server) \
	$(com-client) \
	$(xml-validator) \
	$(com-udp-emulator)


arm-src:=$(src-lib) $(src-exe)
x86-src:=$(src-lib) $(src-exe) $(version-info)

ifeq (x86, $(TARGET))
all-src:=$(x86-src)
endif


ifeq (arm, $(TARGET))
LIBS+=-L  $(CURDIR)/arm-extras
all-src:=$(arm-src)
endif


#default target is x86, we define it here to avoid cheking for the arm compiler if
#compiling just for x86
export TARGET=x86

## Set compiler and archive builder to toolchain.
##ifeq ($(strip $(ARCH)),)
ifeq (x86, $(TARGET))
CCLOCAL:=c++   -std=c++17
ARLOCAL:=ar
else
CCLOCAL:=arm-linux-gnueabihf-g++   -std=c++17 -DARM
ARLOCAL:=arm-linux-gnueabihf-ar
endif


ifdef CC-CROSS
CCLOCAL:=$(CC-CROSS)
endif


export


.PHONY: all $(all-src)
all: $(all-src)


all-clean:=$(x86-src)
unittest-common =  $(testlib)  $(support-modules)  $(gtest-linux)


$(src-all) : $(version-info)
$(src-exe) : $(src-lib)



make-version-info:
	$(MAKE) --directory=$(version-info) all


$(all-src): make-version-info
	$(MAKE) --directory=$@ all

.PHONY: check-compiler
check-compiler:
	$(CCLOCAL) --version /dev/null;



$(INSTALLDIRS):
	mkdir -p $@


x86:

	@$(MAKE) TARGET=x86



.PHONY: clean
clean:  clean-x86
	@find -name *.d -exec rm {} \;
	@find -name *.gdb -exec rm {} \;
	@find -name *.o -exec rm {} \;
	@rm -rf `find -name "SvnInfo*" | grep -v .svn`

.PHONY: clean-exe
clean-exe:
	@for d in $(src-exe); \
	do \
	    $(MAKE)  --directory=$$d/x86  --no-print-directory clean-exe TARGET=x86; \
	done
#	@rm -f build/x86/bin/*



.PHONY: clean-x86
clean-x86:
	@for d in $(x86-src); \
	do \
	    $(MAKE)  --directory=$$d/x86  --no-print-directory clean TARGET=x86; \
	done
	@rm -rf build/x86


.PHONY: distclean
distclean: clean
	@-$(RM) -r build
	@-$(RM) `find -name "SvnInfo*" | grep -v .svn`
	@find -name *.so    |  egrep  -v  '^\./3rd-party/'  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |  egrep -v   '^\./arm-lib-dep/' |  xargs rm -f
	@find -name *.so.*  |  egrep  -v  '^\./3rd-party/'  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |  egrep -v   '^\./arm-lib-dep/' |  xargs rm -f
	@find -name *.a     |  egrep  -v  '^\./3rd-party/'  |  egrep  -v  '^\./boost_1_66_0/'  |  egrep -v  '^\./googletest/'  |   egrep -v   '^\./linux-imx6sx-2.3.2/'   |   xargs rm -f
	@find -name *~ -exec rm {} \;
	@find -name GVersion.cpp | xargs rm -f;
	@find -name tmp.cpp | xargs rm -f;

.PHONY: doc
doc:
	doxygen Doxyfile
