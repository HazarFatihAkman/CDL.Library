#include "../include/numbers.h"

#include <stdlib.h>

static void recapacity(numbers *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

void add_short(short x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
  }

  l->items.shorts[l->count++] = x;
}

void add_int(int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
  }

  l->items.ints[l->count++] = x;
}

void add_long(long x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
  }

  l->items.longs[l->count++] = x;
}

void add_uint(unsigned int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
  }

  l->items.u_ints[l->count++] = x;
}

void add_d(double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
  }

  l->items.doubles[l->count++] = x;
}

void add_ld(long double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
  }

  l->items.l_doubles[l->count++] = x;
}

void add_f(float x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
  }

  l->items.floats[l->count++] = x;
}

