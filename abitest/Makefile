CC = x86_64-unknown-linux-gcc
CFLAGS = -O -Wall
SOURCES = main.c sizal.c scalarargs.c struniargs.c variargs.c reloc.c \
	bitfields.c sizal2.c
OBJECTS = ${SOURCES:.c=.o}
ASMSOURCES = ${SOURCES:.c=.s}
#TARGET = abitest
TARGET = /usr/local/share/simnow/images/start64.ram
LINK = $(X86_64DIR)/bin/simnowlink
X86_64DIR = /opt/x86-64

.SUFFIXES = .s

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(OBJECTS)

clean:
	$(RM) *.o *~ core make_sizal2 $(AUTOSOURCES) a.out

.PHONY: clean dist-clean backup all dep depend

dist-clean: clean
	$(RM) $(ASMSOURCES) .Makefile.deps

sizal2.c: make_sizal2
	make_sizal2 > sizal2.c

make_sizal2: make_sizal2.c
	gcc -g -Wall -o make_sizal2 make_sizal2.c

backup:
	$(MAKE) clean
	cd ..; tar czvf abitest-`date +%m%d`.tar.gz abitest

# Use `make source.s` if you want to see the assembler output
.c.s:
	$(CC) $(CFLAGS) -S $<

# Make makefile dependencies
dep depend: $(AUTOSOURCES)
	gcc -MM $(SOURCES) make_sizal2.c > .Makefile.deps

-include .Makefile.deps