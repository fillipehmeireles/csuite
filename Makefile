
CC = clang
CFLAGS = -Wall -Wextra -Wno-strict-prototypes -Wno-unused-parameter -pedantic -std=c11 
INCLUDES = -I include/
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
TESTDIR = tests
TESTSRC = $(wildcard $(TESTDIR)/*.c)
TESTBIN = bin_tests

test-equal:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) $(TESTDIR)/equal_test.c -o $(TESTBIN)/equal
