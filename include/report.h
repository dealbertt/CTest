#ifndef report_h
#define report_h

#include "../include/assert.h"

#ifndef VERBOSE_ASSERT
#define VERBOSE_ASSERT 0
#endif

//terminal colours
#define clear() printf("\033[H\033[J")
#define red() printf("\033[31m")
#define blue() printf("\033[34m")
#define green() printf("\033[32m")
#define yellow() printf("\033[33m")
#define white() printf("\033[0m")

int report(struct Assertion *assertion);
int reportAssertPassed(struct Assertion *assertion);
int reportAssertInt(struct Assertion *assertion);//(char *message, bool passed, int expected, int actual, long timeTaken);
int reportAssertArrayInt(struct Assertion *assertion);//(char *message, bool passed, int expected[], int actual[],bool equals, long timeTaken);
int reportAssertFloat(struct Assertion *assertion);//(char *message, bool passed, float expected, float actual, long timeTaken);
int reportAssertArrayFloat(struct Assertion *assertion);//(char *message, bool passed, float expected[], float actual[], bool isAssertEquals, long timeTaken);
int reportAssertArrayDouble(struct Assertion *assertion);//(char *message, bool passed, double expected[], double actual[], bool isAssertEquals, long timeTaken);
int reportAssertChar(struct Assertion *assertion);//(char *message, bool passed, char expected, char actual, long timeTaken);
int reportAssertString(struct Assertion *assertion);//(char *message, bool passed, char *expected, char *actual, long timeTaken);
int reportAssertBool(struct Assertion *assertion);//(char *message, bool passed, bool expected, bool actual, long timeTaken);
int reportAssertNULL(struct Assertion *assertion);//(char *message, bool passed, char *expected, char *actual, long timeTaken);

#endif
