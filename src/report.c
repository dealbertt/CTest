#include <stdio.h>
#include "../include/report.h"

int getIndexArrayInt(const AssertStruct *assertion){
    int i = 0;
    while((assertion->actual.intValueArray[i] == assertion->expected.intValueArray[i]) == assertion->equal){
        i++;
    }
    return i;
}

int getIndexArrayFloat(float array1[], float array2[], bool equal){
    int i = 0;
    while((array1[i] == array2[i]) == equal){
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



int reportAssertPassed(const AssertStruct *assertion){
    green();
    printf("\xE2\x9C\x93[PASSED]: ");
    white();
    printf("%s\n", assertion->message);
    return 0;
}

int reportAssertFailed(const AssertStruct *assertion){
    red();
    printf("\xE2\x9C\x97[FAILED]: ");
    white();
    printf("%s\nOn file: %s | Line: %u | Function: %s\n", assertion->message, assertion->fileName, assertion->lineNumber, assertion->functionName);
    return 0;
}

int reportAssertFooter(void){
    printf("----------------------\n");
    fflush(stdout);
    return 0;
}

int reportAssertInt(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %d vs Actual: %d\n", assertion->expected.intValue, assertion->actual.intValue);
    }else if(VERBOSE_ASSERT) {
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertArrayInt(const AssertStruct *assertion){
    if(!assertion->passed){
        getIndexArrayInt(assertion);
        reportAssertFailed(assertion);
        printf("Expected: %d vs Actual: %d in Index %d\n", assertion->expected.intValueArray[assertion->index], assertion->actual.intValueArray[assertion->index], assertion->index);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertFloat(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %f vs Actual: %f\n", assertion->expected.floatValue, assertion->actual.floatValue);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertArrayFloat(const AssertStruct *assertion){
    if(!assertion->passed){
        getIndexArrayInt(assertion);
        reportAssertFailed(assertion);
        printf("Expected: %f vs Actual: %f in Index %d\n", assertion->expected.floatValueArray[assertion->index], assertion->actual.floatValueArray[assertion->index], assertion->index);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertArrayDouble(const AssertStruct *assertion){
    if(!assertion->passed){
        getIndexArrayInt(assertion);
        reportAssertFailed(assertion);
        printf("Expected: %f vs Actual: %f in Index %d\n", assertion->expected.floatValueArray[assertion->index], assertion->actual.floatValueArray[assertion->index], assertion->index);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertChar(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %c vs Actual: %c\n", assertion->expected.charValue, assertion->actual.charValue);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertString(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %s vs Actual: %s\n", assertion->expected.stringValue, assertion->actual.stringValue);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertBool(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %d vs Actual: %d\n", assertion->expected.boolValue, assertion->actual.boolValue);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}

int reportAssertNULL(const AssertStruct *assertion){
    if(!assertion->passed){
        reportAssertFailed(assertion);
        printf("Expected: %s vs Actual: %s\n", assertion->expected.stringValue, assertion->actual.stringValue);
    }else if(VERBOSE_ASSERT){
        reportAssertPassed(assertion);
    }
    reportAssertFooter();
    return 0;
}
