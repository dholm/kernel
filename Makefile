include Makefile.inc

SUBDIRS = init libc io

all: kernel.bin

kernel.bin: libinit.a libkern.a libio.a libc.a
	$(LD) -T kernel.ld -o $@ $^

libkern.a: force_look
	$(MAKE) -C libkern

libinit.a: force_look
	$(MAKE) -C init

libio.a: force_look
	$(MAKE) -C io

libc.a: force_look
	$(MAKE) -C libc

.PHONY: clean

clean:
	@for dir in $(SUBDIRS); do (make -C $$dir clean); done
	@rm -f kernel.bin $(OBJECTS)

force_look:
	@true
