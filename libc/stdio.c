#include <serial.h>
#include <string.h>

#include "vsprintf.h"
#include "stdio.h"

void vfprintf(char *fmt, va_list ap)
{
    static char printf_buf[2048] = {0, };
    vsprintf(printf_buf, fmt, ap);
    serial_write_buffer(printf_buf, strnlen(printf_buf, sizeof(printf_buf)));
}

void printf(char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(fmt, ap);
    va_end(ap);
}
