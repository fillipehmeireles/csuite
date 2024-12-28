#include <stdbool.h>

#ifndef csuite__h
#define csuite_h

typedef enum {
  INT,
  CHAR
} TYPE;


/* Assertions */
bool equal(void* a, void* b, TYPE t);

#endif
