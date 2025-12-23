#include "../include/numbers.h"
#include "../include/utils.h"

#include <stdlib.h>

static void recapacity(numbers *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

static void decapacity(numbers *l) {
  int mod_count = l->count % MIN_CAPACITY;
  if (mod_count >= MIN_CAPACITY) l->capacity -= MIN_CAPACITY;
}

void _push_short(short x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
  }

  if (l->type != SHORT) l->type = SHORT;

  l->items.shorts[l->count++] = x;
}

void _push_int(int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
  }

  if (l->type != INT) l->type = INT;

  l->items.ints[l->count++] = x;
}

void _push_long(long x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
  }

  if (l->type != LONG) l->type = LONG;

  l->items.longs[l->count++] = x;
}

void _push_uint(unsigned int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
  }

  if (l->type != UINT) l->type = UINT;

  l->items.u_ints[l->count++] = x;
}

void _push_d(double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
  }

  if (l->type != DOUBLE) l->type = DOUBLE;

  l->items.doubles[l->count++] = x;
}

void _push_ld(long double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
  }

  if (l->type != LDOUBLE) l->type = LDOUBLE;

  l->items.l_doubles[l->count++] = x;
}

void _push_f(float x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
  }

  if (l->type != FLOAT) l->type = FLOAT;

  l->items.floats[l->count++] = x;
}

static void pop_short(numbers *l) {
  l->items.shorts = realloc(l->items.shorts, l->capacity*sizeof(*l->items.shorts));
}

static void pop_int(numbers *l) {
  l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
}

static void pop_long(numbers *l) {
  l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
}

static void pop_uint(numbers *l) {
  l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
}

static void pop_d(numbers *l) {
  l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
}

static void pop_ld(numbers *l) {
  l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
}

static void pop_f(numbers *l) {
  l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
}

void _n_pop(numbers *l) {
  --l->count;
  decapacity(l);

  switch (l->type) {
    case SHORT:   pop_short(l);
    case INT:     pop_int(l);
    case LONG:    pop_long(l);
    case UINT:    pop_uint(l);
    case DOUBLE:  pop_d(l);
    case LDOUBLE: pop_ld(l);
    case FLOAT:   pop_f(l);
    default: break;
  }
}

