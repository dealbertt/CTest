#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <string.h>
#include "assert.h"
#define MAX_TESTS 20
typedef struct{
    void(*func)(void);
    char name[20];
    bool passed;
}CTest;

typedef struct{;
    char name[20];
    CTest test[MAX_TESTS];
    bool testOccupied[MAX_TESTS];
}TestGroup;

typedef struct{
    unsigned int totalAsserts;
    unsigned int assertsPassed;
    unsigned int assertsFailed;
}TestResult;

int initGroup(TestGroup *group);
int addTest(TestGroup *group, const char *name, CTest *test);
int runTests(TestGroup *group);


bool assertEqualTest(int expected, int (*funcPointer)(int count, ...), int count, ...);
bool assertEqualInt(int expected, int (*funcPointer)(int, int), int a, int b);
bool assertEqualDouble(double expected, int (*funcPointer)(double, double), double a, double b);



typedef struct {
    const char *fileName;
    unsigned line_number;
    const char* functionName;
} sourceLocation;

#define CUR_SOURCE_LOCATION (sourceLocation){__FILE__, __LINE__, __func__}

bool doAssert(bool expr, const sourceLocation *loc, const char *expression);


#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr) \
        doAssert((Expr), &CUR_SOURCE_LOCATION, #Expr)
#else
    #define DEBUG_ASSERT(Expr)
#endif



#endif
