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
  size_t count;
  size_t capacity;
} numbers;

void add_short (short int x, numbers *l);
void add_int   (int x, numbers *l);
void add_long  (long x, numbers *l);
void add_uint  (unsigned int x, numbers *l);
void add_d     (double x, numbers *l);
void add_ld    (long double x, numbers *l);
void add_f     (float x, numbers *l);

#define n_push(x, l) _Generic((x), \
    short int:    add_short, \
    int:          add_int,   \
    long:         add_long,  \
    unsigned int: add_uint,  \
    double:       add_d,     \
    long double:  add_ld,    \
    float:        add_f      \
)(x, l)

#endif // CDL_LIBRARY_NUMBERS_H
 
