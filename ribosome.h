#ifndef RIBOSOME_H
#define RIBOSOME_H
#include "include.h"

typedef struct p_ribosome private_ribosome;
typedef private_ribosome *PrivateRibosome;

typedef struct public_ribosome {  
  PrivateRibosome private;
  void (* setId) (void *, unsigned int id);
} PublicRibosome;

typedef PublicRibosome *Ribosome;

Ribosome ribosome();
#endif
