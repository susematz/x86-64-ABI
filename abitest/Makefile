CC = x86_64-unknown-linux-gcc
CFLAGS = -O -Wall
SOURCES = main.c sizal.c scalarargs.c structargs.c variargs.c reloc.c
OBJECTS = ${SOURCES:.c=.o}
ASMSOURCES = ${SOURCES:.c=.s}
AUTOSOURCES = sizal2.c
#TARGET = abitest
TARGET = /usr/local/share/simnow/images/start64.ram
LINK = /opt/x86-64/bin/simnowlink

.SUFFIXES = .s

all: $(TARGET)

$(TARGET): $(AUTOSOURCES) $(OBJECTS)
	$(LINK) $(OBJECTS)

clean:
	$(RM) *.o *~ core make_sizal2 $(AUTOSOURCES) $(ASMSOURCES) a.out

sizal2.c: make_sizal2
	make_sizal2 > sizal2.c

make_sizal2: make_sizal2.c
	gcc -o make_sizal2 make_sizal2.c

backup:
	$(MAKE) clean
	cd ..; tar czvf abitest-`date +%m%d`.tar.gz abitest

# Use `make source.s` if you want to see the assembler output
.c.s:
	$(CC) $(CFLAGS) -S $<
