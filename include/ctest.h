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


typedef struct {
    const char *fileName;
    unsigned line_number;
    const char* functionName;
} sourceLocation;

#define CUR_SOURCE_LOCATION (sourceLocation){__FILE__, __LINE__, __func__}

bool doAssert(bool expr, const sourceLocation *loc, const char *expression);
bool testAssert(bool expr, const sourceLocation *loc, const char *expression, TestResult *result);

#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr, Result) \
        testAssert((Expr), &CUR_SOURCE_LOCATION, #Expr, Result)
#else
    #define DEBUG_ASSERT(Expr)
#endif

//ASSERT_EQUALS OF TYPES
void ASSERT_EQUALS_INT(int expected, int actual, const sourceLocation *loc);

#define assertEqualsInt(exp, act) \
    ASSERT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


void ASSERT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc);

#define assertEqualsShort(exp, act) \
    ASSERT_EQUALS_SHORT((exp), (act), &CUR_SOURCE_LOCATION);

void ASSERT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc);

#define assertEqualsLong(exp, act) \
    ASSERT_EQUALS_LONG((exp), (act), &CUR_SOURCE_LOCATION);

void ASSERT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc);

#define assertEqualsFloat(exp, act) \
    ASSERT_EQUALS_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);

void ASSERT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc);

#define assertEqualsDouble(exp, act) \
    ASSERT_EQUALS_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);

void ASSERT_EQUALS_CHAR(const char expected, const char actual, const sourceLocation *loc);

#define assertEqualsChar(exp, act) \
    ASSERT_EQUALS_CHAR((exp), (act), &CUR_SOURCE_LOCATION);


void ASSERT_EQUALS_STR(const char *expected, const char *actual, const sourceLocation *loc);

#define assertEqualsStr(exp, act) \
    ASSERT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION);


void ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc);

#define assertEqualsArrayInt(exp, act) \
    ASSERT_EQUALS_ARRAY_INT((exp), (act), &CUR_SOURCE_LOCATION);

//ASSERT_NOT_EQUALS OF TYPES
void ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc);

#define assertNotEqualsInt(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


//ASSERT BOOLEANS
void ASSERT_TRUE(bool actual, const sourceLocation *loc);

#define assertTrue(act) \
    ASSERT_TRUE((act), &CUR_SOURCE_LOCATION);

void ASSERT_FALSE(bool actual, const sourceLocation *loc);

#define assertFalse(act) \
    ASSERT_FALSE((act), &CUR_SOURCE_LOCATION);

//ASSERT NULL / NOT NULL
void ASSERT_NOT_NULL(void *expr, const sourceLocation *loc);

#define assertNotNull(Expr) \
    ASSERT_NOT_NULL((Expr), &CUR_SOURCE_LOCATION);



#endif
