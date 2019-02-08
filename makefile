include conf.mk

MAN :=	$(wildcard $(DOCPREFIX)/*.1)

SRC := 	$(wildcard $(SRCPREFIX)/*.c)
OBJ := 	$(subst $(SRCPREFIX),$(BUILDPREFIX),$(SRC:.c=.o))

TARGETS := $(addprefix $(BUILDPREFIX)/, $(TARGETS))
DEPS :=	$(OBJ)

.PHONY: all clean

all: build

build: $(TARGETS)

$(TARGETS): $(OBJ)
	@printf "[34mLD[0m :: $@\n"
	@$(LD) -o $@ $(DEPS) $(LDFLAGS)

$(BUILDPREFIX)/%.o: $(SRCPREFIX)/%.c
	@[ -d build ] || mkdir -p $(BUILDPREFIX)
	@printf "[32mCC[0m :: $@\n"
	@$(CC) -o $@ $(CFLAGS) -c $<

clean:
	@printf "[32mcleaning, master uwu\n"
	-@rm -r $(BUILDPREFIX)

install:
	install -m 755 -D \
		$(subst $(BUILDPREFIX), $(BINPREFIX), $(TARGETS)) $(DESTDIR)$(BINPREFIX)
	install -m 655 -D \
		$(subst $(DOCPREFIX), $(MANPREFIX), $(MAN)) $(DESTDIR)$(MANPREFIX)
	tic -sx $(DOCPREFIX)/leaf.info

uninstall:
	-rm \
		$(DESTDIR)$(subst $(BUILDPREFIX), $(BINPREFIX), $(TARGETS))
	-rm \
		$(DESTDIR)$(subst $(DOCPREFIX), $(MANPREFIX), $(MAN))
