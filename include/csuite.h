#include <stdbool.h>

#ifndef csuite__h
#define csuite_h


typedef void(TestCaseFn)(void);
typedef struct {
  char* name;
  TestCaseFn* test_case; 
} TestCase;
TestCase* create_testcase(char* name, TestCaseFn* fn);

typedef struct {
  TestCase **test_cases;
  int testcase_c;
}CSuite ;

CSuite* setup_csuite();
void run(CSuite*);
void run_only(CSuite*, char* testcase_name);

void add_testcase(CSuite*, char* testcase_name, TestCaseFn* testcase_fn);

#define success_print() printf("--- PASS\t\n" )
#define fail_print() printf("--- FAIL\t\n")

#define CONCAT(a, b) a##b
#define UNIQUE_NAME(base) CONCAT(base, __COUNTER__)

/* Assertions */
#define Equal(a,b) ((a == b) ?  success_print() : fail_print())
#define NotEqual(a,b) ((a != b) ?  success_print() : fail_print())
#define Greater(a,b) ((a > b) ?  success_print() : fail_print())
#define GreaterOrEqual(a,b) ((a >= b) ?  success_print() : fail_print())
#define Less(a,b) ((a < b) ?  success_print() : fail_print())
#define LessOrEqual(a,b) ((a <= b) ?  success_print() : fail_print())
#define NotNull(a) ((a != NULL) ? success_print() : fail_print())
#define IsNull(a) ((a == NULL) ?  success_print() : fail_print())
#define True(a) (a ? success_print() : fail_print())
#define False(a) (!a ? success_print() : fail_print())
#define Contains(a,b,c) for(int UNIQUE_NAME(i)= 0; UNIQUE_NAME(i) < c; UNIQUE_NAME(i)++) {if(a[UNIQUE_NAME(i)] == b) {success_print();}}

#endif
