#ifndef NUCLEOBASE_H
#define NUCLEOBASE_H
#include "include.h"

#define ADENINE   0x01
#define CYTOSINE  0x02
#define GUANINE   0x04
#define THYMINE   0x08
#define URACIL    0x10

typedef struct private_nucleobase _private_nucleobase;
typedef _private_nucleobase *PrivateNucleobase;

typedef struct public_nucleobase *Nucleobase;
typedef struct public_nucleobase {
  PrivateNucleobase private;
  void (* setType) (Nucleobase self, uint8_t type);
} _public_nucleobase;

Nucleobase nucleobase();

#endif
