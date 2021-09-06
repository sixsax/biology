#include "ribosome.h"

typedef struct private_ribosome{
  Base b;
  unsigned int id;
} _private_ribosome;

void ribosome_setId(Ribosome self, unsigned int id){
  self->private->id = id;
}

void ribosome_destructor(void *self){
  printf("Destructor Ribosome [%d]!\n", ((Ribosome)self)->private->id);
  _private_ribosome * pr = ((Ribosome) self)->private;

  free(pr);
  ((Ribosome) self)->private = NULL;
}

Ribosome ribosome(){

  PrivateRibosome pr = (PrivateRibosome) malloc(sizeof(_private_ribosome));
  pr->id = 0;

  Ribosome p = (Ribosome) malloc(sizeof(_public_ribosome));
  p->private = pr;

  p->setId = &ribosome_setId;
  p->private->b.destructor = &ribosome_destructor;

  printf("Ribosome constructor\n");
  return p;
}
