#ifndef assert_h
#define assert_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define CUR_SOURCE_LOCATION (Assertion){.fileName = __FILE__, .lineNumber = __LINE__, .functionName = __func__}

enum Types{
    TYPE_POINTER,
    TYPE_NULL,
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_FLOAT,
    TYPE_CHAR_ARRAY
};

union ValueUnion{
    void *pointer;
    char charValue;
    char *stringValue;
    char **stringValueArray;
    bool boolValue;
    bool *boolValueArray;
    short shortValue;
    short *shortValueArray;
    int intValue;
    int *intValueArray;
    long longValue;
    long *longValueArray;
    long long longlongValue;
    long long *longlongValueArray;
    float floatValue;
    float *floatValueArray;
    double doubleValue;
    double *doubleValueArray;
    long double longdoubleValue;
    long double *longdoubleValueArray;
};

struct Assertion{
    char *name;
    bool passed;
    char *message;
    const char *fileName;
    unsigned lineNumber;
    const char *functionName;
    int index;
    enum Types type;
    bool equal;
    union ValueUnion expected;
    union ValueUnion actual;
};

bool ASSERT_EQUAL(void *expected, void *actual, size_t size);
bool ASSERT_NOT_EQUAL(void *expected, void *actual, size_t size);

#endif
