#include "csuite.h"

#include <stdbool.h>
#include <stdio.h>


bool INT_equal_test() {
  int a = 1;
  int b = 1;
  TYPE t = INT;
  if(!equal((void *) &a,(void *) &b,t))
  {
    // TODO: LOG Expected x Current
    printf("fail\n");
    return false;
  }

  printf("pass\n");
  return true;
}

bool CHAR_equal_test()
{
  char a = 'a';
  char b = 'b';
  TYPE t = CHAR;

  if(!equal((void *) &a,(void *) &b,t))
  {
    // TODO: LOG Expected x Current
    printf("fail");
    return false;
  }

  printf("pass\n");
  return true;

}
int main()
{
  INT_equal_test();
  CHAR_equal_test();
}
