TARGET =	leaf

CC	?=		gcc

OPTFLAGS =	-Os

CFLAGS =    $(OPTFLAGS) \
			-I /usr/X11R6/include \
            -DVERSION=\"$(VERSION)\" \
            -D_XOPEN_SOURCE=600 \
            `pkg-config --cflags fontconfig`

LDFLAGS =   -lm -lrt -lX11 -lutil -lXft \
            -L /usr/X11R6/lib \
            `pkg-config --libs fontconfig`

PREFIX ?=	/usr
BINPREFIX ?=	$(PREFIX)/bin
MANPREFIX ?=	$(PREFIX)/share/man/man1

DOCPREFIX = 	doc
SRCPREFIX = 	src
BUILDPREFIX ?= 	build

SRC = 	$(SRCPREFIX)/leaf.c $(SRCPREFIX)/x.c
OBJ = 	$(subst $(SRCPREFIX), $(BUILDPREFIX), $(SRC:.c=.o))

all: prepare $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(BUILDPREFIX)/$(TARGET) $(OBJ) $(LDFLAGS)

$(BUILDPREFIX)/%.o: $(SRCPREFIX)/%.c
	$(CC) -o $@ $(CFLAGS) -c $<

prepare:
	mkdir -p $(BUILDPREFIX)

clean:
	rm -r $(BUILDPREFIX)

run:
	$(BUILDPREFIX)/$(TARGET)

install:
	install -m 755 -D $(BUILDPREFIX)/$(TARGET) $(BINPREFIX)/$(TARGET)
	install -m 655 -D $(DOCPREFIX)/leaf.1 $(MANPREFIX)/leaf.1

uninstall:
	rm $(BINPREFIX)/$(TARGET)
	rm $(MANPREFIX)/$(TARGET).1

# .PHONY: all options clean
