#include "csuite.h"
#include <stdbool.h>
#include <stdio.h>


void INT_Equal_test() {
  int a = 1;
  int b = 1;

  Equal(a,b);
}

void CHAR_Equal_test()
{
  char a = 'a';
  char b = 'b';
  Equal(a,b);
}

int main()
{

  CSuite* csuite = setup_csuite();
  add_testcase(csuite,"int_Equal_test",&INT_Equal_test); 
  add_testcase(csuite,"char_Equal_test",&CHAR_Equal_test); 

  // Run all test cases
  run(csuite);


  // Run individual test
  run_only(csuite, "int_Equal_test");
  return 0;

}
