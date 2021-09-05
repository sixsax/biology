#ifndef NUCLEOBASE_H
#define NUCLEOBASE_H
#include "include.h"

#define ADENINE   0x01
#define CYTOSINE  0x02
#define GUANINE   0x04
#define THYMINE   0x08
#define URACIL    0x10

typedef struct p_nucleobase private_nucleobase;
typedef private_nucleobase *PrivateNucleobase;

typedef struct public_nucleobase {
  PrivateNucleobase private;
  void (* setType) (void *, uint8_t type);
} PublicNucleobase;
typedef PublicNucleobase *Nucleobase;

Nucleobase nucleobase();

#endif
