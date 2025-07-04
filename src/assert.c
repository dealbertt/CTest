#include "../include/assert.h"
unsigned int totalAsserts = 0;
unsigned int assertsPassed = 0;
unsigned int assertsFailed = 0;

void doAssert(bool expr, const sourceLocation *loc, const char *expression){
    totalAsserts++;
    if(!expr){
        printf("Assertion Failed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);
        assertsFailed++; 
    }else{
        printf("Assertion Passed! ");
        printf("On file %s | line: %u | function: %s\n", loc->fileName, loc->line_number, loc->functionName);
        assertsPassed++;
    }
}
