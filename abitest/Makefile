X86_64DIR = /opt/x86-64
LINK = $(X86_64DIR)/bin/simnowlink
CC = x86_64-unknown-linux-gcc
CFLAGS = -O -Wall

TYPELISTSOURCES = typelist.h typelist.c
AUTOSOURCES = sizal2.c scalarargs2.c
AUTOEXECS = make_sizal2 make_scalarargs2
AUTOCFLAGS = -O2 -Wall

SOURCES = main.c sizal.c scalarargs.c struniargs.c variargs.c reloc.c \
	bitfields.c $(AUTOSOURCES)
OBJECTS = ${SOURCES:.c=.o}
ASMSOURCES = ${SOURCES:.c=.s}

#TARGET = abitest
TARGET = /usr/local/share/simnow/images/start64.ram


.SUFFIXES = .s


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LINK) $(OBJECTS)

clean:
	$(RM) *.o *~ core make_sizal2 $(AUTOSOURCES) $(AUTOEXECS) a.out

.PHONY: clean dist-clean backup all dep depend

dist-clean: clean
	$(RM) $(ASMSOURCES) .Makefile.deps

sizal2.c: make_sizal2
	make_sizal2 > sizal2.c

make_sizal2: make_sizal2.c $(TYPELISTSOURCES)
	gcc $(AUTOCFLAGS) -o make_sizal2 make_sizal2.c typelist.c

scalarargs2.c: make_scalarargs2
	make_scalarargs2 > scalarargs2.c

make_scalarargs2: make_scalarargs2.c ${TYPELISTSOURCES}
	gcc $(AUTOCFLAGS) -o make_scalarargs2 make_scalarargs2.c typelist.c


backup:
	$(MAKE) clean
	cd ..; tar czvf abitest-`date +%m%d`.tar.gz abitest

# Use `make source.s` if you want to see the assembler output
.c.s:
	$(CC) $(CFLAGS) -S $<

# Make makefile dependencies
dep depend: make_sizal2.c make_scalarargs2.c
	gcc -MM $(SOURCES) make_sizal2.c make_scalarargs2.c typelist.c > .Makefile.deps.temp
	sed < .Makefile.deps.temp > .Makefile.deps "s@:@::@g"
	rm .Makefile.deps.temp

-include .Makefile.deps