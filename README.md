# CSuite - Easiest way to write tests in C 

 ⚠️  Still on development

 Example:
````c
#include "csuite.h"
#include <stdbool.h>
#include <stdio.h>

void contains_test() {
  int arr[] = {1,2,3,4,5};
  int i = 1;

  Contains(arr,i,5);
}

void not_null_test() {
  int i = 10;
  int *iptr = &i;

  NotNull(iptr);
}

void is_null_test() {
  int *iptr = NULL; 

  IsNull(iptr);
}

void equal_test() {
  int a = 1;
  int b = 1;

  Equal(a,b);
}

void char_equal_test()
{
  char a = 'a';
  char b = 'b';

  Equal(a,b);
}

int main(int argc, char *argv[])
{
  CSuite* csuite = setup_csuite();
  add_testcase(csuite,"equal_test",&contains_test); 
  add_testcase(csuite,"int_not_null_test",&not_null_test); 
  add_testcase(csuite,"int_is_null_test",&is_null_test); 
  add_testcase(csuite,"int_equal_test",&equal_test); 
  add_testcase(csuite,"char_equal_test",&char_equal_test); 

  // Run all test cases
  run(csuite);

  // Run individual test
  run_only(csuite, "int_equal_test");

  return 0;
}
````

Running example:
```
$ make example
$ ./bin_example/example
```
