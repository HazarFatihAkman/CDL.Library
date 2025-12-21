#include "../include/numbers.h"
#include "../include/utils.h"

#include <stdlib.h>

static void recapacity(numbers l) {
  if (l.capacity == 0) l.capacity = MIN_CAPACITY;
  else l.capacity *= 2;
}

void add_short(short x, numbers l) {
  int i = 0;
  foreach(i, l.count) {
    if (l.count >= l.capacity) {
      recapacity(l); 
      l.items.shorts = realloc(l.items.shorts, l.capacity*sizeof(*l.items.shorts)); 
    }

    l.items.shorts[l.count++] = x;
  }
}

void add_int(int x, numbers l) {
  int i = 0;
  foreach(i, l.count) {
    if (l.count >= l.capacity) {
      recapacity(l);
      l.items.ints = realloc(l.items.ints, l.capacity*sizeof(*l.items.ints));
    }

    l.items.ints[l.count++] = x;
  }
}


