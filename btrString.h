#ifndef BETTER_STRING_H
#define BETTER_STRING_H

#include <stdlib.h>

/**
 * BtrStr is the structure that this library uses to handle strings
 * @see btrStr_new for creating a new BtrStr.
 * @see btrStr_delete for freeing the memory used by the BtrStr.
 */
typedef struct _BtrStr {
    /** The C String used by the library to store the text */
    char *str;
    /** The length of the string */
    size_t length;
} BtrStr;

#ifdef BTRSTRING_STRINGTYPE

typedef BtrStr String;

#endif

// (I know Objects do not exist in C, I'm not a morron)
/**
 * Creates a new BtrStr "object" with the given initial string.
 * If the initial string is NULL, the BtrStr will be empty.
 * @param init The initial string, or NULL.
 * @return Pointer to the new BtrStr.
*/
BtrStr *btrStr_new(const char *init);

/**
 * Frees the memory used by the BtrStr.
 * (Comparable to a destructor in C++) (You actually need to call this one at the end)
 * @param s The BtrStr to free.
*/
void btrStr_delete(BtrStr *s);

/**
 * Appends a C string to the BtrStr.
 * @param s The BtrStr to append to.
 * @param str The C string to append.
*/
void btrStr_append_cstr(BtrStr *s, const char *str);

/**
 * Appends a BtrStr to the BtrStr.
 * @param s The BtrStr to append to.
 * @param s2 The BtrStr to append.
*/
void btrStr_append(BtrStr *s, BtrStr *s2);

/**
 * Sets the BtrStr to the given C string.
 * @param s The BtrStr to set.
 * @param str The C string to set the BtrStr to.
*/
void btrStr_set_cstr(BtrStr *s, const char *str);

/**
 * Sets the BtrStr to the given BtrStr.
 * @param s The BtrStr to set.
 * @param s2 The BtrStr to set the BtrStr to.
*/
void btrStr_set(BtrStr *s, BtrStr *s2);

/**
 * Gets the C string from the BtrStr.
 * Usefull to use with printf.
 * @param s The BtrStr to get the C string from.
 * @return The C string from the BtrStr.
*/
char *btrStr_cstr(BtrStr *s);

/**
 * Gets the length of the BtrStr.
 * @param s The BtrStr to get the length of.
 * @return The length of the BtrStr.
*/
size_t btrStr_length(BtrStr *s);

#endif