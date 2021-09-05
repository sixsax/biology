#include "ribosome.h"

typedef struct p_ribosome{
  Base b;
  unsigned int id;
} private_ribosome;

void ribosome_setId(void *self, unsigned int id){
  ((Ribosome)self)->private->id = id;
}

void ribosome_destructor(void *self){
  printf("Destructor Ribosome [%d]!\n", ((Ribosome)self)->private->id);
  private_ribosome * pr = ((Ribosome) self)->private;

  free(pr);
  ((Ribosome) self)->private = NULL;
}

Ribosome ribosome(){

  PrivateRibosome pr = (PrivateRibosome) malloc(sizeof(private_ribosome));
  pr->id = 0;

  Ribosome p = (Ribosome) malloc(sizeof(PublicRibosome));
  p->private = pr;

  p->setId = &ribosome_setId;
  p->private->b.destructor = &ribosome_destructor;

  printf("Ribosome constructor\n");
  return p;
}
