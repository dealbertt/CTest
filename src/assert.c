#include "../include/assert.h"

bool ASSERT_EQUAL(void *expected, void *actual, size_t size) {
    return memcmp(expected, actual, size) == 0;
}

bool ASSERT_NOT_EQUAL(void *expected, void *actual, size_t size) {
    return memcmp(expected, actual, size) != 0;
}
