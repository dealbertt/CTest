#include <stdio.h>
#define DEBUG_ASSERT_ENABLED 1
#include "../include/ctest.h"

int add(int a, int b){
    return a + b;
}
//You have to bind a testResult to each assert, in order to track the results of said tests
void test_add(TestResult *res){
    assert(res != NULL);
    DEBUG_ASSERT(add(2, 3) == 2, res);
    DEBUG_ASSERT(add(3, 3) == 6, res);
    DEBUG_ASSERT(add(-3, -3) == -6, res);
}

void test2(TestResult *res){

}

void test3(void){
    printf("Nothing");
    return;
}
int main(){
    CTest test = {test_add};
    /*
    TestGroup group;
    initGroup(&group);
    addTest(&group, "First try", &test);
    runTests(&group);
    */
    ASSERT_EQUALS_INT(4, add(2,2));
    return 0;
}
