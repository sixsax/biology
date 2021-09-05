#include "nucleobase.h"

typedef struct p_nucleobase{
  Base b;
  uint8_t type;
} private_nucleobase;

void nucleobase_setType(void *self, uint8_t type){
  ((PrivateNucleobase)self)->type = type;
  unsigned int ptype = ((PrivateNucleobase)self)->type;

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
  printf("Destructor Nucleobase [%hu]!\n", ((PrivateNucleobase)self)->type);
  private_nucleobase * pr = ((Nucleobase) self)->private;

  free(pr);
  ((Nucleobase) self)->private = NULL;
}

Nucleobase nucleobase(){

  PrivateNucleobase pr = (PrivateNucleobase) malloc(sizeof(private_nucleobase));
  pr->type = 0;

  Nucleobase p = (Nucleobase) malloc(sizeof(PublicNucleobase));
  p->private = pr;

  p->setType = &nucleobase_setType;
  p->private->b.destructor = &nucleobase_destructor;

  return p;
}
