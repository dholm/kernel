#include "io.h"
#include "serial.h"

void serial_init(void)
{
     io_write8(IoPort_Com1InterruptEnable, 0x00);
     io_write8(IoPort_Com1LineControl,     0x80);
     io_write8(IoPort_Com1Data,            0x03);
     io_write8(IoPort_Com1InterruptEnable, 0x00);
     io_write8(IoPort_Com1LineControl,     0x03);
     io_write8(IoPort_Com1FifoControl,     0xc7);
     io_write8(IoPort_Com1ModemControl,    0x0b);
}

int serial_data_buffered(void)
{
     return io_read8(IoPort_Com1LineStatus) & 1;
}

char serial_read8(void)
{
     while (0 == serial_data_buffered());
     return io_read8(IoPort_Com1Data);
}

static int serial_transmit_buffer_empty(void)
{
     return io_read8(IoPort_Com1LineStatus) & 0x20;
}

void serial_write8(unsigned char c)
{
     while (0 == serial_transmit_buffer_empty());
     io_write8(IoPort_Com1Data, c);
}

void serial_write_buffer(const char* buffer, unsigned long size)
{
     for (unsigned long i = 0; i < size; ++i)
     {
          serial_write8(buffer[i]);
     }
}
