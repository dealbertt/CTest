#include <stdio.h>
#include "../include/ctest.h"

int reportAssertPassed(char *message, long timeTaken){
    green();
    printf("\xE2\x9C\x93[PASSED]: ");
    white();
    printf("%s\n", message);
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertFailed(char *message, const sourceLocation *loc, long timeTaken){
    red();
    printf("\xE2\x9C\x97[FAILED]: ");
    white();
    printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertFooter(long timeTaken){
    printf("Time Taken: %ld ms\n", timeTaken);
    fflush(stdout);
    return 0;
}

int checkDifferenceArrayInt(int array1[], int array2[]){
    int i = 0;
    while(array1[i] == array2[i]){
        i++;
    }
    return i;
}

int checkEqualArrayInt(int array1[], int array2[]){
    int i = 0;
    while(array1[i] != array2[i]){
        i++;
    }
    return i;
}

int checkDifferenceArrayFloat(float array1[], float array2[]){
    int i = 0;
    while(array1[i] == array2[i]){
        i++;
    }
    return i;
}

int checkEqualArrayFloat(float array1[], float array2[]){
    int i = 0;
    while(array1[i] != array2[i]){
        i++;
    }
    return i;
}

int checkDifferenceArrayDouble(double array1[], double array2[]){
    int i = 0;
    while(array1[i] == array2[i]){
        i++;
    }
    return i;
}

int checkEqualArrayDouble(double array1[], double array2[]){
    int i = 0;
    while(array1[i] != array2[i]){
        i++;
    }
    return i;
}
int reportGroupResults(TestGroup *group){
    printf("Run Summary of Group: %s\n", group->name);
    printf("Total\tRan\tPassed\tFailed\n");
    printf("%d\t%d\t%d\t%d\n",group->groupResult.totalTests, group->groupResult.totalTests, group->groupResult.testsPassed, group->groupResult.testsFailed);
    return 0;
}

int reportTestResults(){
    printf("Run summary:\n");
    printf("Type\tTotal\tRan\tPassed\tFailed\n");
    printf("asserts\t%d\t%d\t%d\t%d\n",unitResults.totalAsserts, unitResults.totalAsserts, unitResults.assertsPassed, unitResults.assertsFailed);
    printf("tests\t%d\t%d\t%d\t%d\n", testResults.totalTests, testResults.totalTests, testResults.testsPassed, testResults.testsFailed);
    return 0;
}
