#ifndef CTEST_H
#define CTEST_H
#include <stdbool.h>
bool assertEqual(int expected, int (*funcPointer)(int, int), int a, int b);

int sumTest(int a, int b);


#endif
