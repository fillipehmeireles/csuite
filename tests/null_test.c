#include "csuite.h"
#include <stdbool.h>
#include <stdio.h>

void INT_not_null_test() {
  int i = 10;
  int *iptr = &i;
  
  notNull(iptr);
}

void INT_is_null_test() {
  int *iptr = NULL;
 
  isNull(iptr);
}



int main(int argc, char *argv[])
{

  CSuite* csuite = setup_csuite();
  add_testcase(csuite,"int_not_null_test",&INT_not_null_test); 
  add_testcase(csuite,"int_is_null_test",&INT_is_null_test); 

  // Run all test cases
  run(csuite);

  return 0;
}
