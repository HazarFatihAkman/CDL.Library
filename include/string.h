#ifndef CDL_LIBRARY_STRING_H
#define CDL_LIBRARY_STRING_H

#include <sys/types.h>

#define DEFAULT_STRING_SIZE 

typedef struct string_wrapper {
  char *value;
  size_t size;
} string_t;

void alloc_str(string_t val, size_t size);
void free_str();

#endif //CDL_LIBRARY_STRING_H

