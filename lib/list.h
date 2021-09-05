#ifndef LIST_H
#define LIST_H
#include "../include.h"

typedef struct _item {
  void *data;
} item;
typedef item *Item;

typedef struct p_list private_list;
typedef private_list *PrivateList;

typedef struct public_list {
  PrivateList private;
  void  (* add) (void *self, Item item);
  void  (* empty) (void *self);

  Item  (* getIndex) (void *self, int index);  
  int   (* getLen) (void *self);
} PublicList;

typedef PublicList *List;

List list();

#endif
