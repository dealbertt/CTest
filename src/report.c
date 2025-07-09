#include <stdio.h>
#include "../include/ctest.h"

int reportAssertPassed(char *message){
    green();
    printf("\xE2\x9C\x93[PASSED]: ");
    white();
    printf("%s\n", message);
    return 0;
}

int reportAssertFailed(char *message, const sourceLocation *loc){
    red();
    printf("\xE2\x9C\x97[FAILED]: ");
    white();
    printf("%s\nOn file: %s | Line: %u | Function: %s\n", message, loc->fileName, loc->line_number, loc->functionName);
    return 0;
}

int reportAssertFooter(long timeTaken){
    printf("Time Taken: %ld ms\n", timeTaken);
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertInt(char *message, bool passed, int expected, int actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %d vs Actual: %d\n",expected, actual);
    }else if(VERBOSE_ASSERT) {
        green();
        printf("[PASSED]: ");
        white();
        printf("%s\n", message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertArrayInt(char *message, bool passed, int expected[], int actual[],bool equals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(equals){
            i = checkDifferenceArrayInt(expected, actual);
        }else{;
            i = checkEqualArrayInt(expected, actual);
        }
        reportAssertFailed(message, loc);
        printf("Expected: %d vs Actual: %d in Index %d\n", expected[i], actual[i], i);
    }else if(VERBOSE_ASSERT){
        green();
        printf("[PASSED]: ");
        white();
        printf("%s\n", message);
    }
    reportAssertFooter(timeTaken);
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
int reportAssertFloat(char *message, bool passed, float expected, float actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %f vs Actual: %f\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertArrayFloat(char *message, bool passed, float expected[], float actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(isAssertEquals){
            i = checkDifferenceArrayFloat(expected, actual);
        }else{;
            i = checkEqualArrayFloat(expected, actual);
        }
        reportAssertFailed(message, loc);
        printf("Expected: %f vs Actual: %f in Index %d\n", expected[i], actual[i], i);
    }else if(VERBOSE_ASSERT){
        green();
        printf("[PASSED]: ");
        white();
        printf("%s\n", message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertArrayDouble(char *message, bool passed, double expected[], double actual[], bool isAssertEquals, long timeTaken, const sourceLocation *loc){
    if(!passed){
        int i = 0;
        if(isAssertEquals){
            i = checkDifferenceArrayDouble(expected, actual);
        }else{;
            i = checkEqualArrayDouble(expected, actual);
        }
        reportAssertFailed(message, loc);
        printf("Expected: %f vs Actual: %f in Index %d\n", expected[i], actual[i], i);
    }else if(VERBOSE_ASSERT){
        green();
        printf("[PASSED]: ");
        white();
        printf("%s\n", message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}
int reportAssertChar(char *message, bool passed, char expected, char actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %c vs Actual: %c\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertString(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %s vs Actual: %s\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertBool(char *message, bool passed, bool expected, bool actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %d vs Actual: %d\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}

int reportAssertNULL(char *message, bool passed, char *expected, char *actual, long timeTaken, const sourceLocation *loc){
    if(!passed){
        reportAssertFailed(message, loc);
        printf("Expected: %s vs Actual: %s\n",expected, actual);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(message);
    }
    reportAssertFooter(timeTaken);
    return 0;
}
