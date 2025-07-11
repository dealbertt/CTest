#include "../include/ctest.h"

struct CTestGroup initGroup(){
    return (struct CTestGroup ){.testCount = 0};
}

int addTest(struct CTestGroup *group, char *name, void (*test)(struct CTest *test)){
    group->test[group->testCount++] = (struct CTest){.name = name, .func = test};
    printf("Test '%s' added succesfully!\n", name);
    return 0;
}

int runTests(struct CTestGroup *group){
    for(int index = 0; index < group->testCount; index++){
        printf("Running test: '%s'\n", group->test[index].name);
        group->test[index].func(&group->test[index]);
    }
    return 0;
}

int cAssert(struct CTest *test, struct Assertion *assertion) {
    // String
    if(assertion->type == TYPE_CHAR_ARRAY){
        if(assertion->equal == true){
            assertion->passed = ASSERT_EQUAL(&assertion->expected.stringValue, &assertion->actual.stringValue, sizeof(&assertion->expected.stringValue));
        }else{
            assertion->passed = ASSERT_NOT_EQUAL(&assertion->expected.stringValue, &assertion->actual.stringValue, sizeof(&assertion->expected.stringValue));
        }
    }
    //int
    if(assertion->type == TYPE_INT){
        if(assertion->equal == true){
            assertion->passed = ASSERT_EQUAL(&assertion->expected.intValue, &assertion->actual.intValue, sizeof(&assertion->expected.stringValue));
        }else{
            assertion->passed = ASSERT_NOT_EQUAL(&assertion->expected.intValue, &assertion->actual.intValue, sizeof(&assertion->expected.stringValue));
        }
    }
    report(assertion);
    return 0;
}
