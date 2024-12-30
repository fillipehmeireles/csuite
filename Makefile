
CC = clang
CFLAGS = -Wall -Wextra -Wno-strict-prototypes -Wno-unused-parameter -pedantic -std=c11 
INCLUDES = -I include/
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
TESTDIR = tests
TESTSRC = $(wildcard $(TESTDIR)/*.c)
TESTBIN = bin_tests
EXAMPLEDIR = examples
EXAMPLESRC = $(wildcard $(EXAMPLEDIR)/*.c)
EXAMPLEBIN = bin_example

test-equal:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) $(TESTDIR)/equal_test.c -o $(TESTBIN)/equal

test-not-null:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) $(TESTDIR)/null_test.c -o $(TESTBIN)/null_test

test-contains:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) $(TESTDIR)/contains_test.c -o $(TESTBIN)/contains_test

example:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) $(EXAMPLEDIR)/example.c -o $(EXAMPLEBIN)/example
