#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    const char *fileName;
    unsigned line_number;
    const char* functionName;
} sourceLocation;

#define CUR_SOURCE_LOCATION (sourceLocation){__FILE__, __LINE__, __func__}

void doAssert(bool expr, const sourceLocation *loc, const char *expression);

#if DEBUG_ASSERT_ENABLED
    #define DEBUG_ASSERT(Expr) \
        doAssert((Expr), &CUR_SOURCE_LOCATION, #Expr)
#else
    #define DEBUG_ASSERT(Expr)
#endif

#endif
