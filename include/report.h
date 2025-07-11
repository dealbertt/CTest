#ifndef report_h
#define report_h

#include <stdbool.h>
#include "../include/assert.h"

#if VERBOSE_ASSERT_RESULT
#define VERBOSE_ASSERT 1
#else
#define VERBOSE_ASSERT 0
#endif

//terminal colours
#define clear() printf("\033[H\033[J")
#define red() printf("\033[31m")
#define blue() printf("\033[34m")
#define green() printf("\033[32m")
#define yellow() printf("\033[33m")
#define white() printf("\033[0m")

int report(const AssertStruct *assertion);
int reportAssertInt(const AssertStruct *assertion);//(char *message, bool passed, int expected, int actual, long timeTaken);
int reportAssertArrayInt(const AssertStruct *assertion);//(char *message, bool passed, int expected[], int actual[],bool equals, long timeTaken);
int reportAssertFloat(const AssertStruct *assertion);//(char *message, bool passed, float expected, float actual, long timeTaken);
int reportAssertArrayFloat(const AssertStruct *assertion);//(char *message, bool passed, float expected[], float actual[], bool isAssertEquals, long timeTaken);
int reportAssertArrayDouble(const AssertStruct *assertion);//(char *message, bool passed, double expected[], double actual[], bool isAssertEquals, long timeTaken);
int reportAssertChar(const AssertStruct *assertion);//(char *message, bool passed, char expected, char actual, long timeTaken);
int reportAssertString(const AssertStruct *assertion);//(char *message, bool passed, char *expected, char *actual, long timeTaken);
int reportAssertBool(const AssertStruct *assertion);//(char *message, bool passed, bool expected, bool actual, long timeTaken);
int reportAssertNULL(const AssertStruct *assertion);//(char *message, bool passed, char *expected, char *actual, long timeTaken);

#endif
