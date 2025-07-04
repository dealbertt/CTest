#define DEBUG_ASSERT_ENABLED 1
#include "../include/ctest.h"

int add(int a, int b){
    return a + b;
}
//You have to bind a testResult to each assert, in order to track the results of said tests
void test_add(TestResult *res){
    DEBUG_ASSERT(add(2, 3) == 2, res);
    DEBUG_ASSERT(add(3, 3) == 6, res);
    DEBUG_ASSERT(add(-3, -3) == -6, res);
}

int main(){
    TestGroup group;
    CTest test = {test_add};
    initGroup(&group);
    addTest(&group, "First try", &test);
    runTests(&group);
    return 0;
}
