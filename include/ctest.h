#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <string.h>
#include "assert.h"
#define MAX_TESTS 20
typedef struct{
    unsigned int totalAsserts;
    unsigned int assertsPassed;
    unsigned int assertsFailed;
    bool testPassed;
}TestResult;

typedef struct{
    void(*func)(TestResult *res);
    char name[20];
    bool passed;
    TestResult res;
}CTest;


typedef struct{;
    char name[20];
    CTest test[MAX_TESTS];
    bool testOccupied[MAX_TESTS];
}TestGroup;


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
bool testAssert(bool expr, const sourceLocation *loc, const char *expression, TestResult *result);

void ASSERT_EQUALS_INT(int expected, int actual, const sourceLocation *loc);
void ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc);
void ASSERT_EQUALS_STR(const char *expected, const char *actual, const sourceLocation *loc);


#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr, Result) \
        testAssert((Expr), &CUR_SOURCE_LOCATION, #Expr, Result)
#else
    #define DEBUG_ASSERT(Expr)
#endif

#define assertEqualsInt(exp, act) \
    ASSERT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION)

#define assertNotEqualsInt(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION)

#define assertEqualsStr(exp, act) \
    ASSERT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION)



#endif
