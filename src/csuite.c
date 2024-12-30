#include "csuite.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

CSuite* setup_csuite() {
  CSuite* csuite = (CSuite*)malloc(sizeof(CSuite));
  if(!csuite){
    perror("[!] Error on creating CSuite: ");
    exit(EXIT_FAILURE);
  }
  csuite->testcase_c = 0;
  return csuite;
}

TestCase* create_testcase(char* name, TestCaseFn* fn)
{
  char* nameVal = name;
  while(*nameVal++)
  {

    if(isspace(*nameVal))
    {
      fprintf(stderr, "[!] Please provide a valid testcase name (no whitespaces)\n");
      exit(EXIT_FAILURE);
    }
  }
  if (!fn) {
    perror("[!] Error on creating TestCase: fn is null");
    exit(EXIT_FAILURE);
  }
  if (!name) {
    perror("[!] Error on creating TestCase: name is null");
    exit(EXIT_FAILURE);
  }

  TestCase* testcase = (TestCase *)malloc(sizeof(TestCase));
  testcase->name = name;
  testcase->test_case = fn;

  return testcase;
}

void add_testcase(CSuite* csuite, char* testcase_name, TestCaseFn* testcase_fn)
{
  csuite->test_cases = (TestCase **)realloc(csuite->test_cases, (csuite->testcase_c + 1) * sizeof(TestCase *));
  if(!csuite->test_cases){
    fprintf(stderr, "[!] Error on adding testcase [%s] to the CSuite", testcase_name);
    exit(EXIT_FAILURE);
  }

  TestCase *testcase = create_testcase(testcase_name, testcase_fn);
  csuite->test_cases[csuite->testcase_c] = testcase;
  csuite->testcase_c++;
}


void run(CSuite *csuite) {
  printf("[i] Running all tests... \n");
  for(int i = 0; i < csuite->testcase_c; i++)
  {
    printf("[testcase]: %s \t", csuite->test_cases[i]->name);
    csuite->test_cases[i]->test_case();
  }

  printf("Finished\n");
}

void run_only(CSuite *csuite, char* testcase_name)
{

  printf("[i] RunOnly mode... \n" );
  TestCaseFn* this_testcase = NULL;
  for(int i = 0; i < csuite->testcase_c; i++)
  {
    if(strcmp(csuite->test_cases[i]->name, testcase_name) == 0)
    {

      printf("[testcase]: %s \t", csuite->test_cases[i]->name);
      this_testcase = csuite->test_cases[i]->test_case;
      break;
    }
  }
  if(!this_testcase)
  {
    fprintf(stderr, "[!] CSuite has no testcase %s ", testcase_name);
    fail_print();
    exit(EXIT_FAILURE);
  }
  this_testcase();
  printf("Finished\n");
}

// TODO: Bool, Float and Double Equal function
bool Int_equal(int a, int b)
{
  if(a != b)
    return false;
  return true;
}

bool Char_equal(char a, char b){
  if(a != b)
    return false;
  return true;
}



