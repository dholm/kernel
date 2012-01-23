#ifndef SERIAL_H
#define SERIAL_H

void serial_init(void);
char serial_read8(void);
void serial_write8(unsigned char c);
void serial_write_buffer(const unsigned char* buffer, unsigned long size);

#endif /* SERIAL_H */
