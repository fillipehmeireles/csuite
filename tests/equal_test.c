#include "csuite.h"

#include <stdbool.h>
#include <stdio.h>


void INT_equal_test() {
  int a = 1;
  int b = 1;
  Type t = Int;

  equal((void *) &a,(void *) &b,t);
}

void CHAR_equal_test()
{
  char a = 'a';
  char b = 'b';
  Type t = Char;
  equal((void *) &a,(void *) &b,t);
}

int main()
{

  CSuite* csuite = setup_csuite();
  add_testcase(csuite,"int_equal_test",&INT_equal_test); 
  add_testcase(csuite,"char_equal_test",&CHAR_equal_test); 

  // Run all test cases
  run(csuite);


  // Run individual test
  run_only(csuite, "int_equal_test");

}
