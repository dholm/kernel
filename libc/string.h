#ifndef STRING_H
#define STRING_H

/**
 * Fill memory with constant
 * \param s Pointer to memory
 * \param c Constant
 * \param n Bytes to fill
 * \returns Pointer to memory
 */
void* memset(void* s, int c, unsigned long n);

/**
 * Copy memory area
 * \param dst Pointer to destination
 * \param src Pointer to source
 * \param len Length of block to copy
 * \returns Pointer to destination
 */
void* memcpy(void* dst, void* src, unsigned long len);

/**
 * Concatenate two strings in the first one's address space
 * \param s1 String 1
 * \param s2 String 2
 * \returns Pointer to resulting string
 */
char* strcat(char* s1, const char* s2);

/**
 * Calculate length of string
 * \param str String
 * \param len Maximum length of str
 * \returns Length of string in characters
 */
int strnlen(const char* str, unsigned long len);

/**
 * Compare two strings
 * \param s1 String 1
 * \param s2 String 2
 * \returns Smaller than, equal to or greater than zero if s1 is smaller, equal or greater than s2
 */
int strcmp(const char* s1, const char* s2);

#endif /* STRING_H */
