include Makefile.inc

CFLAGS += -Ilibc

OBJECTS = serial.c.o io.c.o \
	  main.c.o boot.S.o

all: kernel.bin

kernel.bin: $(OBJECTS)
	$(LD) -T cernel.ld -o $@ $^

.PHONY: clean

clean:
	@rm -f kernel.bin $(OBJECTS)
