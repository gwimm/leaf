TARGETS =		leaf

CC	?=			cc

PREFIX ?=		/usr
BINPREFIX ?=	$(PREFIX)/bin
MANPREFIX ?=	$(PREFIX)/share/man/man1

DOCPREFIX = 	doc
SRCPREFIX = 	src
BUILDPREFIX ?= 	build

VERSION =		$(shell git describe --always --dirty 2> /dev/null)

OPTFLAGS =		-Os
CDEPS = $(shell pkg-config --cflags x11-xcb xft fontconfig)
CFLAGS =    	$(OPTFLAGS) \
				$(CDEPS) \
            	-DVERSION=\"$(VERSION)\" \
            	-D_XOPEN_SOURCE=600 \

LDLIBS =		$(shell pkg-config --libs x11-xcb xft fontconfig)	
LDFLAGS =   	-lm -lrt -lutil -s \
				$(LDLIBS)

