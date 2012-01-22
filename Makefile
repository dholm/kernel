YASM = yasm
CC   = clang

CFLAGS = -Wall -Wextra -Werror -nostdlib -fno-builtin

all: main.c.o boot.S.o

%.c.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

%.S.o: %.S
	$(YASM) -f elf -o $@ $^
