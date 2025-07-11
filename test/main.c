#include "../include/ctest.h"


void test(struct CTest *test) {
    cAssert(test, &((struct Assertion){.type = TYPE_INT, .equal = true, .expected.intValue = 4, .actual.intValue = 4})); // equal
    cAssert(test, &((struct Assertion){.type = TYPE_INT, .equal = false, .expected.intValue = 4})); // not null
    cAssert(test, &((struct Assertion){.type = TYPE_CHAR_ARRAY, .equal = true, .expected.stringValue = "Hello World", .actual.stringValue = "Hello World"}));
    cAssert(test, &((struct Assertion){.type = TYPE_CHAR_ARRAY, .equal = false, .expected.stringValue = "Hello, World!", .actual.stringValue = "Hello World"}));
}

int main(){
    struct CTestGroup group = initGroup();
    addTest(&group, "First try", test);
    addTest(&group, "Second try", test);
    runTests(&group);
    return 0;
}
