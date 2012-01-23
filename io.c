#include "io.h"

unsigned char io_read8(IoPort io_port)
{
     unsigned char read_byte = 0;
     asm volatile ("inb %1, %0" :
		   "=a" (read_byte) :
		   "dN" ((unsigned short) io_port));
     return read_byte;
}

void io_write8(IoPort io_port, unsigned char data)
{
     asm volatile ("outb %1, %0" :
		   :
		   "dN" ((unsigned short) io_port), "a" (data));
}
