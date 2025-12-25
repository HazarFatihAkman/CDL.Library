#include "../include/linkedList.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

static sl_node_t *_create_node(void *x) {
  sl_node_t *temp = malloc(sizeof(sl_node_t));
  if (temp == NULL) {
    perror("Error");
    return NULL;
  }

  temp->val = x;
  temp->next = NULL;

  return temp;
}

void _sl_push(void *x, sl_list_t *l) {
  sl_node_t *temp = _create_node(x);
  if (l->head == NULL || l->head->val == NULL) {
    l->head = temp;
    l->last = temp;
  }
  else {
    sl_node_t *current = l->head;

    while (current->next) {
      current = current->next;
    }

    current->val = temp;
    l->last = temp;
  }
}

void _sl_pop(sl_list_t *l) {
  if (l->head == NULL || l->head->val == NULL) {
    return;
  }

  if (l->head->next == NULL) {
    l->head->val = NULL;
  }
  else {
    sl_node_t *current = l->head;

    while (current->next) {
      if (current->next == l->last) {
        free(current->next);

        l->last = current;
      }
      else {
        current = current->next;
      }
    }

  }
}
