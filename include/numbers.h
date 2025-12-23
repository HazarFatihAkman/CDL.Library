#ifndef CDL_LIBRARY_NUMBERS_H
#define CDL_LIBRARY_NUMBERS_H

#include <sys/types.h>

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

// pushing
void push_short (short int x, numbers *l);
void push_int   (int x, numbers *l);
void push_long  (long x, numbers *l);
void push_uint  (unsigned int x, numbers *l);
void push_d     (double x, numbers *l);
void push_ld    (long double x, numbers *l);
void push_f     (float x, numbers *l);

#define n_push(x, l) _Generic((x), \
    short int:    push_short, \
    int:          push_int,   \
    long:         push_long,  \
    unsigned int: push_uint,  \
    double:       push_d,     \
    long double:  push_ld,    \
    float:        push_f      \
)(x, l)

#endif // CDL_LIBRARY_NUMBERS_H
 
