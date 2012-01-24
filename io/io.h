#ifndef IO_H
#define IO_H

typedef enum IoPort_e
{
     IoPort_Com1Data            = 0x03f8,
     IoPort_Com1InterruptEnable,
     IoPort_Com1FifoControl,
     IoPort_Com1LineControl,
     IoPort_Com1ModemControl,
     IoPort_Com1LineStatus,
} IoPort;

void io_write8(IoPort io_port, unsigned char data);
unsigned char io_read8(IoPort io_port);

#endif /* IO_H */
