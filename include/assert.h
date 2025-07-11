#ifndef assert_h
#define assert_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#define CUR_SOURCE_LOCATION (AssertStruct){.fileName = __FILE__, .lineNumber = __LINE__, .functionName = __func__}

typedef struct{
    char *name;
    bool passed;
    bool equal;
    char *message;
    const char *fileName;
    unsigned lineNumber;
    const char *functionName;
    int index;
    union{
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
    }expected;
    union{
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
    }actual;
}AssertStruct;

#endif
