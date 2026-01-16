#include "../include/strings.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void recapacity(strings *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

static void decapacity(strings *l) {
  int mod_count = l->count % MIN_CAPACITY;
  if (mod_count >= MIN_CAPACITY) l->capacity -= MIN_CAPACITY;
}

void _push_s(const char *x, strings *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items = realloc(l->items, l->capacity*sizeof(*l->items));
    if (l->items == NULL) {
      perror("Error");
      return;
    }
  }

  l->items[l->count++] = x;
}

void _pop_s(strings *l) {
  --l->count;
  decapacity(l);

  l->items[l->count] = NULL;
  l->items = realloc(l->items, l->capacity*sizeof(*l->items));
  if (l->items == NULL) {
    perror("Error");
    return;
  }
}

void _remove_s(int index, strings *l) {
  for (int i = 0; i < l->count; ++i) {
    if (index <= i) l->items[i] = l->items[i + 1];
  }

  --l->count;
  decapacity(l);

  l->items[l->count] = NULL;
  l->items = realloc(l->items, l->capacity*sizeof(*l->items));
  if (l->items == NULL) {
    perror("Error");
    return;
  }
}

