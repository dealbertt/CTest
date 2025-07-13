#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include "../include/ctest.h"

__attribute__((constructor))
void printHello(){
    //Initialize unitResult (maybe)
}

__attribute__((destructor))
void printGoodBye(){
    reportTestResults();
}

AssertResult unitResults = {0, 0, 0}; //struct in charge of the results of all the asserts that take place
TestResult testResults = {0, 0, 0}; //struct in charge of the results of the different tests that the user makes

AssertStruct arrayAsserts[MAX_ASSERTS];
CTest createTest(const char *name, void (*func)(TestResult *res)){
    CTest createdTest; 
    strncpy(createdTest.name, name, sizeof(createdTest.name) - 1);
    createdTest.func = func;
    createdTest.passed = false;
    return createdTest;
}

int initGroup(TestGroup *group, const char *name){
    group->testCount = 0;
    group->groupResult.totalTests = 0;  
    group->groupResult.testsFailed = 0;  
    group->groupResult.testsPassed = 0;  

    strncpy(group->name, name, sizeof(group->name) - 1);
    for(int i = 0; i < MAX_TESTS; i++){
        memset(group->test[i].name, '\0', sizeof(group->test[i].name));
    }
    return 0;
}

//Function to add a Test to a group
int addTest(TestGroup *group, CTest *test){
    int i = group->testCount;

    group->test[i] = *test;
    //strncpy(group->test[i].name, name, sizeof(group->test[i].name) - 1);
    //group->test[i].name[sizeof(group->test[i].name) - 1] = '\0';
    printf("Test %s added succesfully!\n", group->test[i].name);
    testResults.totalTests++;
    group->testCount++;
    return -1;
}

int runGroup(TestGroup *group){
    for(int i = 0; i < group->testCount; i++){
        printf("Running test: %s\n", group->test[i].name);
        group->test[i].func(&group->groupResult);
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
    result->totalTests++;
    if(!expr){
        result->testsFailed++;
        result->testsPassed= expr;
        printf("Assertion Failed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);

        return expr;
    }else{
        result->testsPassed++;
        return expr;
    }
}
