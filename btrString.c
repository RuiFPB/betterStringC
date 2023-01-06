#include <stdlib.h>
#include <string.h>
#include "btrString.h"

BtrStr *btrStr_new(const char *init) {
    BtrStr *s = malloc(sizeof(BtrStr));
    if (init == NULL) {
        s->length = 0;
        s->str = malloc(sizeof(char));
        s->str[0] = '\0';
    } else {
        s->length = strlen(init);
        s->str = malloc(s->length + 1);
        strcpy(s->str, init);
    }
    return s;
}

void btrStr_delete(BtrStr *s) {
    free(s->str);
    free(s);
}

void btrStr_append_cstr(BtrStr *s, const char *str) {
    size_t newLength = s->length + strlen(str);
    s->str = realloc(s->str, newLength + 1);
    strcpy(s->str + s->length, str);
    s->length = newLength;
}

void btrStr_append(BtrStr *s, BtrStr *s2) {
    size_t newLength = s->length + s2->length;
    s->str = realloc(s->str, newLength + 1);
    strcpy(s->str + s->length, s2->str);
    s->length = newLength;
}

void btrStr_set_cstr(BtrStr *s, const char *str) {
    size_t newLength = strlen(str);
    s->str = realloc(s->str, newLength + 1);
    strcpy(s->str, str);
    s->length = newLength;
}

void btrStr_set(BtrStr *s, BtrStr *s2) {
    size_t newLength = s2->length;
    s->str = realloc(s->str, newLength + 1);
    strcpy(s->str, s2->str);
    s->length = newLength;
}

char *btrStr_cstr(BtrStr *s)
{
    return s->str;
}

size_t btrStr_length(BtrStr *s)
{
    return s->length;
}
