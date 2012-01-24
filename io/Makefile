include ../Makefile.inc

OBJECTS = io.c.o serial.c.o

all: ../libio.a

../libio.a: $(OBJECTS)
	$(AR) rcs $@ $^

.PHONY: clean

clean:
	@rm -f ../libio.a $(OBJECTS)
