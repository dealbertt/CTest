#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define clear() printf("\033[H\033[J")
#define red() printf("\033[31m")
#define blue() printf("\033[34m")
#define green() printf("\033[32m")
#define yellow() printf("\033[33m")
#define white() printf("\033[0m")
#define MAX_TESTS 20
#define MAX_ASSERTS 50


#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr, Result) \
        testAssert((Expr), &CUR_SOURCE_LOCATION, #Expr, Result)
#else
    #define DEBUG_ASSERT(Expr)
#endif

#ifdef VERBOSE_ASSERT_RESULT
#define VERBOSE_ASSERT 1 
#else
#define VERBOSE_ASSERT 0
#endif

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


void displayAssertResults(void);
typedef struct {
    const char *fileName;
    unsigned line_number;
    const char* functionName;
} sourceLocation;

typedef struct{
    char description[20]; 
    sourceLocation loc;
    bool passed;
}AssertStruct;

int reportAssertPassed(char *message, long timeTaken);
int reportAssertFailed(char *message, const sourceLocation *loc, long timeTaken);
int reportAssertFooter(long timeTaken);

static inline int reportAssertInt(char *message, bool passed, int expected, int actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %d vs Actual: %d\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT) {
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}
int reportAssertArrayInt(char *message, bool passed, int expected[], int actual[],bool equals, long timeTaken, const sourceLocation *loc);
int reportAssertFloat(char *message, bool passed, float expected, float actual, long timeTaken, const sourceLocation *loc);
int reportAssertArrayFloat(char *message, bool passed, float expected[], float actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc);
int reportAssertArrayDouble(char *message, bool passed, double expected[], double actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc);
int reportAssertChar(char *message, bool passed, char expected, char actual, long timeTaken, const sourceLocation *loc);
int reportAssertString(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc);
int reportAssertBool(char *message, bool passed, bool expected, bool actual, long timeTaken, const sourceLocation *loc);
int reportAssertNULL(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc);


//THIS MIGHT NEED SOME REFINIMENT
int checkDifferenceArrayInt(int array1[], int array2[]);
int checkEqualArrayInt(int array1[], int array2[]);
int checkDifferenceArrayFloat(float array1[], float array2[]);
int checkEqualArrayFloat(float array1[], float array2[]);
int checkDifferenceArrayDouble(double array1[], double array2[]);
int checkEqualArrayDouble(double array1[], double array2[]);

#define CUR_SOURCE_LOCATION (sourceLocation){__FILE__, __LINE__, __func__}

bool doAssert(bool expr, const sourceLocation *loc, const char *expression);
bool testAssert(bool expr, const sourceLocation *loc, const char *expression, TestResult *result);
//ASSERT_EQUALS OF TYPES
extern TestResult unitResults;
static inline bool ASSERT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    clock_t now = clock();

    unitResults.totalAsserts++;

    bool result = (expected == actual);

    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }

    clock_t difference = clock() - now;
    long msec = difference * 1000 /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsInt", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsInt(exp, act) \
    ASSERT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc);

#define assertEqualsShort(exp, act) \
    ASSERT_EQUALS_SHORT((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc);

#define assertEqualsLong(exp, act) \
    ASSERT_EQUALS_LONG((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc);

#define assertEqualsFloat(exp, act) \
    ASSERT_EQUALS_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_DELTA(float expected, float actual, float delta, const sourceLocation *loc);

#define assertEqualsDelta(exp, act, delta) \
    ASSERT_EQUALS_DELTA((exp), (act), (delta), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc);

#define assertEqualsDouble(exp, act) \
    ASSERT_EQUALS_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_CHAR(char expected, char actual, const sourceLocation *loc);

#define assertEqualsChar(exp, act) \
    ASSERT_EQUALS_CHAR((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_EQUALS_STR(char *expected, char *actual, const sourceLocation *loc);

#define assertEqualsStr(exp, act) \
    ASSERT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc);

#define assertEqualsArrayInt(exp, act) \
    ASSERT_EQUALS_ARRAY_INT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc);

#define assertEqualsArrayShort(exp, act) \
    ASSERT_EQUALS_ARRAY_SHORT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc);

#define assertEqualsArrayLong(exp, act) \
    ASSERT_EQUALS_ARRAY_LONG((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc);

#define assertEqualsArrayFloat(exp, act) \
    ASSERT_EQUALS_ARRAY_Float((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc);


#define assertEqualsArrayDouble(exp, act) \
    ASSERT_EQUALS_ARRAY_Double((exp), (act), &CUR_SOURCE_LOCATION);



//ASSERT_NOT_EQUALS OF TYPES

bool ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc);
#define assertNotEqualsInt(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_NOT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc);
#define assertNotEqualsShort(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_NOT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc);
#define assertNotEqualsLong(exp, act) \
    ASSERT_NOT_EQUALS_LONG((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_NOT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc);
#define assertNotEqualsFloat(exp, act) \
    ASSERT_NOT_EQUALS_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);


bool ASSERT_NOT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc);
#define assertNotEqualsDouble(exp, act) \
    ASSERT_NOT_EQUALS_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_CHAR(char expected, char actual, const sourceLocation *loc);
#define assertNotEqualsChar(exp, act) \
    ASSERT_NOT_EQUALS_CHAR((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_STR(char *expected, char *actual, const sourceLocation *loc);
#define assertNotEqualsStr(exp, act) \
    ASSERT_NOT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION);

//ASSERT NOT EQUALS FOR ARRAY TYPES :( 
//
//
bool ASSERT_NOT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc);
#define assertNotEqualsArrayInt(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_INT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc);
#define assertNotEqualsArrayShort(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_SHORT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc);
#define assertNotEqualsArrayLong(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_Long((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc);
#define assertNotEqualsArrayFloat(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);

bool ASSERT_NOT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc);
#define assertNotEqualsArrayDouble(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);
//ASSERT BOOLEANS
bool ASSERT_TRUE(bool actual, const sourceLocation *loc);


#define assertTrue(act) \
    ASSERT_TRUE((act), &CUR_SOURCE_LOCATION);

bool ASSERT_FALSE(bool actual, const sourceLocation *loc);

#define assertFalse(act) \
    ASSERT_FALSE((act), &CUR_SOURCE_LOCATION);

//ASSERT NULL / NOT NULL
bool ASSERT_NOT_NULL(void *expr, const sourceLocation *loc);

#define assertNotNull(Expr) \
    ASSERT_NOT_NULL((Expr), &CUR_SOURCE_LOCATION);

bool ASSERT_NULL(void *expr, const sourceLocation *loc);

#define assertNull(Expr) \
    ASSERT_NULL((Expr), &CUR_SOURCE_LOCATION);

#endif
