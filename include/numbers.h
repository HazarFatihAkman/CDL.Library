#ifndef CDL_LIBRARY_NUMBERS_H
#define CDL_LIBRARY_NUMBERS_H

#include <sys/types.h>
#include "dataTypes.h"

typedef union {
  short int    *shorts;
  int          *ints;
  long         *longs;
  unsigned int *u_ints;
  double       *doubles;
  long double  *l_doubles;
  float        *floats;
} item_types;

typedef struct {
  item_types items;
  DataType type;
  size_t count;
  size_t capacity;
} numbers;

void add_short(short int x, numbers l);
void add_int(int x, numbers l);

#define push(x, l) _Generic((x), \
    short int: add_short, \
    int:       add_int \
)(x, l)

#endif // CDL_LIBRARY_NUMBERS_H
 
