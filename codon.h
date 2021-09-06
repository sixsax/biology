#ifndef CODON_H
#define CODON_H
#include "include.h"
#include "nucleotide.h"

typedef struct private_codon _private_codon;
typedef _private_codon *PrivateCodon;

typedef struct public_codon *Codon;
typedef struct public_codon {
  PrivateCodon private;
  void (* setId) (Codon self, unsigned int id);
  void (* setNucleotide) (Codon self, Nucleotide ntd, unsigned int position);
} _public_codon;

Codon codon();

#endif
