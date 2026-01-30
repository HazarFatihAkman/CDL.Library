#include "../include/listInterface.h"
#include <stdio.h>

int main(int argv, char *args[]) {
  li_t l = {0};
  char *t = "Test";
  push_v(t, &l);
  push_v((void*)"Test2", &l);

  printf("Pushed\n");
  for (int i = 0; i < l.count; i++) printf("%s\n", (char*)l.items[i]); 

  remove_at(0, &l);
  printf("remove_at\n");
  for (int i = 0; i < l.count; i++) printf("%s\n", (char*)l.items[i]); 

  pop_v(&l);
  printf("pop\n");
  for (int i = 0; i < l.count; i++) printf("%s\n", (char*)l.items[i]); 

  li_t numbers = {0};
  push_v((void*)1, &numbers);
 
  printf("Pushed\n");
  for (int i = 0; i < numbers.count; i++) {
    int x = (int)numbers.items[i];
    printf("%d | %zu\n", x, sizeof(x)); 
  }
  return 0;
}
