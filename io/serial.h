#ifndef SERIAL_H
#define SERIAL_H

void serial_init(void);
int serial_data_buffered(void);
char serial_read8(void);
void serial_write8(unsigned char c);
void serial_write_buffer(const char* buffer, unsigned long size);

#endif /* SERIAL_H */
