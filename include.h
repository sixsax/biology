#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct base {
  void (*destructor) (void *self);
} Base;

#define new(s, c) ( { s ptr = c(); ptr; } )

#define delete(s) ( { \
                  ((Base *)(s->private))->destructor(s); \
                  free(s); \
                  } )

#endif
