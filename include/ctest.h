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

void displayAssertResults(void);

typedef struct CTest{
    void(*func)(struct CTest *test);
    char name[20];
    unsigned int assertsTotal;
    unsigned int assertsPassed;
    unsigned int assertsFailed;
    bool passed;
}CTest;

typedef struct{;
    char name[20];
    CTest test[MAX_TESTS];
    bool testOccupied[MAX_TESTS];
}CTestGroup;

int initGroup(CTestGroup *group);
int addTest(CTestGroup *group, const char *name, CTest *test);
int runTests(CTestGroup *group);

//bool doAssert(bool expr, const AssertStruct *assertion, const char *expression);
//bool testAssert(bool expr, const AssertStruct *assertion, const char *expression, AssertStruct *result);

#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr, Result) \
//        testAssert((Expr), &CUR_SOURCE_LOCATION, #Expr, Result)
#else
    #define DEBUG_ASSERT(Expr)
#endif

//ASSERT_EQUALS OF TYPES
bool ASSERT_EQUALS_INT(int expected, int actual);
bool ASSERT_EQUALS_SHORT(short expected, short actual);
bool ASSERT_EQUALS_LONG(long expected, long actual);
bool ASSERT_EQUALS_FLOAT(float expected, float actual);
bool ASSERT_EQUALS_DELTA(float expected, float actual, float delta);
bool ASSERT_EQUALS_DOUBLE(double expected, double actual);
bool ASSERT_EQUALS_CHAR(char expected, char actual);
bool ASSERT_EQUALS_STR(char *expected, char *actual);
bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[]);
bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[]);
bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[]);
bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[]);
bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[]);
//ASSERT_NOT_EQUALS OF TYPES
bool ASSERT_NOT_EQUALS_INT(int expected, int actual);
bool ASSERT_NOT_EQUALS_SHORT(short expected, short actual);
bool ASSERT_NOT_EQUALS_LONG(long expected, long actual);
bool ASSERT_NOT_EQUALS_FLOAT(float expected, float actual);
bool ASSERT_NOT_EQUALS_DOUBLE(double expected, double actual);
bool ASSERT_NOT_EQUALS_CHAR(char expected, char actual);
bool ASSERT_NOT_EQUALS_STR(char *expected, char *actual);
//ASSERT NOT EQUALS FOR ARRAY TYPES
bool ASSERT_NOT_EQUALS_ARRAY_INT(int expected[], int actual[]);
bool ASSERT_NOT_EQUALS_ARRAY_SHORT(short expected[], short actual[]);
bool ASSERT_NOT_EQUALS_ARRAY_LONG(long expected[], long actual[]);
bool ASSERT_NOT_EQUALS_ARRAY_FLOAT(float expected[], float actual[]);
bool ASSERT_NOT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[]);
//ASSERT BOOLEANS
bool ASSERT_TRUE(bool actual);
bool ASSERT_FALSE(bool actual);
//ASSERT NULL / NOT NULL
bool ASSERT_NOT_NULL(void *expr);
bool ASSERT_NULL(void *expr);

#endif
