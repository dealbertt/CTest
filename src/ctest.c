#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include "../include/ctest.h"
TestResult unitResults = {0, 0, 0};

AssertStruct arrayAsserts[MAX_ASSERTS];

int initGroup(TestGroup *group){
    for(int i = 0; i < MAX_TESTS; i++){
        group->testOccupied[i] = false;
    }
    return 0;
}

int addTest(TestGroup *group, const char *name, CTest *test){
    for(int i = 0; i < MAX_TESTS; i++){
        if(!group->testOccupied[i]){
            group->test[i] = *test;
            strncpy(group->test[i].name, name, sizeof(group->test[i].name) - 1);
            group->test[i].name[sizeof(group->test[i].name) - 1] = '\0';
            printf("Test %s added succesfully!\n", group->test[i].name);
            group->testOccupied[i] = !group->testOccupied[i];
            return 0;
        }
    }
    return -1;
}

int runTests(TestGroup *group){
    for(int i = 0; i < MAX_TESTS; i++){
        if(group->testOccupied[i]){
            printf("Running test: %s\n", group->test[i].name);
                group->test[i].func(&group->test[i].res);
        }
    }
     
    return 0;
}

int reportAssertPassed(char *message){
    green();
    printf("[PASSED]: ");
    white();
    printf("%s\n", message);
    return 0;
}

int reportAssertInt(char *message, bool passed, int expected, int actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %d vs Actual: %d\n",expected, actual);
    }else if(passed && VERBOSE_ASSERT) {
        green();
        printf("[PASSED]: ");
        white();
        printf("%s\n", message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertFloat(char *message, bool passed, float expected, float actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %f vs Actual: %f\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertChar(char *message, bool passed, char expected, char actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %c vs Actual: %c\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertString(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %s vs Actual: %s\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertBool(char *message, bool passed, bool expected, bool actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %d vs Actual: %d\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertNULL(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        red();
        printf("[FAILED]: ");
        white();
        printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
        printf("Expected: %s vs Actual: %s\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

//ASSERTION PART --------------------------------
void displayAssertResults(){
    for(int i = 0; i < MAX_ASSERTS; i++){

    }
}
bool doAssert(bool expr, const sourceLocation *loc, const char *expression){
    if(!expr){
        printf("Assertion Failed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);
        return expr;
    }else{
        printf("Assertion Passed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);
        return expr;
    }
}

bool testAssert(bool expr, const sourceLocation *loc, const char *expression, TestResult *result){
    result->totalAsserts++;
    if(!expr){
        result->assertsFailed++;
        result->testPassed = expr;
        printf("Assertion Failed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);

        return expr;
    }else{
        result->assertsPassed++;
        result->testPassed = expr;
        return expr;
    }

}


//ASSERT_EQUALS OF TYPES
bool ASSERT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
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

bool ASSERT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    bool result = (expected == actual);

    clock_t now = clock();

    if(result){
        //printf("assertEquals(short): Passed | %hd == %hd\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        unitResults.assertsFailed++;
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);

        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsShort", result, expected, actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    clock_t now = clock();
    bool result = (expected == actual);
    if(result){
        //printf("assertEquals(long): Passed | %ld == %ld\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        ////printf("assertEquals(long): Failed | %ld != %ld\n", expected, actual); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    reportAssertInt("assertEqualsLong", result, expected, actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc){
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
bool ASSERT_EQUALS_DELTA(float expected, float actual, float delta, const sourceLocation *loc){
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

bool ASSERT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc){
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

bool ASSERT_EQUALS_CHAR(const char expected, const char actual, const sourceLocation *loc){
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
bool ASSERT_EQUALS_STR(char *expected, char *actual, const sourceLocation *loc){
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

bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(!result){
        //printf("assertEqualsArray(int): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(int): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertEqualsArrayInt", result, *expected, *actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result){
        //printf("assertEqualsArray(short): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(short): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;
    
    reportAssertInt("assertEqualsArrayInt", result, *expected, *actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result){
        //printf("assertEqualsArray(long): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(long): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertEqualsArrayInt", result, *expected, *actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result){
        //printf("assertEqualsArray(float): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(float): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertFloat("assertEqualsArrayInt", result, *expected, *actual, msec, loc);
    return result;
}

bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    int result = memcmp(expected, actual, sizeof(&expected));
    if(result){
        //printf("assertEqualsArray(double): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertEqualsArray(double): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertEqualsArrayInt", result, *expected, *actual, msec, loc);
    return result;
}
//--------------------------------------------------------

//ASSERT_NOT_EQUALS OF TYPES
bool ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    bool result = (expected != actual);
    if(result){
        //printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        //printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertInt("assertNotEqualsInt", result, expected, actual, msec, loc);
    return result;
}
//--------------------------------------------------------


//ASSERT BOOLEANS
bool ASSERT_TRUE(bool actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();

    if(actual){
        //printf("assertTrue: Passed | %d == true\n", actual); 
    }else{
        //printf("assertTrue: Failed | %d != true\n", actual); 
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertBool("assertTrue", actual, true, actual, msec, loc);
    return actual;
}

bool ASSERT_FALSE(bool actual, const sourceLocation *loc){
    unitResults.totalAsserts++;

    clock_t now = clock();
    if(!actual){
        //printf("assertFalse: Passed | %d == false\n", actual); 
    }else{
        //printf("assertFalse: Failed | %d != false\n", actual); 
    }
    clock_t difference = clock() - now;
    long msec = difference /  CLOCKS_PER_SEC;

    reportAssertBool("assertFalse", actual, false, actual, msec, loc);
    return actual;
}
//--------------------------------------------------------

//ASSERT NULL / NOT NULL
bool ASSERT_NOT_NULL(void *expr, const sourceLocation *loc){
    unitResults.totalAsserts++;
    
    bool result = (expr != NULL);
    if(result){
        //printf("assertNotNull: Passed |\n"); 
        reportAssertNULL("assertNotNULL", true, "Not NULL", "Not NULL",0, loc);
    }else{
        //printf("assertNotNull: Failed |\n"); 
        reportAssertNULL("assertNotNULL", false, "Not NULL", "NULL", 0, loc);
    }
    return result;
}

bool ASSERT_NULL(void *expr, const sourceLocation *loc){
    bool result = (expr == NULL);
    if(result){
        //printf("assertNotNull: Passed |\n"); 
        reportAssertNULL("assertNULL", true, "NULL", "NULL", 0, loc);
    }else{
        //printf("assertNotNull: Failed |\n"); 
        reportAssertNULL("assertNULL", false, "NULL", "NULL", 0, loc);
    }
    return result;
}
//--------------------------------------------------------
