#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#define MAX_TESTS 20
typedef struct{
    void (*testName)(void);
    char name[20];
}CTest;

typedef struct{;
    char name[20];
    CTest test[MAX_TESTS];
    bool testOccupied[MAX_TESTS];
}TestGroup;

void test_add(void);
int initGroup(TestGroup *group);
int addTest(TestGroup *group, const char *name, CTest *test);
int runTests(TestGroup *group);


bool assertEqualTest(int expected, int (*funcPointer)(int count, ...), int count, ...);
bool assertEqualInt(int expected, int (*funcPointer)(int, int), int a, int b);
bool assertEqualDouble(double expected, int (*funcPointer)(double, double), double a, double b);



#endif
