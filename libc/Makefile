include ../Makefile.inc

OBJECTS = string.c.o vsprintf.c.o

all: libc.a

libc.a: $(OBJECTS)
	$(AR) rcs $@ $^

.PHONY: clean

clean:
	@rm -f libc.a $(OBJECTS)
