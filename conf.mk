TARGETS =		leaf

CC	?=			cc
LD	=			$(CC)

DOCPREFIX = 	doc
SRCPREFIX = 	src
BUILDPREFIX ?= 	bin

PREFIX ?=		/usr
BINPREFIX ?=	$(PREFIX)/bin
MANPREFIX ?=	$(PREFIX)/share/man/man1

VERSION =		$(shell git describe --always --dirty 2> /dev/null)

OPTFLAGS =		-Os
CFLAGS =    	$(OPTFLAGS) \
				$(CDEPS) \
            	-DVERSION=\"$(VERSION)\" \
            	-D_XOPEN_SOURCE=600 \
				$(shell pkg-config --cflags x11-xcb xft fontconfig)

LDLIBS =		$(shell pkg-config --libs x11-xcb xft fontconfig)	
LDFLAGS =   	-lm -lrt -lutil -s \
				$(LDLIBS)

