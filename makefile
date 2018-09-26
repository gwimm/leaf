TARGETS =	leaf

CC	?=		gcc
STRIP ?=	strip

OPTFLAGS =	-Os

CFLAGS =    $(OPTFLAGS) \
			-I /usr/X11R6/include \
            -DVERSION=\"$(VERSION)\" \
            -D_XOPEN_SOURCE=600 \
            $(shell pkg-config --cflags fontconfig)

LDFLAGS =   -lm -lrt -lX11 -lutil -lXft \
            -L /usr/X11R6/lib \
            $(shell pkg-config --libs fontconfig)

PREFIX ?=	/usr
BINPREFIX ?=	$(PREFIX)/bin
MANPREFIX ?=	$(PREFIX)/share/man/man1

DOCPREFIX = 	doc
SRCPREFIX = 	src
BUILDPREFIX ?= 	build

MAN =	$(wildcard $(DOCPREFIX)/*.1)

SRC = 	$(wildcard $(SRCPREFIX)/*.c)
OBJ = 	$(subst $(SRCPREFIX), $(BUILDPREFIX), $(SRC:.c=.o))

.PHONY: all clean

all: prepare build strip

strip:
	$(STRIP) $(BUILDPREFIX)/$(TARGETS)
	
build: $(TARGETS)

$(TARGETS): $(OBJ)
	$(CC) -o $(BUILDPREFIX)/$(TARGETS) $(OBJ) $(LDFLAGS)

$(BUILDPREFIX)/%.o: $(SRCPREFIX)/%.c
	$(CC) -o $@ $(CFLAGS) -c $<

prepare:
	mkdir -p $(BUILDPREFIX)

clean:
	-rm -r $(BUILDPREFIX)

run:
	$(BUILDPREFIX)/$(TARGETS)

install:
	install -m 755 -D $(BUILDPREFIX)/$(TARGETS) $(BINPREFIX)/$(TARGETS)
	install -m 655 -D $(subst $(DOCPREFIX), $(MANPREFIX), $(MAN)) $(MAN)

uninstall:
	-rm $(BINPREFIX)/$(TARGETS)
	-rm $(MANPREFIX)/$(TARGETS).1

# .PHONY: all options clean
