#include "nucleotide.h"

typedef struct private_nucleotide{
  Base b;
  unsigned int id;
  Nucleobase nb;
  /* Phosphate, Sugar and so on ... */
} _private_nucleotide;

void nucleotide_setId(Nucleotide self, unsigned int id){
  self->private->id = id;
}

void nucleotide_setNucleobase(Nucleotide self, Nucleobase nb){
  self->private->nb = nb;
}

void nucleotide_destructor(void *self){
  printf("Destructor Nucleotide [%d]!\n", ((Nucleotide)self)->private->id);

  _private_nucleotide * pr = ((Nucleotide) self)->private;
  Nucleobase nb = ((Nucleotide) self)->private->nb;

  delete(nb);
  free(pr);

  ((Nucleotide) self)->private->nb = NULL;
  ((Nucleotide) self)->private = NULL;
}

Nucleotide nucleotide(){

  PrivateNucleotide pn = (PrivateNucleotide) malloc(sizeof(_private_nucleotide));
  pn->id = 0;
  pn->nb = NULL;

  Nucleotide p = (Nucleotide) malloc(sizeof(_public_nucleotide));
  p->private = pn;

  p->setId = &nucleotide_setId;
  p->setNucleobase = &nucleotide_setNucleobase;
  p->private->b.destructor = &nucleotide_destructor;

  printf("Nucleotide constructor\n");
  return p;
}
