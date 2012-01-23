#include "string.h"

void* memcpy(void* dst, void* src, unsigned long len)
{
	unsigned char* d = (unsigned char*) dst;
	unsigned char* s = (unsigned char*) src;

	while (len--) {
		*d++ = *s++;
	}

	return dst;
}

char* strcat(char* s1, const char* s2)
{
	char* t = s1;

	if (!s1 || !s2) {
		return 0L;
	}

	for (; *t; ++t) {
		continue;
	}

	while ((*t++ = *s2++) != '\0') {
		continue;
	}

	return s1;
}

int strnlen(const char* str, unsigned long len)
{
	const char *s;
	unsigned int i;

	if (!str) {
		return 0;
	}

	for (s = str, i = 0; *s && i < len; ++s, ++i) {
		continue;
	}

	return i;
}

int strcmp(const char* s1, const char* s2)
{
	if (!s1 || !s2) {
		// FIXME: Assert
		return -1;
	}

	while (*s1 == *s2++) {
		if (*s1++ == 0) {
			return 0;
		}
	}

	return (*(const unsigned char *) s1 - *(const unsigned char *) --s2);
}

void* memset(void* s, int c, unsigned long len)
{
	char* p = (char*) s;

	while (len--) {
		*p++ = c;
	}

	return s;
}
