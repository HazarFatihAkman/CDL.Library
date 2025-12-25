#include "../include/numbers.h"
#include "../include/strings.h"

#include <stdio.h>

int main() {
  numbers l = {0};

  int val = 10;
  n_push(val, &l);
  n_push(20, &l);

  for (size_t i = 0; i < l.count; ++i) printf("%d : %zu\n", l.items.ints[i], i); 

  numbers l2 = {0};
  short int sval = 111;
  n_push(sval, &l2);
  n_push((short int)112, &l2);
  n_push((short int)113, &l2);
  n_push((short int)114, &l2);
  n_push((short int)115, &l2);
  n_push((short int)116, &l2);
  n_push((short int)117, &l2);
  n_push((short int)118, &l2);
  n_push((short int)119, &l2);
  n_push((short int)120, &l2);
  n_push((short int)121, &l2);
  n_push((short int)122, &l2);
  n_push((short int)123, &l2);
  n_push((short int)124, &l2);
  n_push((short int)125, &l2);
  printf("Shorts %zu\n", l2.count);
  for (size_t i = 0; i < l2.count; ++i) printf("%d : %zu\n", l2.items.shorts[i], i);
  n_remove(2, &l2);
  printf("Shorts %zu\n", l2.count);
  for (size_t i = 0; i < l2.count; ++i) printf("%d : %zu\n", l2.items.shorts[i], i);
  numbers l3 = {0};
  long lval = 132;
  n_push(lval, &l3);
  n_push((long) 133, &l3);
  n_push((long) 134, &l3);
  n_push((long) 135, &l3);
  n_push((long) 136, &l3);
  printf("Long \n");
  for (size_t i = 0; i < l3.count; ++i) printf("%lu : %zu\n", l3.items.longs[i], i);

  n_remove(2, &l3);
  printf("Long \n");
  for (size_t i = 0; i < l3.count; ++i) printf("%lu : %zu\n", l3.items.longs[i], i);

  strings ls = {0};
  const char *strval = "string";
  str_push(strval, &ls);
  str_push("string 2", &ls);
  str_push("string 3", &ls);
  str_push("string 4", &ls);
  printf("String \n");
  for (size_t i = 0; i < ls.count; ++i) printf("%s : %zu\n", ls.items[i], i);
  str_remove(2, &ls); 
  printf("String \n");
  for (size_t i = 0; i < ls.count; ++i) printf("%s : %zu\n", ls.items[i], i);
  return 0;
}
