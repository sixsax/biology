#ifndef LIST_H
#define LIST_H
#include "../include.h"

typedef struct _item {
  void *data;
} item;
typedef item *Item;

typedef struct private_list _private_list;
typedef _private_list *PrivateList;

typedef struct public_list *List;
typedef struct public_list {
  PrivateList private;
  void  (* add) (List self, Item item);
  void  (* empty) (List self);

  Item  (* getIndex) (List self, int index);
  int   (* getLen) (List self);
} _public_list;

List list();

#endif
