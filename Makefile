YASM = yasm
CC   = clang

all: boot.S.o

%.S.o: %.S
	$(YASM) -f elf -o $@ $^
