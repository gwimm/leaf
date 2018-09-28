include conf.mk

MAN =	$(wildcard $(DOCPREFIX)/*.1)

SRC = 	$(wildcard $(SRCPREFIX)/*.c)
OBJ = 	$(subst $(SRCPREFIX), $(BUILDPREFIX), $(SRC:.c=.o))

.PHONY: all clean

all: prepare build

build: $(TARGETS)

$(TARGETS): $(OBJ)
	@printf "[34mLD[0m :: $@\n"
	$(CC) -o $(BUILDPREFIX)/$(TARGETS) $(OBJ) $(LDFLAGS)

$(BUILDPREFIX)/%.o: $(SRCPREFIX)/%.c
	@printf "[32mCC[0m :: $@\n"
	$(CC) -o $@ $(CFLAGS) -c $<

prepare:
	mkdir -p $(BUILDPREFIX)

clean:
	@printf "[32mcleaning, master uwu\n"
	-@rm -r $(BUILDPREFIX)

run:
	$(BUILDPREFIX)/$(TARGETS)

install:
	install -m 755 -D $(BUILDPREFIX)/$(TARGETS) $(BINPREFIX)/$(TARGETS)
	install -m 655 -D $(subst $(DOCPREFIX), $(MANPREFIX), $(MAN)) $(MAN)

uninstall:
	-rm $(BINPREFIX)/$(TARGETS)
	-rm $(MANPREFIX)/$(TARGETS).1

# .PHONY: all options clean
