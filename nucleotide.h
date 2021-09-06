#ifndef NUCLEOTIDE_H
#define NUCLEOTIDE_H
#include "include.h"
#include "nucleobase.h"

typedef struct private_nucleotide _private_nucleotide;
typedef _private_nucleotide *PrivateNucleotide;

typedef struct public_nucleotide *Nucleotide;
typedef struct public_nucleotide {
  PrivateNucleotide private;
  void (* setId)(Nucleotide self, unsigned int id);
  void (* setNucleobase) (Nucleotide self, Nucleobase nb);
} _public_nucleotide;

Nucleotide nucleotide();

#endif
