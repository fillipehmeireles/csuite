#include "csuite.h"
#include <stdbool.h>
#include <stdio.h>


void INT_contains_test() {

  int arr[] = {1,2,3,4,5};
  int i = 1;
  Contains(arr,i,5);
}
int main(int argc, char *argv[])
{
  CSuite* csuite = setup_csuite();
  add_testcase(csuite,"int_Equal_test",&INT_contains_test); 

  // Run all test cases
  run(csuite);


  return 0;
}
