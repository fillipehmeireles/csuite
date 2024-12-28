#include "csuite.h"
#include <stdbool.h>

void setup_csuite() {
  // TODO
}
bool INT_equal(int a, int b)
{
  if(a != b)
    return false;
  return true;
}
bool CHAR_equal(char a, char b){
  if(a != b)
    return false;

  return true;
}
bool equal(void* a, void* b, TYPE t)
{
  // TODO: check for seg fault
  // TODO dyn dispatch for calling type callback
  switch (t) {
    case INT:
      return INT_equal((*(int*)a), (*(int*)b));
      break;
    case CHAR:
      return CHAR_equal((*(char*)a), (*(char*)b));
    default:
      return false;
  }


}

