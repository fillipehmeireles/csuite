
CC = clang
CFLAGS = -Wall -Wextra -Wno-strict-prototypes -Wno-unused-parameter -pedantic -std=c11 
INCLUDES = -I include/
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
TESTDIR = tests
TESTSRC = $(wildcard $(TESTDIR)/*.c)

test-equal:
	$(CC) $(CFLAGS)$(INCLUDES) $(SRC) tests/equal_test.c -o ./tests/equal
