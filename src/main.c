#include <stdio.h>
#define DEBUG_ASSERT_ENABLED 1
#include "../include/ctest.h"

int add(int a, int b){
    return a + b;
}
void test_add(void){
    DEBUG_ASSERT(add(2, 3) == 2);
    DEBUG_ASSERT(add(3, 3) == 6);
    DEBUG_ASSERT(add(-3, -3) == -6);
}

int main(){
    TestGroup group;
    CTest test = {test_add};
    initGroup(&group);
    addTest(&group, "First try", &test);
    runTests(&group);
    return 0;
}
