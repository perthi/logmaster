# $Id: Makefile.in,v 1.71 2020/02/02 23:34:34 tom Exp $
##############################################################################
# Copyright 2020 Thomas E. Dickey                                            #
# Copyright 1998-2015,2018 Free Software Foundation, Inc.                    #
#                                                                            #
# Permission is hereby granted, free of charge, to any person obtaining a    #
# copy of this software and associated documentation files (the "Software"), #
# to deal in the Software without restriction, including without limitation  #
# the rights to use, copy, modify, merge, publish, distribute, distribute    #
# with modifications, sublicense, and/or sell copies of the Software, and to #
# permit persons to whom the Software is furnished to do so, subject to the  #
# following conditions:                                                      #
#                                                                            #
# The above copyright notice and this permission notice shall be included in #
# all copies or substantial portions of the Software.                        #
#                                                                            #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    #
# THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    #
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        #
# DEALINGS IN THE SOFTWARE.                                                  #
#                                                                            #
# Except as contained in this notice, the name(s) of the above copyright     #
# holders shall not be used in advertising or otherwise to promote the sale, #
# use or other dealings in this Software without prior written               #
# authorization.                                                             #
##############################################################################
#
# Author: Thomas E. Dickey 1996-on
#
# Makefile for panels source code.
#
# This makes the following:
#	libraries (normal/debug/profile/shared)
#
# The variable 'srcdir' refers to the source-distribution, and can be set with
# the configure script by "--srcdir=DIR".
#
# The rules are organized to produce the libraries for the configured models,

# turn off _all_ suffix rules; we'll generate our own
.SUFFIXES:

SHELL		= /bin/sh

THIS		= Makefile

x		= 
o		= .o

MODEL		= normal
DESTDIR		= 
top_srcdir	= ..
srcdir		= .
prefix		= /usr
exec_prefix	= ${prefix}
bindir		= ${exec_prefix}/bin
libdir		= ${exec_prefix}/lib
includedir	= ${prefix}/include
datarootdir	= ${prefix}/share
datadir		= ${datarootdir}
includesubdir	= 

INCLUDEDIR	= $(DESTDIR)$(includedir)$(includesubdir)

PACKAGE		= ncurses

LIBTOOL		= 
LIBTOOL_OPTS	=  
LIBTOOL_CLEAN	= 
LIBTOOL_COMPILE	= 
LIBTOOL_LINK	= ${CC}
LIBTOOL_INSTALL	= 
LIBTOOL_UNINSTALL = 
LT_UNDEF	= 

INSTALL		= /usr/bin/install -c
INSTALL_LIB	= /usr/bin/install -c -m 644 -p
INSTALL_PROG	= ${INSTALL} -s
INSTALL_DATA	= ${INSTALL} -m 644

AR		= ar
ARFLAGS		= -curvU
AWK		= mawk
LD		= ld
LN_S		= ln -s -f

CTAGS		= 
ETAGS		= 

CC		= arm-linux-gnueabihf-gcc
CPP		= arm-linux-gnueabihf-gcc -E
CFLAGS		= -O2 --param max-inline-insns-single=1200

CPPFLAGS	= -I${top_srcdir}/ncurses -DHAVE_CONFIG_H -I. -I../include -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -D_FILE_OFFSET_BITS=64 -DNDEBUG

CCFLAGS		= $(CPPFLAGS) $(CFLAGS)

CFLAGS_LIBTOOL	= $(CCFLAGS)
CFLAGS_NORMAL	= $(CCFLAGS)
CFLAGS_DEBUG	= $(CCFLAGS) -g -DTRACE
CFLAGS_PROFILE	= $(CCFLAGS) -pg
CFLAGS_SHARED	= $(CCFLAGS) -fPIC

CFLAGS_DEFAULT	= $(CFLAGS_NORMAL)

LINK		= $(LIBTOOL_LINK)
LDFLAGS		=   

SHLIB_DIRS	= -L../lib
SHLIB_LIST	= $(SHLIB_DIRS) -lncurses 

RPATH_LIST	= ${libdir}
RESULTING_SYMS	= 
VERSIONED_SYMS	= 
MK_SHARED_LIB	= ${CC} ${LDFLAGS} ${CFLAGS} -shared -Wl,-soname,`basename $@ .${REL_VERSION}`.${ABI_VERSION},-stats,-lc -o $@

NCURSES_MAJOR	= 6
NCURSES_MINOR	= 2
REL_VERSION	= 6.2
ABI_VERSION	= 6

RANLIB		= ranlib

LIBRARIES	=  ../lib/libpanel.a ../lib/libpanel_g.a

LINT		= 
LINT_OPTS	= 
LINT_LIBS	= -lpanel -lncurses 

AUTO_SRC	= \
		../include/panel.h

################################################################################
all \
libs \
install ::	$(AUTO_SRC) $(LIBRARIES)

sources:	$(AUTO_SRC)

$(DESTDIR)$(bindir) \
$(DESTDIR)$(libdir) :
	mkdir -p $@

# make a copy to simplify include-paths while still keeping panel's include
# file in this directory.
../include/panel.h : $(srcdir)/panel.h
	-rm -f $@
	cp $(srcdir)/panel.h $@

HEADER_DEPS = \
	$(srcdir)/panel.priv.h \
	$(srcdir)/panel.h

tags:
	$(CTAGS) *.[ch]

#TAGS:
#	$(ETAGS) *.[ch]

mostlyclean ::
	-rm -f core tags TAGS *~ *.bak *.i *.ln *.atac trace

clean :: mostlyclean
	-rm -f $(AUTO_SRC)
	-rm -rf .libs *.dSYM

distclean :: clean
	-rm -f Makefile

realclean :: distclean

###############################################################################
# The remainder of this file is automatically generated during configuration
###############################################################################

# Generated by CF_LIB_RULES
resulting.map: 
	mawk 'BEGIN { skip = 1; last=""; } /deprecated in ABI6/ { next; }{ sub("NCURSES([WT]+)?", "&6"); } { if ( last != "" && ( skip == 0 || $$0 !~ /}/ ) ) { print last; } skip = 0; last = $$0; } END { print last; }' <  >$@

distclean::
	rm -f resulting.map

# generated by mk-0th.awk
#   libname:    panel
#   subsets:    ticlib+termlib+ext_tinfo+base+ext_funcs

.SUFFIXES: .c .cc .h .i .ii
.c.i :
	$(CPP) $(CPPFLAGS) $< >$@
.cc.ii :
	$(CPP) $(CPPFLAGS) $< >$@
.h.i :
	$(CPP) $(CPPFLAGS) $< >$@

C_SRC = \
	$(srcdir)/panel.c \
	$(srcdir)/p_above.c \
	$(srcdir)/p_below.c \
	$(srcdir)/p_bottom.c \
	$(srcdir)/p_delete.c \
	$(srcdir)/p_hide.c \
	$(srcdir)/p_hidden.c \
	$(srcdir)/p_move.c \
	$(srcdir)/p_new.c \
	$(srcdir)/p_replace.c \
	$(srcdir)/p_show.c \
	$(srcdir)/p_top.c \
	$(srcdir)/p_update.c \
	$(srcdir)/p_user.c \
	$(srcdir)/p_win.c

# Producing llib-lpanel is time-consuming, so there's no direct-dependency for
# it in the lintlib rule.  We'll only remove in the cleanest setup.

PANEL_SRC = \
	$(srcdir)/panel.c \
	$(srcdir)/p_above.c \
	$(srcdir)/p_below.c \
	$(srcdir)/p_bottom.c \
	$(srcdir)/p_delete.c \
	$(srcdir)/p_hide.c \
	$(srcdir)/p_hidden.c \
	$(srcdir)/p_move.c \
	$(srcdir)/p_new.c \
	$(srcdir)/p_replace.c \
	$(srcdir)/p_show.c \
	$(srcdir)/p_top.c \
	$(srcdir)/p_update.c \
	$(srcdir)/p_user.c \
	$(srcdir)/p_win.c

clean ::
	rm -f llib-lpanel.*

realclean ::
	rm -f llib-lpanel

llib-lpanel : $(PANEL_SRC)
	cproto -a -l -DNCURSES_ENABLE_STDBOOL_H=0 -DLINT $(CPPFLAGS) $(PANEL_SRC) >$@

lintlib ::
	sh $(srcdir)/../misc/makellib panel $(CPPFLAGS)

lint ::
	$(LINT) $(LINT_OPTS) $(CPPFLAGS) $(PANEL_SRC) $(LINT_LIBS)

# generated by mk-1st.awk (subset=ticlib+termlib+ext_tinfo+base+ext_funcs)
#  name:          panel
#  traces:        DEBUG
#  MODEL:         NORMAL
#  CXX_MODEL:     NORMAL
#  model:         objects
#  prefix:        lib
#  suffix:        .a
#  subset:        ticlib+termlib+ext_tinfo+base+ext_funcs
#  driver:        no
#  ShlibVer:      rel
#  ShlibVerInfix: no
#  SymLink:       ln -s -f
#  TermlibRoot:   ncurses
#  TermlibSuffix: .a
#  ReLink:        no
#  ReRanlib:      no
#  DoLinks:       yes
#  rmSoLocs:      no
#  ldconfig:      :
#  overwrite:     yes
#  depend:        ../include/ncurses_cfg.h ./panel.priv.h
#  host:          arm-unknown-linux-gnu

NORMAL_OBJS = \
	../objects/panel$o \
	../objects/p_above$o \
	../objects/p_below$o \
	../objects/p_bottom$o \
	../objects/p_delete$o \
	../objects/p_hide$o \
	../objects/p_hidden$o \
	../objects/p_move$o \
	../objects/p_new$o \
	../objects/p_replace$o \
	../objects/p_show$o \
	../objects/p_top$o \
	../objects/p_update$o \
	../objects/p_user$o \
	../objects/p_win$o

$(NORMAL_OBJS) : ../include/ncurses_cfg.h ./panel.priv.h

../lib/libpanel.a : $(NORMAL_OBJS)
	@sleep 1
	$(AR) $(ARFLAGS) $@ $?
	$(RANLIB) $@

install \
install.libs \
install.panel :: $(DESTDIR)$(libdir) ../lib/libpanel.a
	@echo installing ../lib/libpanel.a as $(DESTDIR)$(libdir)/libpanel.a
	$(INSTALL_DATA) ../lib/libpanel.a $(DESTDIR)$(libdir)/libpanel.a

uninstall \
uninstall.libs \
uninstall.panel ::
	@echo uninstalling $(DESTDIR)$(libdir)/libpanel.a
	-@rm -f $(DESTDIR)$(libdir)/libpanel.a

clean ::
	-rm -f ../lib/libpanel.a

mostlyclean::
	-rm -f $(NORMAL_OBJS)

# generated by mk-2nd.awk
#   model:      objects
#   MODEL:      NORMAL
#   echo:       yes
#   subset:     ticlib+termlib+ext_tinfo+base+ext_funcs
#   crenames:   yes
#   cxxrenames: yes
#   traces:     DEBUG
#   srcdir:     .

../objects/panel$o :	$(srcdir)/panel.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/panel.c -o ../objects/panel$o

../objects/p_above$o :	$(srcdir)/p_above.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_above.c -o ../objects/p_above$o

../objects/p_below$o :	$(srcdir)/p_below.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_below.c -o ../objects/p_below$o

../objects/p_bottom$o :	$(srcdir)/p_bottom.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_bottom.c -o ../objects/p_bottom$o

../objects/p_delete$o :	$(srcdir)/p_delete.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_delete.c -o ../objects/p_delete$o

../objects/p_hide$o :	$(srcdir)/p_hide.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_hide.c -o ../objects/p_hide$o

../objects/p_hidden$o :	$(srcdir)/p_hidden.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_hidden.c -o ../objects/p_hidden$o

../objects/p_move$o :	$(srcdir)/p_move.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_move.c -o ../objects/p_move$o

../objects/p_new$o :	$(srcdir)/p_new.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_new.c -o ../objects/p_new$o

../objects/p_replace$o :	$(srcdir)/p_replace.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_replace.c -o ../objects/p_replace$o

../objects/p_show$o :	$(srcdir)/p_show.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_show.c -o ../objects/p_show$o

../objects/p_top$o :	$(srcdir)/p_top.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_top.c -o ../objects/p_top$o

../objects/p_update$o :	$(srcdir)/p_update.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_update.c -o ../objects/p_update$o

../objects/p_user$o :	$(srcdir)/p_user.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_user.c -o ../objects/p_user$o

../objects/p_win$o :	$(srcdir)/p_win.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_NORMAL) -c ../panel/p_win.c -o ../objects/p_win$o


# generated by mk-1st.awk (subset=ticlib+termlib+ext_tinfo+base+ext_funcs)
#  name:          panel
#  traces:        DEBUG
#  MODEL:         DEBUG
#  CXX_MODEL:     DEBUG
#  model:         obj_g
#  prefix:        lib
#  suffix:        _g.a
#  subset:        ticlib+termlib+ext_tinfo+base+ext_funcs
#  driver:        no
#  ShlibVer:      rel
#  ShlibVerInfix: no
#  SymLink:       ln -s -f
#  TermlibRoot:   ncurses
#  TermlibSuffix: .a
#  ReLink:        no
#  ReRanlib:      no
#  DoLinks:       yes
#  rmSoLocs:      no
#  ldconfig:      :
#  overwrite:     yes
#  depend:        ../include/ncurses_cfg.h ./panel.priv.h
#  host:          arm-unknown-linux-gnu

DEBUG_OBJS = \
	../obj_g/panel$o \
	../obj_g/p_above$o \
	../obj_g/p_below$o \
	../obj_g/p_bottom$o \
	../obj_g/p_delete$o \
	../obj_g/p_hide$o \
	../obj_g/p_hidden$o \
	../obj_g/p_move$o \
	../obj_g/p_new$o \
	../obj_g/p_replace$o \
	../obj_g/p_show$o \
	../obj_g/p_top$o \
	../obj_g/p_update$o \
	../obj_g/p_user$o \
	../obj_g/p_win$o

$(DEBUG_OBJS) : ../include/ncurses_cfg.h ./panel.priv.h

../lib/libpanel_g.a : $(DEBUG_OBJS)
	@sleep 1
	$(AR) $(ARFLAGS) $@ $?
	$(RANLIB) $@

install \
install.libs \
install.panel :: $(DESTDIR)$(libdir) ../lib/libpanel_g.a
	@echo installing ../lib/libpanel_g.a as $(DESTDIR)$(libdir)/libpanel_g.a
	$(INSTALL_DATA) ../lib/libpanel_g.a $(DESTDIR)$(libdir)/libpanel_g.a

uninstall \
uninstall.libs \
uninstall.panel ::
	@echo uninstalling $(DESTDIR)$(libdir)/libpanel_g.a
	-@rm -f $(DESTDIR)$(libdir)/libpanel_g.a

clean ::
	-rm -f ../lib/libpanel_g.a

mostlyclean::
	-rm -f $(DEBUG_OBJS)

# generated by mk-2nd.awk
#   model:      obj_g
#   MODEL:      DEBUG
#   echo:       yes
#   subset:     ticlib+termlib+ext_tinfo+base+ext_funcs
#   crenames:   yes
#   cxxrenames: yes
#   traces:     DEBUG
#   srcdir:     .

../obj_g/panel$o :	$(srcdir)/panel.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/panel.c -o ../obj_g/panel$o

../obj_g/p_above$o :	$(srcdir)/p_above.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_above.c -o ../obj_g/p_above$o

../obj_g/p_below$o :	$(srcdir)/p_below.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_below.c -o ../obj_g/p_below$o

../obj_g/p_bottom$o :	$(srcdir)/p_bottom.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_bottom.c -o ../obj_g/p_bottom$o

../obj_g/p_delete$o :	$(srcdir)/p_delete.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_delete.c -o ../obj_g/p_delete$o

../obj_g/p_hide$o :	$(srcdir)/p_hide.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_hide.c -o ../obj_g/p_hide$o

../obj_g/p_hidden$o :	$(srcdir)/p_hidden.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_hidden.c -o ../obj_g/p_hidden$o

../obj_g/p_move$o :	$(srcdir)/p_move.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_move.c -o ../obj_g/p_move$o

../obj_g/p_new$o :	$(srcdir)/p_new.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_new.c -o ../obj_g/p_new$o

../obj_g/p_replace$o :	$(srcdir)/p_replace.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_replace.c -o ../obj_g/p_replace$o

../obj_g/p_show$o :	$(srcdir)/p_show.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_show.c -o ../obj_g/p_show$o

../obj_g/p_top$o :	$(srcdir)/p_top.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_top.c -o ../obj_g/p_top$o

../obj_g/p_update$o :	$(srcdir)/p_update.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_update.c -o ../obj_g/p_update$o

../obj_g/p_user$o :	$(srcdir)/p_user.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_user.c -o ../obj_g/p_user$o

../obj_g/p_win$o :	$(srcdir)/p_win.c \
			$(HEADER_DEPS)
	$(LIBTOOL_COMPILE) $(CC) $(CFLAGS_DEBUG) -c ../panel/p_win.c -o ../obj_g/p_win$o


# generated by mk-hdr.awk
#  subset:     ticlib+termlib+ext_tinfo+base+ext_funcs
#  compat:     yes

${INCLUDEDIR} :
	mkdir -p $@

install \
install.libs \
install.includes :: ${AUTO_SRC} ${INCLUDEDIR} \
		$(srcdir)/panel.h
	@ (cd ${INCLUDEDIR} && rm -f panel.h) ; ../headers.sh ${INSTALL_DATA} ${INCLUDEDIR} ${srcdir} $(srcdir)/panel.h

uninstall \
uninstall.libs \
uninstall.includes ::
	-@ (cd ${INCLUDEDIR} && rm -f panel.h)
depend : ${AUTO_SRC}
	makedepend -- ${CPPFLAGS} -- ${C_SRC}

# DO NOT DELETE THIS LINE -- make depend depends on it.
