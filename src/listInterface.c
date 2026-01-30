#include "../include/listInterface.h"
#include "../include/utils.h"

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void recapacity(li_t *l) {
  if (l->capacity == 0) l->capacity = MIN_CAPACITY;
  else l->capacity *= 2;
}

void decapacity(li_t *l) {
  int mod_count = l->count % MIN_CAPACITY;
  if (mod_count >= MIN_CAPACITY) l->capacity -= MIN_CAPACITY;
}


void _push_v(void *v, li_t *l) {
  if (l->count >= l->capacity) {
    recapacity(l);
    l->items = realloc(l->items, l->capacity*sizeof(*l->items));
    if (l->items == NULL) {
      perror("Error");
      return;
    }
  }

  l->items[l->count++] = v;
}

void _pop_v(li_t *l) {
  --l->count;
  decapacity(l);

  l->items[l->count] = NULL;
  l->items = realloc(l->items, l->capacity*sizeof(*l->items));
  if (l->items == NULL) {
    perror("Error");
    return;
  }
}

void _remove_at(int index, li_t *l) {
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

