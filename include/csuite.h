#include <stdbool.h>

#ifndef csuite__h
#define csuite_h

typedef enum {
  Int,
  Bool,
  Char,
  Float,
  Double
} Type;

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
/* Assertions */
void equal(void* a, void* b, Type t);

#endif
