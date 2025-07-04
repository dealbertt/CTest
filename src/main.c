#include <stdio.h>
#include "../include/ctest.h"

int main(){
    TestGroup group;
    CTest test = {test_add};
    initGroup(&group);
    addTest(&group, "First try", &test);
    runTests(&group);

   return 0;
}
