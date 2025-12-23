#include "../include/numbers.h"
#include "../include/utils.h"

#include <stdio.h>

int main() {
  numbers l = {0};

  int val = 10;
  n_push(val, &l);
  n_push(20, &l);

  for (size_t i = 0; i < l.count; ++i) printf("%d : %zu\n", l.items.ints[i], i); 

  numbers l2 = {0};
  short int sval = 11;
  n_push(sval, &l2);

  printf("Shorts \n");
  for (size_t i = 0; i < l2.count; ++i) printf("%d : %zu\n", l2.items.shorts[i], i);

  numbers l3 = {0};
  long lval = 12;
  n_push(lval, &l3);
  printf("Long \n");
  for (size_t i = 0; i < l3.count; ++i) printf("%lu : %zu\n", l3.items.longs[i], i);

  return 0;
}
