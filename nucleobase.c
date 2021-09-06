#include "nucleobase.h"

typedef struct private_nucleobase{
  Base b;
  uint8_t type;
} _private_nucleobase;

void nucleobase_setType(Nucleobase self, uint8_t type){
  self->private->type = type;
  unsigned int ptype = self->private->type;

  if(ptype & ADENINE)
    printf("ADENINE\n");
  else if(ptype & CYTOSINE)
    printf("CYTOSINE\n");
  else if(ptype & GUANINE)
    printf("GUANINE\n");
  else if (ptype & THYMINE)
    printf("THYMINE\n");
  else if (ptype & URACIL)
    printf("URACIL\n");
  else
    fprintf(stderr, "There is an anomaly at %hu\n", ptype );
}

void nucleobase_destructor(void *self){
  printf("Destructor Nucleobase [%hu]!\n", ((Nucleobase)self)->private->type);
  _private_nucleobase * pr = ((Nucleobase) self)->private;

  free(pr);
  ((Nucleobase) self)->private = NULL;
}

Nucleobase nucleobase(){

  PrivateNucleobase pr = (PrivateNucleobase) malloc(sizeof(_private_nucleobase));
  pr->type = 0;

  Nucleobase p = (Nucleobase) malloc(sizeof(_public_nucleobase));
  p->private = pr;

  p->setType = &nucleobase_setType;
  p->private->b.destructor = &nucleobase_destructor;

  return p;
}
