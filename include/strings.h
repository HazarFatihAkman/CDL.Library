#ifndef CDL_LIBRARY_STRINGS_H
#define CDL_LIBRARY_STRINGS_H

#include <sys/types.h>

typedef struct {
  const char **items;
  size_t count;
  size_t capacity;
} strings;

void push_s(const char *x, strings *l);

#define str_push(x, l) push_s(x, l)

#endif // CDL_LIBRARY_STRINGS_H
