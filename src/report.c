#include <stdio.h>
#include "../include/report.h"

int report(struct Assertion *assertion) {
    if(assertion->passed){
        green();
        printf("\xE2\x9C\x93[PASSED]: ");
    }else{
        red();
        printf("\xE2\x9C\x97[FAILED]: ");
    }
    white();
    printf("%s\n", assertion->message);
    printf("----------\n");
    fflush(stdout);
    return 0;
}

int getArrayIndex(struct Assertion *assertion){
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
