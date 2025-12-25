#include "../include/numbers.h"
#include "../include/utils.h"

#include <stdio.h>
#include <stdlib.h>

static void recapacity(numbers *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

static int decapacity(numbers *l) {
  if (l->count % MIN_CAPACITY > MIN_CAPACITY) {
    l->capacity -= MIN_CAPACITY;
    return 1;
  }

  return 0;
}

void _push_short(short x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.shorts = realloc(l->items.shorts, l->capacity*sizeof(*l->items.shorts));
    if (l->items.shorts == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != SHORT) l->type = SHORT;

  l->items.shorts[l->count++] = x;
}

void _push_int(int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
    if (l->items.ints == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != INT) l->type = INT;

  l->items.ints[l->count++] = x;
}

void _push_long(long x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
    if (l->items.longs == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != LONG) l->type = LONG;

  l->items.longs[l->count++] = x;
}

void _push_uint(unsigned int x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
    if (l->items.u_ints == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != UINT) l->type = UINT;

  l->items.u_ints[l->count++] = x;
}

void _push_d(double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
    if (l->items.doubles == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != DOUBLE) l->type = DOUBLE;

  l->items.doubles[l->count++] = x;
}

void _push_ld(long double x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
    if (l->items.l_doubles == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != LDOUBLE) l->type = LDOUBLE;

  l->items.l_doubles[l->count++] = x;
}

void _push_f(float x, numbers *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
    if (l->items.floats == NULL) {
      perror("Error");
      return;
    }
  }

  if (l->type != FLOAT) l->type = FLOAT;

  l->items.floats[l->count++] = x;
}

static void _pop_short(numbers *l) {
  l->items.shorts[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.shorts = realloc(l->items.shorts, l->capacity*sizeof(*l->items.shorts));
    if (l->items.shorts == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_int(numbers *l) {
  l->items.ints[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.ints = realloc(l->items.ints, l->capacity*sizeof(*l->items.ints));
    if (l->items.ints == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_long(numbers *l) {
  l->items.longs[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
    if (l->items.longs == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_uint(numbers *l) {
  l->items.u_ints[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
    if (l->items.u_ints == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_d(numbers *l) {
  l->items.doubles[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
    if (l->items.doubles == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_ld(numbers *l) {
  l->items.l_doubles[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
    if (l->items.floats == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _pop_f(numbers *l) {  
  l->items.floats[l->count] = 0;

  --l->count;
  if (decapacity(l) == 1) {
    l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
    if (l->items.floats == NULL) {
      perror("Error");
      return;
    }
  }
}

void _n_pop(numbers *l) {
  switch (l->type) {
    case SHORT:   _pop_short(l); break;
    case INT:     _pop_int(l);   break;
    case LONG:    _pop_long(l);  break;
    case UINT:    _pop_uint(l);  break;
    case DOUBLE:  _pop_d(l);     break;
    case LDOUBLE: _pop_ld(l);    break;
    case FLOAT:   _pop_f(l);     break;
    default: break;
  }
}

// _r_n abbreviation = remove_number
static void _r_n_short(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) {
      l->items.shorts[i] = l->items.shorts[i + 1]; 
    }
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.shorts = realloc(l->items.shorts, l->capacity*sizeof(*l->items.shorts));
    if (l->items.shorts == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_int(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.ints[i] = l->items.ints[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.ints = realloc(l->items.shorts, l->capacity*sizeof(*l->items.ints));
    if (l->items.ints == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_long(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.longs[i] = l->items.longs[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.longs = realloc(l->items.longs, l->capacity*sizeof(*l->items.longs));
    if (l->items.longs == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_uint(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.u_ints[i] = l->items.u_ints[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.u_ints = realloc(l->items.u_ints, l->capacity*sizeof(*l->items.u_ints));
    if (l->items.u_ints == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_d(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.doubles[i] = l->items.doubles[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.doubles = realloc(l->items.doubles, l->capacity*sizeof(*l->items.doubles));
    if (l->items.doubles == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_ld(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.l_doubles[i] = l->items.l_doubles[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.l_doubles = realloc(l->items.l_doubles, l->capacity*sizeof(*l->items.l_doubles));
    if (l->items.l_doubles == NULL) {
      perror("Error");
      return;
    }
  }
}

static void _r_n_f(int index, numbers *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items.floats[i] = l->items.floats[i + 1];
  }

  --l->count;
  if (decapacity(l) == 1) {
    l->items.floats = realloc(l->items.floats, l->capacity*sizeof(*l->items.floats));
    if (l->items.floats == NULL) {
      perror("Error");
      return;
    }
  }
}

void _n_remove(int i, numbers *l) {
  switch (l->type) {
    case SHORT:   _r_n_short(i, l); break;
    case INT:     _r_n_int(i, l);   break;
    case LONG:    _r_n_long(i, l);  break;
    case UINT:    _r_n_uint(i, l);  break;
    case DOUBLE:  _r_n_d(i, l);     break;
    case LDOUBLE: _r_n_ld(i, l);    break;
    case FLOAT:   _r_n_f(i, l);     break;
    default: break;
  }
}

