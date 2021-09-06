#ifndef RIBOSOME_H
#define RIBOSOME_H
#include "include.h"

typedef struct private_ribosome _private_ribosome;
typedef _private_ribosome *PrivateRibosome;

typedef struct public_ribosome *Ribosome;
typedef struct public_ribosome {
  PrivateRibosome private;
  void (* setId) (Ribosome self, unsigned int id);
} _public_ribosome;

Ribosome ribosome();
#endif
