MAKE = make
YASM = yasm
CC   = clang
LD   = i686-elf-ld
AR   = i686-elf-ar

CFLAGS = -march=i686 -ccc-host-triple i686-elf \
	 -integrated-as \
	 -nostdlib -fno-builtin -ffreestanding \
	 -Wall -Wextra -Werror

%.c.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

%.S.o: %.S
	$(YASM) -f elf -o $@ $^

