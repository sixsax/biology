#include "list.h"

typedef struct p_list{
  Base b;
  unsigned int len;
  Item *items;
} private_list;

Item getIndex(void *self, int index){
  PrivateList l = ((List)self)->private;

  //If index is out of bounds
  if ( (index < 1) || (index > l->len) )
    return NULL;

  return l->items[index-1];
}

int getLen(void* self){
  PrivateList l = ((List)self)->private;

  return l->len;
}

void list_add (void *self, Item item){
  PrivateList l = ((List)self)->private;

  l->len++;
  l->items = (Item *) realloc (l->items, l->len);

  l->items[l->len - 1] = item;
}

void list_empty(void *self){
  PrivateList l = ((List)self)->private;

  for (int i = l->len - 1; i >= 0; i--){
    void *data = (l->items[i])->data;
    free (data);
    free (l->items[l->len]);
  }

  free(l->items);
  l->items = NULL;
  l->len = 0;
}

void list_destructor(void *self){
  printf("Destructor List [%p]!\n", (List) self );
  private_list * pl = ((List)self)->private;

  free(pl);
  ((List)self)->private = NULL;
}

List list(){
  PrivateList pl = (PrivateList) malloc(sizeof(private_list));
  pl->items = NULL;
  pl->len = 0;

  List l = (List) malloc (sizeof(PublicList));
  l->private = pl;
  l->private->b.destructor = &list_destructor;
  l->add      = &list_add;
  l->empty    = &list_empty;
  l->getIndex = &getIndex;
  l->getLen   = &getLen;
  return l;
}
