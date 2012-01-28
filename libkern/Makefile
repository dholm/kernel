include ../Makefile.inc

CFLAGS += -I../libc -I../

OBJECTS = command.c.o

all: ../libkern.a

../libkern.a: $(OBJECTS)
	$(AR) rcs $@ $^

.PHONY: clean

clean:
	@rm -f ../libkern.a $(OBJECTS)
