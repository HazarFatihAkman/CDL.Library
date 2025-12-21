#include "../include/numbers.h"
#include "../include/utils.h"

#include <stdio.h>

int main() {
  numbers l = {0};

  int val = 1;
  push(val, l);

  int i = 0;

  printf("Test\n");
  printf("%zu\n", l.count);
  foreach(i, l.count) {
    printf("%d\n", l.items.ints[i]);    
  }

  return 0;
}
