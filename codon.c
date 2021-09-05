#include "codon.h"

typedef struct p_codon{
  Base b;
  unsigned int id;
  Nucleotide ntd[3];
}private_codon;

void codon_setId(void *self, unsigned int id){
  ((Codon)self)->private->id = id;
}

void codon_setNucleotide(void *self, Nucleotide ntd, unsigned int position){
  Codon c = (Codon) self;
  if( position<0 || position > 2 ){
    fprintf(stderr, "Invalid codon position %d\n", position);
    return;
  }

  c->private->ntd[position] = ntd;
}

void codon_destructor(void *self){
  printf("Destructor Codon [%d]!\n", ((Codon)self)->private->id);
  private_codon * pr = ((Codon) self)->private;

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
  PrivateCodon pr = (PrivateCodon) malloc(sizeof(private_codon));
  pr->id = 0;

  Codon c = (Codon) malloc(sizeof(PublicCodon));
  c->private = pr;

  c->setId = &codon_setId;
  c->setNucleotide = &codon_setNucleotide;
  c->private->b.destructor = &codon_destructor;

  for( int i = 0;  i < 3; i++)
    pr->ntd[i] = NULL;

  return c;
}
