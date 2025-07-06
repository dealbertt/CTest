#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/ctest.h"
TestResult unitResults = {0, 0, 0};

AssertStruct arrayAsserts[MAX_ASSERTS];
int sumTest(int a, int b){
    return a + b;
}

bool assertEqualInt(int expected, int (*funcPointer)(int, int), int a, int b){
    int result = funcPointer(a, b);
    if(expected == result){
        printf("Yay it works, equal!\n");
        return true;
    }else{
        printf("Not really equal man!\n");
        return false;
    }
}

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
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(int): Passed | %d == %d\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(int): Failed | %d != %d\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_SHORT(short expected, short actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(short): Passed | %hd == %hd\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        red();
        printf("assertEquals(short): Failed | %hd != %hd\n", expected, actual); 
        white();
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);

        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_LONG(long expected, long actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(long): Passed | %ld == %ld\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(long): Failed | %ld != %ld\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_FLOAT(float expected, float actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(float): Passed | %f == %f\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(float): Failed | %f != %f\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }

}

bool ASSERT_EQUALS_DOUBLE(double expected, double actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(double): Passed | %f == %f\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(double): Failed | %f != %f\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_CHAR(const char expected, const char actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(char): Passed | %c == %c\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(char): Failed | %c != %c\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }
}
bool ASSERT_EQUALS_STR(const char *expected, const char *actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEquals(string): Passed | %s == %s\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEquals(string): Failed | %s != %s\n", expected, actual); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[], const sourceLocation *loc){
    int result = memcmp(expected, actual, sizeof(&expected));
    if(!result){
        printf("assertEqualsArray(int): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEqualsArray(int): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[], const sourceLocation *loc){
    if(memcmp(expected, actual, sizeof(&expected))){
        printf("assertEqualsArray(short): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEqualsArray(short): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[], const sourceLocation *loc){
    if(memcmp(expected, actual, sizeof(&expected))){
        printf("assertEqualsArray(long): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEqualsArray(long): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[], const sourceLocation *loc){
    if(memcmp(expected, actual, sizeof(&expected))){
        printf("assertEqualsArray(float): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEqualsArray(float): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
        return false;
    }
}

bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[], const sourceLocation *loc){
    if(memcmp(expected, actual, sizeof(&expected))){
        printf("assertEqualsArray(double): Passed | Array expected == Array Actual\n"); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertEqualsArray(double): Failed | Array expected != Array Actual\n"); 
        unitResults.assertsFailed++;
        return false;
    }
}
//--------------------------------------------------------

//ASSERT_NOT_EQUALS OF TYPES
bool ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected != actual){
        printf("assertNotEquals(int): Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
        return true;
    }else{
        printf("assertNotEquals(int): Failed | %d == %d\n", expected, actual); 
        unitResults.assertsPassed++;
        return false;
    }
}
//--------------------------------------------------------


//ASSERT BOOLEANS
bool ASSERT_TRUE(bool actual, const sourceLocation *loc){
    if(actual){
        printf("assertTrue: Passed | %d == true\n", actual); 
        return actual;
    }else{
        printf("assertTrue: Failed | %d != true\n", actual); 
        return actual;
    }
}

bool ASSERT_FALSE(bool actual, const sourceLocation *loc){
    if(!actual){
        printf("assertFalse: Passed | %d == false\n", actual); 
        return true;
    }else{
        printf("assertFalse: Failed | %d != false\n", actual); 
        return false;
    }
}
//--------------------------------------------------------

//ASSERT NULL / NOT NULL
bool ASSERT_NOT_NULL(void *expr, const sourceLocation *loc){
    if(expr != NULL){
        printf("assertNotNull: Passed |\n"); 
        return true;
    }else{
        printf("assertNotNull: Failed |\n"); 
        return false;
    }
}
//--------------------------------------------------------
