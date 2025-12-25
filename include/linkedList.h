#ifndef CDL_LIBRARY_LINKEDLIST_H
#define CDL_LIBRARY_LINKEDLIST_H

typedef struct signly_linked_node {
  void *val;
  struct signly_linked_node *next;
} sl_node_t;

typedef struct signly_linked_list {
  sl_node_t *head;
  sl_node_t *last;
} sl_list_t;

// push
void _sl_push(void *x, sl_list_t *l); 
#define sl_push(x, l) _sl_push(x, l)

// pop
void _sl_pop(sl_list_t *l);
#define sl_pop(l) _sl_pop(l)

// remove
void _sl_remove(void *x, sl_list_t *l);
#define sl_remove(x, l) _sl_remove(x, l);

#endif // CDL_LIBRARY_LINKEDLIST_H
