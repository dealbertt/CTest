#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

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
}AssertResult;

typedef struct{
    unsigned int totalTests;
    unsigned int testsPassed;
    unsigned int testsFailed;
}TestResult;

typedef struct{
    void(*func)(TestResult *res);
    char name[20];
    bool passed;
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
int reportTestResults();

//THIS MIGHT NEED SOME REFINIMENT
int checkDifferenceArrayInt(int array1[], int array2[]);
int checkEqualArrayInt(int array1[], int array2[]);
int checkDifferenceArrayFloat(float array1[], float array2[]);
int checkEqualArrayFloat(float array1[], float array2[]);
int checkDifferenceArrayDouble(double array1[], double array2[]);
int checkEqualArrayDouble(double array1[], double array2[]);

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
static inline int reportAssertArrayInt(char *message, bool passed, int expected[], int actual[], bool equals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(equals){
            i = checkDifferenceArrayInt(expected, actual);
        }else{;
            i = checkEqualArrayInt(expected, actual);
        }
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %d vs Actual: %d in Index %d\n", expected[i], actual[i], i);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}
static inline int reportAssertFloat(char *message, bool passed, float expected, float actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %f vs Actual: %f\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}

static inline int reportAssertArrayFloat(char *message, bool passed, float expected[], float actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(isAssertEquals){
            i = checkDifferenceArrayFloat(expected, actual);
        }else{;
            i = checkEqualArrayFloat(expected, actual);
        }
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %f vs Actual: %f in Index %d\n", expected[i], actual[i], i);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}

static inline int reportAssertArrayDouble(char *message, bool passed, double expected[], double actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(isAssertEquals){
            i = checkDifferenceArrayDouble(expected, actual);
        }else{;
            i = checkEqualArrayDouble(expected, actual);
        }
        reportAssertFailed(message, loc, timeTaken);
        printf("----------------------\n");
        printf("Expected: %f vs Actual: %f in Index %d\n", expected[i], actual[i], i);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}

static inline int reportAssertChar(char *message, bool passed, char expected, char actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %c vs Actual: %c\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}
static inline int reportAssertString(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %s vs Actual: %s\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}

static inline int reportAssertBool(char *message, bool passed, bool expected, bool actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %d vs Actual: %d\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}
static inline int reportAssertNULL(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc, timeTaken);
        printf("Expected: %s vs Actual: %s\n", expected, actual);
        printf("----------------------\n");
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message, timeTaken);
        printf("----------------------\n");
    }
    return 0;
}


#define CUR_SOURCE_LOCATION (sourceLocation){__FILE__, __LINE__, __func__}

bool doAssert(bool expr, const sourceLocation *loc, const char *expression);
bool testAssert(bool expr, const sourceLocation *loc, const char *expression, TestResult *result);
//ASSERT_EQUALS OF TYPES
extern AssertResult unitResults;
extern TestResult testResults;

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


static inline bool ASSERT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    bool result = (expected == actual);

    clock_t now = clock();

    if(result){
        //printf("assertEquals(short): Passed | %hd == %hd\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsShort", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsShort(exp, act) \
    ASSERT_EQUALS_SHORT((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();
    bool result = (expected == actual);
    if(result){
        //printf("assertEquals(long): Passed | %ld == %ld\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(long): Failed | %ld != %ld\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsLong", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsLong(exp, act) \
    ASSERT_EQUALS_LONG((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();

    bool result = (expected == actual);
    if(result){
        //printf("assertEquals(float): Passed | %f == %f\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(float): Failed | %f != %f\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertFloat("assertEqualsFloat", result, expected, actual, msec, loc);
    return result;

}

#define assertEqualsFloat(exp, act) \
    ASSERT_EQUALS_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_DELTA(float expected, float actual, float delta, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();
    bool result = fabs(expected - actual) <= delta;
    if(result){
        //printf("assertEquals(float): Passed | %f == %f\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(float): Failed | %f != %f\n", expected, actual); 
        unitResults.assertsFailed++;
    } 
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertFloat("assertEqualsDelta", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsDelta(exp, act, delta) \
    ASSERT_EQUALS_DELTA((exp), (act), (delta), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();
    bool result = expected == actual;
    if(result){
        //printf("assertEquals(double): Passed | %f == %f\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(double): Failed | %f != %f\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsDouble", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsDouble(exp, act) \
    ASSERT_EQUALS_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_CHAR(const char expected, const char actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();
    bool result = expected == actual;
    if(result){
        //printf("assertEquals(char): Passed | %c == %c\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(char): Failed | %c != %c\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertChar("assertEqualsChar", result, expected, actual, msec, loc);
    return result;
}

#define assertEqualsChar(exp, act) \
    ASSERT_EQUALS_CHAR((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_EQUALS_STR(char *expected, char *actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = expected == actual;
    if(result){
        //printf("assertEquals(string): Passed | %s == %s\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEquals(string): Failed | %s != %s\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertString("assertEqualsString", result, expected, actual, msec, loc);
    return result;
}
#define assertEqualsStr(exp, act) \
    ASSERT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result == 0){
        //printf("assertEqualsArray(int): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(int): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAssertEqual = true;
    reportAssertArrayInt("assertEqualsArrayInt", result == 0, expected, actual, isAssertEqual, msec, loc);
    return result;
}

#define assertEqualsArrayInt(exp, act) \
    ASSERT_EQUALS_ARRAY_INT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result == 0){
        //printf("assertEqualsArray(short): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(short): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    
    bool isAssertEqual = true;
    reportAssertArrayInt("assertEqualsArrayShort", result == 0, (int *)expected, (int *)actual, isAssertEqual, msec, loc);
    return result;
}
#define assertEqualsArrayShort(exp, act) \
    ASSERT_EQUALS_ARRAY_SHORT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result == 0){
        //printf("assertEqualsArray(long): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(long): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAssertEqual = true;
    reportAssertArrayInt("assertEqualsArrayLong", result == 0, (int *)expected, (int *)actual, isAssertEqual, msec, loc);
    return result;
}

#define assertEqualsArrayLong(exp, act) \
    ASSERT_EQUALS_ARRAY_LONG((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result == 0){
        //printf("assertEqualsArray(float): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(float): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAssertEqual = true;
    reportAssertArrayFloat("assertEqualsArrayLong", result == 0, expected, actual, isAssertEqual, msec, loc);
    return result;
}

#define assertEqualsArrayFloat(exp, act) \
    ASSERT_EQUALS_ARRAY_Float((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result == 0){
        //printf("assertEqualsArray(double): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(double): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = true;
    reportAssertArrayDouble("assertEqualsArrayDouble", result == 0, expected, actual, isAsserEqual, msec, loc);
    return result;
}


#define assertEqualsArrayDouble(exp, act) \
    ASSERT_EQUALS_ARRAY_Double((exp), (act), &CUR_SOURCE_LOCATION);



//ASSERT_NOT_EQUALS OF TYPES

static inline bool ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertNotEqualsInt", result, expected, actual, msec, loc);
    return result;
}
#define assertNotEqualsInt(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_NOT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertNotEqualsShort", result, expected, actual, msec, loc);
    return result;
}
#define assertNotEqualsShort(exp, act) \
    ASSERT_NOT_EQUALS_INT((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_NOT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertNotEqualsLong", result, expected, actual, msec, loc);
    return result;
}
#define assertNotEqualsLong(exp, act) \
    ASSERT_NOT_EQUALS_LONG((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_NOT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertFloat("assertNotEqualsFloat", result, expected, actual, msec, loc);

    return result;
}
#define assertNotEqualsFloat(exp, act) \
    ASSERT_NOT_EQUALS_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);


static inline bool ASSERT_NOT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertNotEqualsDouble", result, expected, actual, msec, loc);

    return result;
}
#define assertNotEqualsDouble(exp, act) \
    ASSERT_NOT_EQUALS_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_CHAR(char expected, char actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertChar("assertNotEqualsChar", result, expected, actual, msec, loc);

    return result;
}
#define assertNotEqualsChar(exp, act) \
    ASSERT_NOT_EQUALS_CHAR((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_STR(char *expected, char *actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertString("assertNotEqualsChar", result, expected, actual, msec, loc);

    return result;
}
#define assertNotEqualsStr(exp, act) \
    ASSERT_NOT_EQUALS_STR((exp), (act), &CUR_SOURCE_LOCATION);

//ASSERT NOT EQUALS FOR ARRAY TYPES :( 
//
//
static inline bool ASSERT_NOT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = false;
    reportAssertArrayInt("AssertNotEqualsArrayInt", result, expected, actual, isAsserEqual, msec, loc);
    return result;
}
#define assertNotEqualsArrayInt(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_INT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = false;
    reportAssertArrayInt("AssertNotEqualsArrayShort", result, (int *)expected, (int *)actual, isAsserEqual, msec, loc);
    return result;
}
#define assertNotEqualsArrayShort(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_SHORT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = false;
    reportAssertArrayInt("AssertNotEqualsArrayLong", result, (int *)expected, (int *)actual, isAsserEqual, msec, loc);
    return result;
}
#define assertNotEqualsArrayLong(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_Long((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = false;
    reportAssertArrayFloat("AssertNotEqualsArrayFloat", result, expected, actual, isAsserEqual, msec, loc);
    return result;
}
#define assertNotEqualsArrayFloat(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_FLOAT((exp), (act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NOT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    if(result){
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    bool isAsserEqual = false;
    reportAssertArrayDouble("AssertNotEqualsArrayDouble", result, expected, actual, isAsserEqual, msec, loc);
    return result;
}
#define assertNotEqualsArrayDouble(exp, act) \
    ASSERT_NOT_EQUALS_ARRAY_DOUBLE((exp), (act), &CUR_SOURCE_LOCATION);
//ASSERT BOOLEANS
//
static inline bool ASSERT_TRUE(bool actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    if(actual){
        //printf("assertTrue: Passed | %d == true\n", actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertTrue: Failed | %d != true\n", actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertBool("assertTrue", actual, true, actual, msec, loc);
    return actual;
}


#define assertTrue(act) \
    ASSERT_TRUE((act), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_FALSE(bool actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();
    if(!actual){
        //printf("assertFalse: Passed | %d == false\n", actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertFalse: Failed | %d != false\n", actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertBool("assertFalse", actual, false, actual, msec, loc);
    return actual;
}

#define assertFalse(act) \
    ASSERT_FALSE((act), &CUR_SOURCE_LOCATION);

//ASSERT NULL / NOT NULL
static inline bool ASSERT_NOT_NULL(void *expr, const sourceLocation *loc){
    unitResults.totalAsserts++;
    
    bool result = (expr != NULL);
    if(result){
        //printf("assertNotNull: Passed |\n"); 
        reportAssertNULL("assertNotNULL", true, "Not NULL", "Not NULL",0, loc);
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotNull: Failed |\n"); 
        reportAssertNULL("assertNotNULL", false, "Not NULL", "NULL", 0, loc);
        unitResults.assertsFailed++;
    }
    return result;
}

#define assertNotNull(Expr) \
    ASSERT_NOT_NULL((Expr), &CUR_SOURCE_LOCATION);

static inline bool ASSERT_NULL(void *expr, const sourceLocation *loc){
    unitResults.totalAsserts++;
    bool result = (expr == NULL);
    if(result){
        //printf("assertNotNull: Passed |\n"); 
        reportAssertNULL("assertNULL", true, "NULL", "NULL", 0, loc);
        unitResults.assertsFailed++;
    }else{
        //printf("assertNotNull: Failed |\n"); 
        reportAssertNULL("assertNULL", false, "NULL", "NotNULL", 0, loc);
        unitResults.assertsFailed++;
    }
    return result;
}

#define assertNull(Expr) \
    ASSERT_NULL((Expr), &CUR_SOURCE_LOCATION);

#endif
