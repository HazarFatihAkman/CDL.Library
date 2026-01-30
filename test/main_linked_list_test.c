#include "../include/linkedList.h"

#include <stdio.h>

int main() {
  sl_list_t linkedList = {0};

  sl_push((void*)1, &linkedList);
  sl_push((void*)2, &linkedList);
  sl_push((void*)3, &linkedList);
  sl_push((void*)4, &linkedList);

  sl_node_t *current = linkedList.head;
  while (current->next) printf("%d\n", (int)current->val);

  sl_pop(&linkedList);

  sl_node_t *current2 = linkedList.head;
  while (current2->next) {
    printf("%d\n", (int)current2->val);
  }

  return 0;
}
