#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>

void vfprintf(char *fmt, va_list ap);
void printf(char *fmt, ...);

#endif /* STDIO_H */
