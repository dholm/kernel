include ../Makefile.inc

CFLAGS += -I../io -I../libc -I../libkern -I../

OBJECTS = boot.S.o main.c.o

all: ../libinit.a

../libinit.a: $(OBJECTS)
	$(AR) rcs $@ $^

.PHONY: clean

clean:
	@rm -f ../libinit.a $(OBJECTS)
