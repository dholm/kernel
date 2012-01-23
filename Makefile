YASM = yasm
CC   = clang
LD   = i686-elf-ld

CFLAGS = -march=i686 -ccc-host-triple i686-elf \
	 -integrated-as \
	 -nostdlib -fno-builtin -ffreestanding \
	 -Wall -Wextra -Werror

OBJECTS = serial.c.o io.c.o main.c.o boot.S.o

all: kernel.bin

kernel.bin: $(OBJECTS)
	$(LD) -T cernel.ld -o $@ $^

.PHONY: clean

%.c.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

%.S.o: %.S
	$(YASM) -f elf -o $@ $^

clean:
	@rm -f kernel.bin $(OBJECTS)
