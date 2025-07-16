#include <stdio.h>
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

void test2(TestResult *res){
    printf("Boo\n");
}

void test3(void){
    printf("Nothing");
    return;
}

int main(){
    TestGroup group;
    initGroup(&group, "Test group");
    CTest test3 = createTest("Test 1", test2);
    addTest(&group, &test3);
    runGroup(&group);

    FILE *Emptyptr = NULL;
    FILE *ptr = fopen("test/main.c", "r");

    float a = 5;
    float b = 5;

    double c = 2;
    double d = 4;

    short e = 5;
    short f = 6;

    long g = 1200000;
    long h = 2400000;

    int array1[] = {1,2,3};
    int array2[] = {1,2,3};
    int array3[] = {3,2,1};


    assertEqualsInt(4, add(2,2));
    assertEqualsFloat(a, b);
    assertEqualsDouble(c, d);
    assertEqualsArrayInt(array1, array2);
    assertEqualsArrayInt(array1, array3);
    assertEqualsShort(e, f);
    assertEqualsLong(g, h);


    //assertNotEqualsInt(5, add(3, 2));
    //assertNotEqualsInt(6, add(3, 2));

    assertEqualsStr("Hello World", "Hello World");
    assertTrue(2 < 4);
    assertFalse(2 < 4);
    assertNull(Emptyptr);
    assertNotNull(ptr);

    float delta = 0.0001;

    assertEqualsDelta(g, h, delta);

    assertNotEqualsInt(4, add(2,2));
    assertNotEqualsFloat(a, b);
    assertNotEqualsDouble(c, d);
    assertEqualsArrayInt(array1, array2); // should pass
    assertEqualsArrayInt(array1, array3); // should fail
    assertNotEqualsArrayInt(array1, array2); // should fail aswell
    assertNotEqualsShort(e, f);
    assertNotEqualsLong(g, h);


    return 0;
}
