#include "../include/strings.h"
#include "../include/utils.h"
#include <stdlib.h>

static void recapacity(strings *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

void add_s(const char *x, strings *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items = realloc(l->items, l->capacity*sizeof(*l->items));
  }

  l->items[l->count++] = x;
}

