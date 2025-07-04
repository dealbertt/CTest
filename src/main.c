#include <stdio.h>
#include "../include/ctest.h"
#define DEBUG_ASSERT_ENABLED 1

#include "../include/assert.h"
void test_add(void){
    printf("Hola que tal\n");
}

int main(){
    /*
    TestGroup group;
    CTest test = {test_add};
    initGroup(&group);
    addTest(&group, "First try", &test);
    runTests(&group);
    */
    int a = 2;
    int b = 3;
    DEBUG_ASSERT(a == b);
    DEBUG_ASSERT(a < b);
    return 0;
}
