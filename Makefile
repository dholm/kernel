include Makefile.inc

CFLAGS += -Ilibc

OBJECTS = serial.c.o io.c.o \
	  main.c.o boot.S.o

all: kernel.bin

libc/libc.a:
	$(MAKE) -C libc

kernel.bin: libc/libc.a $(OBJECTS)
	$(LD) -T cernel.ld -o $@ $^

.PHONY: clean

clean:
	@make -C libc clean
	@rm -f kernel.bin $(OBJECTS)
