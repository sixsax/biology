#include "codon.h"

typedef struct private_codon{
  Base b;
  unsigned int id;
  Nucleotide ntd[3];
}_private_codon;

void codon_setId(Codon self, unsigned int id){
  self->private->id = id;
}

void codon_setNucleotide(Codon self, Nucleotide ntd, unsigned int position){
  Codon c = self;
  if( position<0 || position > 2 ){
    fprintf(stderr, "Invalid codon position %d\n", position);
    return;
  }

  c->private->ntd[position] = ntd;
}

void codon_destructor(void *self){
  printf("Destructor Codon [%d]!\n", ((Codon) self)->private->id);
  _private_codon * pr = ((Codon) self)->private;

  for( int i = 0;  i < 3; i++){
    if (pr->ntd[i] != NULL){
      Nucleotide ntd = pr->ntd[i];
      delete(ntd);
    }
  }

  free(pr);
  ((Codon) self)->private = NULL;
}

Codon codon(){
  PrivateCodon pr = (PrivateCodon) malloc(sizeof(_private_codon));
  pr->id = 0;

  Codon c = (Codon) malloc(sizeof(_public_codon));
  c->private = pr;

  c->setId = &codon_setId;
  c->setNucleotide = &codon_setNucleotide;
  c->private->b.destructor = &codon_destructor;

  for( int i = 0;  i < 3; i++)
    pr->ntd[i] = NULL;

  return c;
}
