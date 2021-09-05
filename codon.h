#ifndef CODON_H
#define CODON_H
#include "include.h"
#include "nucleotide.h"

typedef struct p_codon private_codon;
typedef private_codon *PrivateCodon;

typedef struct public_codon {
  PrivateCodon private;
  void (* setId) (void *, unsigned int id);
  void (* setNucleotide) (void *self, Nucleotide ntd, unsigned int position);
} PublicCodon;

typedef PublicCodon *Codon;


Codon codon();

#endif
