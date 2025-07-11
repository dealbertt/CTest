#include "../include/assert.h"

//ASSERTION PART --------------------------------

//ASSERT_EQUALS OF TYPES
bool ASSERT_EQUALS_INT(int expected, int actual){
    bool result = (expected == actual);
//    reportAssertInt("assertEqualsInt", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_SHORT(short expected, short actual){
    bool result = (expected == actual);
//    reportAssertInt("assertEqualsShort", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_LONG(long expected, long actual){
    bool result = (expected == actual);
//    reportAssertInt("assertEqualsLong", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_FLOAT(float expected, float actual){
    bool result = (expected == actual);
//    reportAssertFloat("assertEqualsFloat", result, expected, actual, msec, assertion);
    return result;
    
}
bool ASSERT_EQUALS_DELTA(float expected, float actual, float delta){
    bool result = fabs(expected - actual) <= delta;
//    reportAssertFloat("assertEqualsDelta", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_DOUBLE(double expected, double actual){
    bool result = expected == actual;
//    reportAssertInt("assertEqualsDouble", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_CHAR(const char expected, const char actual){
    bool result = expected == actual;
//    reportAssertChar("assertEqualsChar", result, expected, actual, msec, assertion);
    return result;
}
bool ASSERT_EQUALS_STR(char *expected, char *actual){
    bool result = expected == actual;
//    reportAssertString("assertEqualsString", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_ARRAY_INT(int expected[], int actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayInt("assertEqualsArrayInt", result == 0, expected, actual, isAssertEqual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_ARRAY_SHORT(short expected[], short actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayInt("assertEqualsArrayShort", result == 0, (int *)expected, (int *)actual, isAssertEqual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_ARRAY_LONG(long expected[], long actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayInt("assertEqualsArrayLong", result == 0, (int *)expected, (int *)actual, isAssertEqual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_ARRAY_FLOAT(float expected[], float actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayFloat("assertEqualsArrayLong", result == 0, expected, actual, isAssertEqual, msec, assertion);
    return result;
}

bool ASSERT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayDouble("assertEqualsArrayDouble", result == 0, expected, actual, isAsserEqual, msec, assertion);
    return result;
}
//--------------------------------------------------------

//ASSERT_NOT_EQUALS OF TYPES
bool ASSERT_NOT_EQUALS_INT(int expected, int actual){
    bool result = (expected != actual);
//    reportAssertInt("assertNotEqualsInt", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_SHORT(short expected, short actual){
    bool result = (expected != actual);
//    reportAssertInt("assertNotEqualsShort", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_LONG(long expected, long actual){
    bool result = (expected != actual);
//    reportAssertInt("assertNotEqualsLong", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_FLOAT(float expected, float actual){
    bool result = (expected != actual);
//    reportAssertFloat("assertNotEqualsFloat", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_DOUBLE(double expected, double actual){
    bool result = (expected != actual);
//    reportAssertInt("assertNotEqualsDouble", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_CHAR(char expected, char actual){
    bool result = (expected != actual);
//    reportAssertChar("assertNotEqualsChar", result, expected, actual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_STR(char *expected, char *actual){
    bool result = (expected != actual);
//    reportAssertString("assertNotEqualsChar", result, expected, actual, msec, assertion);
    return result;
}


bool ASSERT_NOT_EQUALS_ARRAY_INT(int expected[], int actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
//    reportAssertArrayInt("AssertNotEqualsArrayInt", result, expected, actual, isAsserEqual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_ARRAY_SHORT(short expected[], short actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    //    reportAssertArrayInt("AssertNotEqualsArrayShort", result, (int *)expected, (int *)actual, isAsserEqual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_ARRAY_LONG(long expected[], long actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    //    reportAssertArrayInt("AssertNotEqualsArrayLong", result, (int *)expected, (int *)actual, isAsserEqual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_ARRAY_FLOAT(float expected[], float actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    //    reportAssertArrayFloat("AssertNotEqualsArrayFloat", result, expected, actual, isAsserEqual, msec, assertion);
    return result;
}

bool ASSERT_NOT_EQUALS_ARRAY_DOUBLE(double expected[], double actual[]){
    bool result = (memcmp(expected, actual, sizeof(&expected)) != 0);
    //    reportAssertArrayDouble("AssertNotEqualsArrayFloat", result, expected, actual, isAsserEqual, msec, assertion);
    return result;
}
//--------------------------------------------------------


//ASSERT BOOLEANS
bool ASSERT_TRUE(bool actual){
    bool result = actual;
//    reportAssertBool("assertTrue", actual, true, actual, msec, assertion);
    return result;
}

bool ASSERT_FALSE(bool actual){
    bool result = actual;
//    reportAssertBool("assertFalse", actual, false, actual, msec, assertion);
    return result;
}
//--------------------------------------------------------

//ASSERT NULL / NOT NULL
bool ASSERT_NOT_NULL(void *expr){
    bool result = (expr != NULL);
//    reportAssertNULL("assertNotNULL", result, "Not NULL", "Not NULL",0, assertion);
    return result;
}

bool ASSERT_NULL(void *expr){
    bool result = (expr == NULL);
//    reportAssertNULL("assertNULL", result, "NULL", "NULL", 0, assertion);
    return result;
}
//--------------------------------------------------------
