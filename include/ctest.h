#ifndef CTEST_H
#define CTEST_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <unistd.h>
#include <time.h>
#include "../include/assert.h"
#include "../include/report.h"

#define MAX_TESTS 20

typedef struct CTest CTest;
struct CTest{
    void(*func)(struct CTest *test);
    char *name;
    unsigned int assertsTotal;
    unsigned int assertsPassed;
    unsigned int assertsFailed;
    bool passed;
};

struct CTestGroup{;
    char *name;
    int testCount;
    struct CTest test[20];
};

struct CTestGroup initGroup(void);
int addTest(struct CTestGroup *group, char *name, void (*)(struct CTest *test));
int runTests(struct CTestGroup *group);
int cAssert(struct CTest *test, struct Assertion *assertion);

#endif
