#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "include.h"
#include "nucleobase.h"

typedef struct p_nucleotide private_nucleotide;
typedef private_nucleotide *PrivateNucleotide;

typedef struct public_nucleotide {
  PrivateNucleotide private;
  void (* setId)(void *, unsigned int id);
  void (* setNucleobase) (void *, Nucleobase nb);
} PublicNucleotide;
typedef PublicNucleotide *Nucleotide;

Nucleotide nucleotide();

#endif
