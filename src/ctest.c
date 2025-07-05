#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "../include/ctest.h"
TestResult unitResults = {0, 0, 0};
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


void ASSERT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEqualsInt: Passed | %d == %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        printf("assertEqualsInt: Failed | %d != %d\n", expected, actual); 
        unitResults.assertsFailed++;
    }
}
void ASSERT_NOT_EQUALS_INT(int expected, int actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected != actual){
        printf("assertNotEqualsInt: Passed | %d != %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        printf("assertNotEqualsInt: Failed | %d == %d\n", expected, actual); 
        unitResults.assertsPassed++;
    }
}

void ASSERT_EQUALS_STR(const char *expected, const char *actual, const sourceLocation *loc){
    unitResults.totalAsserts++;
    if(expected == actual){
        printf("assertEqualsStr: Passed | %s == %s\n", expected, actual); 
        unitResults.assertsPassed++;
    }else{
        printf("assertEqualsStr: Failed | %s != %s\n", expected, actual); 
        unitResults.assertsFailed++;
    }
}

void ASSERT_TRUE(bool actual, const sourceLocation *loc){
    if(actual){
        printf("assertEqualsTrue: Passed | %d == true\n", actual); 
    }else{
        printf("assertEqualsTrue: Failed | %d != true\n", actual); 
    }
}

void ASSERT_FALSE(bool actual, const sourceLocation *loc){
    if(!actual){
        printf("assertFalse: Passed | %d == false\n", actual); 
    }else{
        printf("assertFalse: Failed | %d != false\n", actual); 
    }
}

void ASSERT_NOT_NULL(void *expr, const sourceLocation *loc){
    if(expr != NULL){
        printf("assertNotNull: Passed |\n"); 
    }else{
        printf("assertNotNull: Failed |\n"); 
    }
}
